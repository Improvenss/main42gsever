/* CELEBT09

   The following attributes changes the terminal attributes.
   Aşağıdaki öznitelikler, uçbirim özniteliklerini değiştirir.

 */
#define _POSIX_SOURCE
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

int	main()
{
	struct termios term1, term2;

	if (tcgetattr(STDIN_FILENO, &term1) != 0)
		perror("tcgetattr() error");
	else
	{
		printf("the original end-of-file character is x'%02x'\n",
		term1.c_cc[VEOF]);
		term1.c_cc[VEOF] = 'z';
		if (tcsetattr(STDIN_FILENO, TCSANOW, &term1) != 0)
			perror("tcsetattr() error");
		if (tcgetattr(STDIN_FILENO, &term1) != 0)
			perror("tcgetattr() error");
		else
			printf("the new end-of-file character is x'%02x'\n",
		term1.c_cc[VEOF]);
	}
}