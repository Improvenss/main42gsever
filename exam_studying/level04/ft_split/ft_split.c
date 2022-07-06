#include <stdlib.h>

char	**ft_split(char *str)
{
	char **words;
	int	i;
	int	i2;
	int	i3;

	words = (char **)malloc(sizeof(char *) * 100);
	i = 0;
	i2 = 0;
	while (str[i] != ' ' && str[i] != '\t && str[i] != '\n')
		i++;
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
int	main()
{
	char *amk = "boyle sistemin amk";
	char **words;
	int	i;

	i = 0;
	words = ft_split(amk);
	while (words[i] != 0)
	{
		ft_putstr(words[i]);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
