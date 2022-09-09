#include <stdio.h>
#include <stdlib.h>

void	pgcd(int s1, int s2)
{
	int	i;
	int annen;

	i = 1;
	annen = 0;
	while (i < s1 && i < s2)
	{
		if (s1 % i == 0 && s2 % i == 0)
			annen = i;
		i++;
	}
	printf("%d", annen);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		pgcd(atoi(av[1]), atoi(av[2]));
	printf("\n");
	return (0);
}
