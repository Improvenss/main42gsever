#include <iostream>
#include <stdio.h>
#include <sys/socket.h> // socket()
#include <netinet/in.h> // bind()
#include <unistd.h> // close()

/**
 * @brief Creating socket for server.
 * 
 * Socket: Create a new communication
 * Bind: Attach a local address to a socket
 * Listen: Announce willingness to accept connections
 * Accept: Block caller until a connection request arrives
 * Connect: Actively attempt to establish a connection
 * Send: Send some data over a connection
 * Receive: Receive some data over a connection
 * Close: Release the connection
 * 
	SERVER		CLIENT
	socket		socket
	bind
	listen	<-	connect
	accept
	send/recv <-> send/recv
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main( int argc, char **argv )
{
	if (argc < 2)
	{
		std::cout << "You must be use ./a.out <port>"\
			<< std::flush << std::endl;
		return (1);
	}
	int	socketFd;
	struct sockaddr_in socketAddress;

	socketFd = socket(AF_INET, SOCK_STREAM, 0);
	if (socketFd < 0)
	{
		perror("Socket error.");
		return (1);
	}
	std::cout << "socket created!" << std::flush << std::endl;
	bzero(&socketAddress, sizeof(socketAddress));
	socketAddress.sin_addr.s_addr = INADDR_ANY;
	socketAddress.sin_family = AF_INET;
	socketAddress.sin_port = htons(atoi(argv[1]));
	if (bind(socketFd, (const sockaddr *)&socketAddress, sizeof(socketAddress)) < 0)
	{
		close(socketFd);
		perror("Error: Bind: Attaching address!");
		return (1);
	}
	if (listen(socketFd, 10) < 0)
	{
		close(socketFd);
		perror("Error: Listen: Queue!");
		return (1);
	}
	
	return (0);
}