/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:11:16 by gsever            #+#    #+#             */
/*   Updated: 2021/12/12 19:40:28 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_ver_bas(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')//basemiz dugun ise 1 doner
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1]
			|| base[i] == ' ' || base[i] == '\n' || base[i] == '\t'
			|| base[i] == '\v' || base[i] == '\f' || base[i] == '\r')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	ft_mult_nbr(char d, char *base, int mult, int nbr)
{
	int	c;

	c = 0;
	while (base[c] != '\0')
	{
		if (d == base[c])
			return (nbr + (mult * c));
		c++;
	}
	return (nbr);
}

int	ft_isbase(char n, char *base)
{
	int	c;

	c = 0;
	if (n == '\n' || n == '\t' || n == '\v' || n == '\f' || n == '\r'
		|| n == ' ' || n == '+' || n == '-')
		return (1);
	while (base[c] != '\0')
	{
		if (base[c] == n)
			return (2);
		c++;
	}
	return (0);
}

int	ft_atoi_simpl(char *str, char *base, int size, int c)
{
	int	i;
	int	s;
	int	res;
	int	mult;

	i = c - 1;
	s = 1;
	res = 0;
	mult = 1;
	while (i >= 0)
	{
		if (str[i] == '-')
			s *= (-1);
		if (ft_isbase(str[i], base) == 2)
		{
			res = ft_mult_nbr(str[i], base, mult, res);
			mult *= size;
		}
		i--;
	}
	return (res * s);
}

int	ft_atoi_base(char *str, char *base)
{
	int	size;
	int	c;

	size = 0;
	c = 0;
	if (ft_ver_bas(base) == 0)//sayi sisteminde hata var mi baktik = 1
		return (0);
	while (base[size] != '\0')//sayi sistemini saydik = 10
		size++;
	while (str[c] == '\n' || str[c] == '\t' || str[c] == '\v'
		|| str[c] == '\f' || str[c] == '\r' || str[c] == ' ')//bosluklar fln + c
		c++;
	while (str[c] == '-' || str[c] == '+')//isaretler falan + c
		c++;
	while (str[c] >= '0' && str[c] <= '9')//rakamlar + c
		c++;
	return (ft_atoi_simpl(str, base, size, c));//simple fonksiyonuna attik.
}

int main(void)
{
	printf("%d\n", ft_atoi_base(" -+--122-45-- 2- 42-45", "0123456789"));
}

