#include "Philo.h"

int	ft_atoi(char *string)
{
	int	val;
	int	i;
	int	l;

	i = 0;
	val = 0;
	while (string[i])
	{
		val = (val * 10) + (string[i] - 48);
		i++;
	}
	return (val);
}