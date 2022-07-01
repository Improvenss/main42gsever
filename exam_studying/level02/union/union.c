#include <unistd.h>

int	check_first(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i] != '\0')
		{
			if (check_first(av[1], av[1][i], i))
			{
				write(1, &av[1][i], 1);
			}
			i++;
		}
		i = 0;
		while (av[2][i] != '\0')
		{
			if (check_second(av[2], av[2][i], i))
			{
				write(1, &av[2][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
