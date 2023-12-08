#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
// #include <sys/select.h>
#include <netinet/in.h>

#include <stdio.h>

#define BUFFER_SIZE 3

typedef struct s_client
{
	int	id;
	int	sock_id;
}	t_client;

void	send_all(char *str, char *message, int newSocket, int maxfd, t_client *clients)
{
	int		i;
	char	*buff = NULL; // sprintf() ile icerisini dolduracagiz.

	buff = realloc(buff, (sizeof(str) + sizeof(message)));
	sprintf(buff, str, clients[newSocket].id, message); // str'yi client id'siyle birlikte buff'a yaziyoruz.
	printf("buff: %s", buff);
	i = 3;
	while (++i <= maxfd)
		if (i != newSocket && clients[i].sock_id != -1)
			send(i, buff, strlen(buff), 0);
	free(message);
	free(buff);
}

void	ft_putstr_fd(int fd, char *str, int exit_num)
{
	write(fd, str, strlen(str));
	write(fd, "\n", 1);
	if (exit_num != 0)
		exit(exit_num); // #include <stdlib.h>
}

void	check_status(int maxfd, fd_set *mainfds)
{
	printf("Soket Durumu:\n");
	for (int i = 0; i <= maxfd; i++) {
		if (FD_ISSET(i, mainfds)) // Socket'lerin set edilip edilmedigini tespit eder.
			printf("Soket %d: Hazır\n", i);
		else
			printf("Soket %d: Hazır Değil\n", i);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr_fd(2, "Wrong number of arguments", 1);

	int					sockfd; // Server'imizin fd'sini temsil eder.
	int					maxfd;
	int					next_id; // Gelen her socket'in id'sine tekamul eder. 0, 1, 2, 3... gibi.
	struct sockaddr_in	servaddr; // #include <netinet/in.h>
	fd_set				mainfds; // Socketlerimizin hepsinin tutuldugu fd.
	fd_set				rfds; // select() functionu tarafindan set edilmis fd'ler tutulur.
	t_client			clients[1024];
	ssize_t				readed_byte;
	ssize_t				total_byte;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		ft_putstr_fd(2, "socket: Fatal Error", 1);
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	// servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_addr.s_addr = htonl(127 * 256 * 256 * 256 + 1); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));

	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) != 0))
		ft_putstr_fd(2, "bind: Fatal Error", 1);
	if (listen(sockfd, 4000) != 0)
		ft_putstr_fd(2, "listen: Fatal Error", 1);

	maxfd = sockfd;
	FD_ZERO(&mainfds); // mainfds'i yani 
	FD_SET(sockfd, &mainfds);

	next_id = 0;
	while (1)
	{
		rfds = mainfds;
		if (select(maxfd + 1, &rfds, NULL, NULL, NULL) < 0)
			ft_putstr_fd(2, "Fatal Error", 1);
		if (FD_ISSET(sockfd, &rfds))
		{ // yeni bir baglanti oldugunda kayit etmek icin kullanilir.
			int	newSocket = accept(sockfd, NULL, NULL);
			if (newSocket < 0)
				ft_putstr_fd(2, "Fatal Error", 1);
			clients[newSocket].id = next_id++;
			clients[newSocket].sock_id = newSocket;
			FD_SET(newSocket, &mainfds);
			send_all("server: client %d just arrived\n", NULL, newSocket, maxfd, clients);
			if (newSocket > maxfd)
				maxfd = newSocket;
			printf("Socket %d: Basarili bir sekilde baglandi.\n", newSocket);
			check_status(maxfd, &mainfds);
		}
		for (int socket = 4; socket <= maxfd; socket++)
		{
			if (!FD_ISSET(socket, &rfds))
				continue;
			char*	dynamic_buffer = NULL;
			// Read Messages
			total_byte = 0;
			while (1)
			{ // Buradaki dinamik olarak buffer kadar yer aciyoruz ve okuma islemi gerceklestiriyoruz.
				dynamic_buffer = realloc(dynamic_buffer, BUFFER_SIZE);
				if (dynamic_buffer == NULL)
				{
					free(dynamic_buffer);
					ft_putstr_fd(2, "Fatal Error", 1);
				}
				readed_byte = recv(socket, dynamic_buffer + total_byte, BUFFER_SIZE, 0);
				if (readed_byte < 0)
					break;
				total_byte += readed_byte;
				if (readed_byte == 0 || dynamic_buffer[total_byte - 1] == '\n')
					break;
			}
			dynamic_buffer[total_byte] = '\0';
			if (total_byte <= 0)
			{
				send_all("server: client %d just left\n", NULL, socket, maxfd, clients);
				FD_CLR(socket, &mainfds);
				clients[socket].sock_id = -1;
				free(dynamic_buffer);
				close(socket);
				break;
			}
			printf("total_byte: %lu\n", total_byte);
			send_all("client %d: %s", dynamic_buffer, socket, maxfd, clients);
		}
	}

	return (0);
}