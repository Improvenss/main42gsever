#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	polarity;
	int	number;

	i = 0;
	polarity = 1;
	number = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			polarity *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i++] - 48);
	}
	return (number * polarity);
}
/*
int	main()
{
	char	*str;
	int		number;

	str = "2001";
	number = ft_atoi(str);
	printf("%d\n", number);
}
*/
