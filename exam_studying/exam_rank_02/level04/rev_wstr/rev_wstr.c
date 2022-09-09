#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	**ft_split(char *str)
{
	char	**words;
	int		i;
	int 	i2;
	int		i3;

	i = 0;
	i2 = 0;
	words = (char**)malloc(sizeof(char*) * 100);
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			i3 = 0;
			words[i2] = (char *)malloc(sizeof(char) * 100);
			while (str[i] > 32)
			{
				words[i2][i3] = str[i];
				i3++;
				i++;
			}
			words[i2][i3] = '\0';
			i2++;
		}
		else
			i++;
	}
	words[i2] = 0;
	return (words);
}

int	main(int ac, char **av)
{
	char **words;
	int	i;

	if (ac == 2)
	{
		i = 0;
		words = ft_split(av[1]);
		while (words[i] != 0)
			i++;
		i--;
		while (i >= 0)
		{
			ft_putstr(words[i]);
			if (i > 0)
				write(1, " ", 1);
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
