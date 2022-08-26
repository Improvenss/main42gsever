
/**
 * Kelimenin verilen başlangıç indexinden isspace eşitliğine kadar uzunluğunu döndürüyor.
*/
int	ft_strlen_to_space(int i, const char *str)
{
	int	l;

	l = i;
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (i - l);
		i++;
	}
	return (i - l);
}

/**
 * Girilen komut satırının önünde yer alan boş karakterleri atlar.
 * İlk harfin konumunu döndürür.
 * 
 * isspace decimal set:
 * 	Horizontal tabulator:	'\t' -> 9
 * 	Line feed: 				'\n' -> 10
 * 	Vertical tabulator:		'\v' -> 11
 * 	Page feed:				'\f' -> 12
 * 	Carriage return:		'\r' -> 13
 * 	Space:					' ' -> 32
*/
int	ft_skip_front_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	return (i);
}

int	ft_word_count(const char *str)
{
	int	i;
	int	l;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	l = 0;
	if (i == 0)
		l++;
	while (str[i])
	{
		if (((str[i - 1] >= 9 && str[i - 1] <= 13) || str[i - 1] == 32) &&\
		(str[i] < 9 || str[i] > 13) && str[i] != 32)
			l++;
		i++;
	}
	return (l);
}

void	ft_set_line(const char *str, t_main *main)
{
	int	i;
	int	l;
	int	x;
	int y;

	i = -1;
	l = ft_word_count(str);
	main->line = (char **)malloc(sizeof(char **) * l);
	
	/*
	while (++i < l)
	{
		x = ft_skip_front_spaces(str);
		y = ft_strlen_to_space(x, str);
		main->line[i] = (char *)malloc(sizeof(char *) * y);
		printf("%s\n", main->line[i]);
	}*/

	/*
	i = ft_skip_front_spaces(str);
	l = ft_strlen_to_space(i, str);
	main->line[0] = (char *)malloc(sizeof(char *) * (l + 1));
	printf("i: %d, l: %d\n", i, l);

	int k = 0;
	while (str[i] && i <= l)
	{
		main->line[0][k] = str[i];
		i++;
		k++;
	}
	main->line[0][k] = '\0';
	printf("%s\n", main->line[0]);
	*/
}