#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

int	main( int argc, char **argv )
{
	if (argc < 2)
	{
		std::cerr << "You must be enter client port. ./a.out <port>"\
			<< std::flush << std::endl;
		return (1);
	}
	int	clientFd;
	struct sockaddr_in destAddress;

	clientFd = socket(AF_INET, SOCK_STREAM, 0);
	if (clientFd < 0)
	{
		perror("Socket create error.");
		return (1);
	}
	std::cout << "Client socket created!" << std::flush << std::endl;
	bzero(&destAddress, sizeof(destAddress));
	if (connect(clientFd, (const sockaddr *)&destAddress, sizeof(destAddress)) < 0)
	{
		perror("Error: Connection error!");
		return (1);
	}
	std::cout << "Connected!" << std::flush << std::endl;
	return (0);
}