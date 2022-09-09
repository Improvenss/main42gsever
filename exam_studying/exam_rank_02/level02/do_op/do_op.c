#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	n1;
	int	n2;

	if (ac == 4)
	{
		n1 = atoi(av[1]);
		n2 = atoi(av[3]);
		if (av[2][0] == '+')
		{
			printf("%d", n1 + n2);
		}
		else if (av[2][0] == '-')
		{
			printf("%d", n1 - n2);
		}
		else if (av[2][0] == '*')
		{
			printf("%d", n1 * n2);
		}
		else if (av[2][0] == '/')
		{
			printf("%d", n1 / n2);
		}
		else if (av[2][0] == '%')
		{
			printf("%d", n1 % n2);
		}
	}
	printf("\n");
	return (0);
}
