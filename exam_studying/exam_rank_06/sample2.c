#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_CLIENTS 128    // Maximum number of client connections allowed
#define BUFFER_SIZE 200000 // Size of the buffer used for message exchange

int main(int argc, char **argv) 
{
	if (argc != 2)  // Check if the number of command line arguments is incorrect 
	{
		fprintf(stderr, "Usage: %s <port>\n", argv[0]);		// Print an error message to the standard error stream
		exit(1);											// Terminate the program with a non-zero status code
	}

	int clientSockets[MAX_CLIENTS];           // Array to store client socket descriptors
	int next_id = 0;                          // Identifier for the next client connection

	// File descriptor sets
	fd_set activeSockets, readySockets;        // File descriptor sets for tracking socket activity
	char buffer[BUFFER_SIZE];                  // Buffer for storing received messages

	// Create the server socket
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);  // Create a socket with IPv4 addressing and TCP protocol
	if (serverSocket < 0)  // Check if socket creation failed
	{                    
		perror("Error creating server socket"); // Print an error message with a description of the error
		exit(1);                              // Terminate the program with a non-zero status code
	}

	// Set up the server address
	struct sockaddr_in serverAddress = {0};    // Structure to hold the server address
	serverAddress.sin_family = AF_INET;        // Set address family to IPv4
	serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);  // Set the IP address to localhost
	serverAddress.sin_port = htons(atoi(argv[1]));  // Set the port number from the command line argument

	// Bind the server socket to the specified address
	if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) 
	{
		perror("Error binding server socket");  // Print an error message if binding fails
		exit(1);                              // Terminate the program with a non-zero status code
	}

	// Listen for incoming connections
	if (listen(serverSocket, MAX_CLIENTS) < 0) 
	{
		perror("Error listening on server socket");  // Print an error message if listening fails
		exit(1);                              // Terminate the program with a non-zero status code
	}

	// Initialise the active sockets set
	FD_ZERO(&activeSockets);                   // Clear the set of active sockets
	FD_SET(serverSocket, &activeSockets);      // Add the server socket to the set
	int maxSocket = serverSocket;              // Variable to track the maximum socket descriptor

	while (1) 
	{
		// Wait for activity on the sockets
		readySockets = activeSockets;           // Copy the active sockets set for use with select()
		if (select(maxSocket + 1, &readySockets, NULL, NULL, NULL) < 0) 
		{
			perror("Error in select");         // Print an error message if select() fails
			exit(1);                          // Terminate the program with a non-zero status code
		}

		// Check each socket for activity
		for (int socketId = 0; socketId <= maxSocket; socketId++) 
		{
			if (FD_ISSET(socketId, &readySockets)) 
			{
				// New client connection
				if (socketId == serverSocket)  // Check if the activity is on the server socket
				{
					int clientSocket = accept(serverSocket, NULL, NULL);  // Accept a new client connection
					if (clientSocket < 0) 
					{
						perror("Error accepting client connection");  // Print an error message if accepting fails
						exit(1);                          // Terminate the program with a non-zero status code
					}

					// Add the new client socket to the active set
					FD_SET(clientSocket, &activeSockets);     // Add the client socket to the set of active sockets
					maxSocket = (clientSocket > maxSocket) ? clientSocket : maxSocket;  // Update the maximum socket descriptor

					// Send a welcome message to the client
					sprintf(buffer, "server: client %d just arrived\n", next_id);  // Prepare the welcome message
					send(clientSocket, buffer, strlen(buffer), 0);  // Send the welcome message to the client

					// Store the client socket for future reference
					clientSockets[next_id++] = clientSocket;  // Add the client socket to the array
				} 
				else 
				{
					// Data received from a client
					int bytesRead = recv(socketId, buffer, sizeof(buffer) - 1, 0);  // Receive data from the client

					if (bytesRead <= 0) 
					{
						// Client disconnected
						sprintf(buffer, "server: client %d just left\n", socketId);  // Prepare the disconnection message

						// Notify remaining clients about the disconnected client
						for (int i = 0; i < next_id; i++) 
						{
							if (clientSockets[i] != socketId) 
							{
								send(clientSockets[i], buffer, strlen(buffer), 0); // Send the disconnection message to other clients
							}
						}

						// Close the socket and remove it from the active set
						close(socketId);                          // Close the client socket
						FD_CLR(socketId, &activeSockets);         // Remove the client socket from the set of active sockets
					} 
					else 
					{
						// Broadcast the received message to all other clients
						buffer[bytesRead] = '\0';                  // Null-terminate the received message
						sprintf(buffer, "client %d: %s\n", socketId, buffer);  // Add client identifier to the message

						for (int i = 0; i < next_id; i++) 
						{
							if (clientSockets[i] != socketId) 
							{
								send(clientSockets[i], buffer, strlen(buffer), 0);  // Send the message to other clients
							}
						}
					}
				}
			}
		}
	}
	return 0;
}