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
	return ;
}

char	**ft_split(char *str)
{
	char	**words;
	int	i;
	int	i2;
	int	i3;

	i = 0;
	i2 = 0;
	words = (char**)malloc(sizeof(char) * 100);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			i3 = 0;
			words[i2] = (char*)malloc(sizeof(char) * 100);
			while (str[i] != ' ' && str[i] != '\t' && str[i])
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

	if (ac > 1)
	{
		i = 1;
		words = ft_split(av[1]);
		while (words[i])
		{
			ft_putstr(words[i]);
			write(1, " ", 1);
			i++;
		}
		ft_putstr(words[0]);
	}
	write(1, "\n", 1);
	return (0);
}
