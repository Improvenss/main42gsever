int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*
#include <string.h>
#include <stdio.h>
*/
/*
	Bu sacma fonsiyonda bastan basliyor ayniysa geciyor
farklilik gordugu gibi farkli olan characterlerin
farkini return ediyor. :....(
*/
/*
int	main()
{
	char	s1[] = "123456";
	char	s2[] = "123546";
	char	b1[] = "123456";
	char	b2[] = "123546";

	printf("ft_:%d\n", ft_strcmp(s1, s2));
	printf("org:%d\n", strcmp(b1, b2));
}
*/
