#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 400000
char buffer[BUFFER_SIZE];
int maxfd, next_id;

typedef struct s_client {
	int	id;
	int	sockId;
} t_client;

t_client    clients[1024];

void fatal_error()
{
	write(2, "Fatal Error\n", 12);
	exit(1);
}

void send_all(char *str, int s)
{
	for (int i = 4; i <= maxfd; i++)
	{
		if (i != s && clients[i].sockId != -1)
			send(i, str, strlen(str), 0);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	next_id = 0;
	struct sockaddr_in servaddr;

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		fatal_error();
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));

	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
		fatal_error();
	}

	if (listen(sockfd, 4000) != 0) {
		fatal_error();
	}
	maxfd = sockfd;
	fd_set rfds, masterfds;
	FD_ZERO(&masterfds);
	FD_SET(sockfd, &masterfds);

	while (1)
	{
		rfds = masterfds;
		if (select(maxfd + 1, &rfds, NULL, NULL, NULL) < 0)
			fatal_error();
		if (FD_ISSET(sockfd, &rfds))
		{
			//new connection
			int newSocket = accept(sockfd, NULL, NULL);
			if (newSocket < 0)
				fatal_error();
			clients[newSocket].sockId = newSocket;
			clients[newSocket].id = next_id++;
			FD_SET(newSocket, &masterfds);
			char bufArrived[1000];
			sprintf(bufArrived, "server: client %d just arrived\n", clients[newSocket].id);
			send_all(bufArrived, newSocket);
			if (newSocket > maxfd)
				maxfd = newSocket;
			bzero(bufArrived, sizeof(bufArrived));
		}
		for (int socket = 4; socket <= maxfd; socket++)
		{
			if (FD_ISSET(socket, &rfds))
			{
				ssize_t totalByte = 0;
				int line = 0;
				while (1)
				{
					char saveBuf[BUFFER_SIZE];
					ssize_t byte = recv(socket, saveBuf, sizeof(saveBuf), 0);
					totalByte += byte;
					for (int i = 0; i < byte; i++)
					{
						buffer[line] = saveBuf[i];
						line++;
					}
					if (byte == 0 || saveBuf[byte - 1] == '\n')
						break;
				}
				buffer[totalByte] = '\0';
				if (totalByte <= 0)
				{
					//close
					char bufLeft[1000];
					sprintf(bufLeft, "server: client %d just left\n", clients[socket].id);
					send_all(bufLeft, socket);
					FD_CLR(socket, &masterfds);
					clients[socket].sockId = -1;
					close(socket);
					bzero(bufLeft, sizeof(bufLeft));
				}
				else//send msgs
				{
					int bufferIndex = 0;
					for (int i = 0; i < totalByte; i++)
					{
						if (buffer[i] == '\n' || buffer[i] == '\0')
						{
							char bufLine[BUFFER_SIZE];
							int line = 0;
							while (bufferIndex <= i)
							{
								bufLine[line] = buffer[bufferIndex];
								line++;
								bufferIndex++;
							}
							bufferIndex = i + 1;
							char bufSend[BUFFER_SIZE];
							sprintf(bufSend, "client %d: %s", clients[socket].id, bufLine);
							send_all(bufSend, socket);
							bzero(bufSend, sizeof(bufSend));
							bzero(bufLine, sizeof(bufSend));
						}
					}
					bzero(buffer, sizeof(buffer));
				}
			}
		}
	}
	return 1;
}