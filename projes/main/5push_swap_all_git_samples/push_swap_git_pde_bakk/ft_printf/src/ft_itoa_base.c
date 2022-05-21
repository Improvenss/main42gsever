/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 18:29:13 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 12:16:17 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_amount(long long nb, long long base, t_map *map)
{
	long long	amount;

	amount = 0;
	map->nb = nb;
	if (nb == 0)
		amount++;
	if (nb < 0 && base == 10)
	{
		map->plus = 0;
		nb = -nb;
	}
	while (nb)
	{
		nb = nb / base;
		amount++;
		if (map->apos > -1)
			map->apos++;
	}
	map->apos = (map->apos - 1) / 3;
	return (amount);
}

int	ft_absolutely(long long nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base(long long nb, long long base, t_map *map, char c)
{
	char		*str;
	char		*tab;
	long long	amount;

	amount = ft_amount(nb, base, map);
	if (c == 'X' || c == 'F' || c == 'A')
		tab = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		tab = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (base < 2 || base > 36)
		return (0);
	str = (char *)printf_calloc(amount + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (amount > 0)
	{
		str[amount - 1] = tab[ft_absolutely(nb % base)];
		amount--;
		nb = nb / base;
	}
	return (str);
}

int	ft_precpower(t_map *map, int base)
{
	int	result;
	int	power;

	result = 1;
	power = 0;
	if (map->prec == -1)
		map->prec = map->prec + 7;
	if (map->prec == 0)
		return (0);
	if (map->prec > 0)
		power = map->prec;
	while (power > 0)
	{
		result = result * base;
		power--;
	}
	return (result);
}

long long int	ft_floatrect(long double f, t_map *map)
{
	if (map->prec == 0)
	{
		f = f + 0.5;
	}
	return ((long long)f);
}
