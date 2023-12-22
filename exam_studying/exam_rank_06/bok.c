#include <unistd.h> // write
#include <stdlib.h> // exit, atoi
#include <string.h> // strlen
#include <stdio.h> // sprintf
#include <netinet/in.h> // sockaddr_in
#include <sys/socket.h> // fd_set, socket, bind, accept, recv

#define BUFFER_SIZE 400000

typedef struct c_client
{
	int	id;
	int	sock_id;
}	t_client;

void	ft_putstr_fd(int fd, char *str, int exit_num)
{
	write(fd, str, strlen(str));
	if (exit_num != 0)
		exit(exit_num);
}

void	send_all(char *str, char *msg, int newSocket, int maxfd, t_client *clients)
{
	// char	buff[BUFFER_SIZE];
	char	*buff;

	buff = NULL;
	buff = realloc(buff, (sizeof(str) + sizeof(msg) + 1000));
	sprintf(buff, str, clients[newSocket].id, msg);
	for (int i = 4; i <= maxfd; i++)
		if (i != newSocket && clients[i].sock_id != -1)
			send(i, buff, strlen(buff), 0);
	// bzero(buff, sizeof(buff));
	free(buff);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr_fd(2, "Wrong number of arguments\n", 1);

	int					sockfd;
	int					maxfd;
	int					next_id;
	int					newSocket;
	int					line;
	struct sockaddr_in	servaddr;
	fd_set				mainfds;
	fd_set				rfds;
	ssize_t				total_b;
	ssize_t				readed_b;
	t_client			clients[4000];

	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)
		ft_putstr_fd(2, "Fatal error\n", 1);
	bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(127 * 256 * 256 * 256 + 1); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 
  
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		ft_putstr_fd(2, "Fatal error\n", 1);
	if (listen(sockfd, 4000) != 0)
		ft_putstr_fd(2, "Fatal error\n", 1);
	maxfd = sockfd;
	FD_ZERO(&mainfds);
	FD_SET(sockfd, &mainfds);
	next_id = 0;
	while (1)
	{
		rfds = mainfds;
		if (select(maxfd + 1, &rfds, NULL, NULL, NULL) < 0)
			ft_putstr_fd(2, "Fatal error\n", 1);
		if (FD_ISSET(sockfd, &rfds))
		{ // new connection
			newSocket = accept(sockfd, NULL, NULL);
			if (newSocket < 0)
				ft_putstr_fd(2, "Fatal error\n", 1);
			clients[newSocket].id = next_id++;
			clients[newSocket].sock_id = newSocket;
			FD_SET(newSocket, &mainfds);
			send_all("server: client %d just arrived\n", NULL, newSocket, maxfd, clients);
			if (newSocket > maxfd)
				maxfd = newSocket;
		}
		for (int socket = 4; socket <= maxfd; socket++)
		{
			if (!FD_ISSET(socket, &rfds))
				continue;
			char	buff_total[BUFFER_SIZE];
			total_b = 0;
			line = 0;
			while (1)
			{ // read message
				char	buff_readed[BUFFER_SIZE];
				readed_b = recv(socket, buff_readed, sizeof(buff_readed), 0);
				total_b += readed_b;
				for (int i = 0; i < readed_b; i++)
					buff_total[line++] = buff_readed[i];
				if (readed_b == 0 || buff_readed[readed_b - 1] == '\n')
					break;
			}
			buff_total[total_b] = '\0';
			// printf("buff_total: [%s]\n", buff_total);
			if (total_b <= 0)
			{ // client disconnect
				send_all("server: client %d just left\n", NULL, socket, maxfd, clients);
				clients[socket].sock_id = -1;
				FD_CLR(socket, &mainfds);
				close(socket);
				bzero(buff_total, sizeof(buff_total));
			}
			else
			{ // send message
				int	buff_index = 0;
				for (int i = 0; i < total_b; i++)
				{
					if (buff_total[i] == '\n' || buff_total[i] == '\0')
					{
						char	buff_line[BUFFER_SIZE];
						line = 0;
						while (buff_index <= i)
							buff_line[line++] = buff_total[buff_index++];
						buff_index = i + 1;
						send_all("client %d: %s", buff_line, socket, maxfd, clients);
						bzero(buff_line, sizeof(buff_line));
					}
				}
			}
			bzero(buff_total, sizeof(buff_total));
		}
	}
	return (1);
}






// 1
// 22
// 333
// 4444
// 55555


// 11
// 222
// 3333


