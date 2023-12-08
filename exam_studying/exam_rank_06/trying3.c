#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

void	ft_putstr_fd(int fd, char *str, int exit_status)
{
	write(fd, str, strlen(str));
	write(fd, "\n", 1);
	if (exit_status != 0)
		exit(exit_status);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr_fd(2, "Wrong number of arguments", 1);

	int sockfd;
	struct sockaddr_in servaddr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) // -1 hata seysi
		ft_putstr_fd(2, "Fatal error", 1);
	bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));
	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
		ft_putstr_fd(2, "Fatal error", 1);
	if (listen(sockfd, 4000) != 0)
		ft_putstr_fd(2, "Fatal error", 1);
	

	return (0);
}