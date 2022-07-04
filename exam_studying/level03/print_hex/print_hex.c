#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void print_hex(int nb)
{
	if (nb >= 16)
	{
		print_hex(nb / 16);
		print_hex(nb % 16);
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	else if (nb < 16)
		ft_putchar(nb + 87);
}

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	result;

	i = 0;
	n = 1;
	result = 0;
	if (str[i] == '-')
	{
		n *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * n);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}
