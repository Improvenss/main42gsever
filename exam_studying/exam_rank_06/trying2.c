#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>

#define BUFFER_SIZE 3

#include <stdio.h>

typedef struct s_client
{
	int		id;
	int		sock_id;
} t_client;

void	send_all(char *str, char *message, int newSocket, int maxfd, t_client *clients)
{
	int		i;
	char	*buff = NULL;

	buff = realloc(buff, (sizeof(str) + sizeof(message)));
	sprintf(buff, str, clients[newSocket].id, message);
	printf("buff: %s\n", buff);
	i = 3;
	while(++i <= maxfd)
		if (i != newSocket && clients[i].sock_id != -1)
			send(i, buff, strlen(buff), 0);
	free(message);
	free(buff);
}

void	ft_putstr_fd(int fd, char *str, int exit_status)
{
	write(fd, str, strlen(str));
	write(fd, "\n", 1);
	if (exit_status != 0)
		exit(exit_status); // #include <stdlib.h>
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr_fd(2, "Wrong number of arguments", 1);
	
	int					sockfd;
	int					maxfd;
	int					next_id;
	struct sockaddr_in	servaddr;
	fd_set				mainfds;
	fd_set				rfds;
	t_client			clients[1024];
	ssize_t				total_byte;
	ssize_t				readed_byte;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		ft_putstr_fd(2, "socket: Fatal error", 1);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(127 * 256 * 256 * 256 + 1);
	servaddr.sin_port = htons(atoi(argv[1]));

	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof (servaddr)) != 0)
		ft_putstr_fd(2, "bind: Fatal error", 1);
	if (listen(sockfd, 4000) != 0)
		ft_putstr_fd(2, "listen: Fatal error", 1);
	maxfd = sockfd;
	FD_ZERO(&mainfds);
	FD_SET(sockfd, &mainfds);

	next_id = 0;
	while (1)
	{
		rfds = mainfds;
		if (select(maxfd + 1, &rfds, NULL, NULL, NULL) < 0)
			ft_putstr_fd(2, "select: Fatal error", 1);
		if (FD_ISSET(sockfd, &rfds))
		{ // new connection
			int	newSocket = accept(sockfd, NULL, NULL);
			if (newSocket < 0)
				ft_putstr_fd(2, "Fatal error", 1);
			clients[newSocket].sock_id = newSocket;
			clients[newSocket].id = next_id++;
			FD_SET(newSocket, &mainfds); // Socket'i mainfds'lere ekle yeni uye kaydi.
			send_all("server: client %d just arrived\n", NULL, newSocket, maxfd, clients);
			if (newSocket > maxfd)
				maxfd = newSocket;
			printf("Socket %d basarili bir sekilde baglandi.\n", newSocket);
		}
		for (int socket = 4; socket <= maxfd; socket++)
		{
			if (!FD_ISSET(socket, &rfds))
				continue;
			char	*dynamic_buffer = NULL;
			total_byte = 0;
			while (1)
			{
				dynamic_buffer = realloc(dynamic_buffer, BUFFER_SIZE);
				if (dynamic_buffer == NULL)
				{
					free(dynamic_buffer);
					ft_putstr_fd(2, "realloc: Fatal error", 1);
				}
				readed_byte = recv(socket, dynamic_buffer + total_byte, BUFFER_SIZE, 0);
				if (readed_byte < 0)
					ft_putstr_fd(2, "recv: Fatal error", 1);
				total_byte += readed_byte;
				if (readed_byte == 0 || dynamic_buffer[total_byte - 1] == '\n')
					break;
			}
			dynamic_buffer[total_byte] = '\0';
			if (total_byte <= 0)
			{ // connection lost
				send_all("server: client %d just left\n", NULL, socket, maxfd, clients);
				FD_CLR(socket, &mainfds);
				clients[socket].sock_id = -1;
				free(dynamic_buffer);
				close(socket);
				break;
			}
			printf("total_byte: %zd\n", total_byte);
			send_all("client %d: %s", dynamic_buffer, socket, maxfd, clients);
		}
	}
	return (0);
}
