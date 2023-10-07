#include <unistd.h>
#include <sys/socket.h>
#include <vector>
#include <poll.h>
#include <netinet/in.h>
// #include <stdio.h>

int main(){

	std::vector<pollfd> pollFds;
	unsigned short port = 8080;
	int serverFd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in serverSocket;

	memset((char*)&serverSocket, 0, sizeof(serverSocket));
	serverSocket.sin_family = AF_INET;
	uint8_t ipArray[4] = {127, 0, 0, 1};
	serverSocket.sin_addr.s_addr = *( uint32_t*) ipArray; //htonl(); // INADDR_ANY // INADDR_LOOPBACK
	serverSocket.sin_port = (port >> 8) | (port << 8); //htons();

	if (bind(serverFd, (const struct sockaddr *)&serverSocket, sizeof(serverSocket) ) < 0)
	{
		return (0);
	}

	if (listen(serverFd, 10) < 0)
	{
		return (0);
	}

	pollfd pollServer;
	pollServer.fd = serverFd;
	pollServer.events = POLLIN;
	pollServer.revents = 0;
	pollFds.push_back(pollServer);

	while (1)
	{
		if (poll(pollFds.begin().base(), pollFds.size(), -1) < 0)
		{
			return (0);
		}

		for (std::vector<pollfd>::iterator it = pollFds.begin(); it != pollFds.end(); ++it)
		{
			if (it->revents & POLLHUP)
			{
				pollFds.erase(it);
				break;
			}

			if (it->revents & POLLIN)
			{
				if (it->fd == serverFd)
				{
					struct sockaddr_in clientAddr = { 0 };
					socklen_t clientAddrSize = sizeof(clientAddr);

					int clientFd = accept(serverFd, (struct sockaddr *)&clientAddr, &clientAddrSize );
					pollfd pollClient;
					pollClient.fd = clientFd;
					pollClient.events = POLLIN;
					pollClient.revents = 0;
				}
				else
				{
					char buffer[99999];
					ssize_t byteRead = recv(it->fd, &buffer, sizeof(buffer) - 1, 0);
					if (byteRead > 0)
					{
						//send->cmd
					}
					else
					{
						pollFds.erase(it);
						break;
					}
				}
			}
		}
	}

	return (0);
}