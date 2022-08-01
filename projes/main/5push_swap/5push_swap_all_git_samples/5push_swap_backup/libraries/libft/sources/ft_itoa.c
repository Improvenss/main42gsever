/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:34:51 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:14 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//int degeri string donduruyor 
static size_t	digit_count(int n)
{
	int	count;

	if (n == ((1 << ((32) - 1))))
		return (11);
	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	put_number(int n, char *str, int *i)
{
	if (n > 9)
	{
		put_number(n / 10, str, i);
		put_number(n % 10, str, i);
	}
	else
		str[(*i)++] = n + '0';
}

//https://www.geeksforgeeks.org/computing-int_max-int_min-bitwise-operations/
char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nbr;

	nbr = n;
	str = malloc(sizeof(char) * (digit_count(nbr) + 1));
	if (!str)
		return (NULL);
	if (n == ((1 << ((32) - 1))))
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	i = 0;
	if (nbr < 0)
	{
		str[i++] = '-';
		nbr *= -1;
	}
	put_number(nbr, str, &i);
	str[i] = '\0';
	return (str);
}
/*
int	main()
{
	printf("Int min: %s\n", ft_itoa(-2147483648));
	printf("Int max: %s\n", ft_itoa(2147483647));
	printf("Zero: %s\n", ft_itoa(0));
	printf("Positive: %s\n", ft_itoa(1));
	printf("Negative : %s\n", ft_itoa(-1));
}
*/