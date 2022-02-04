/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeser <aeser@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:34:31 by aeser             #+#    #+#             */
/*   Updated: 2022/01/30 17:00:11 by aeser            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
