/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ultoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 19:23:32 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 13:11:41 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	ft_unsigned_amount(unsigned long long nb, long base, t_map *map)
{
	long	amount;

	amount = 0;
	map->nb = nb;
	if (nb == 0)
		amount++;
	if (base == 10)
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

char	*ft_ultoa(unsigned long long nb, long bas, t_map *map, char c)
{
	char	*str;
	char	*tab;
	long	amount;

	amount = ft_unsigned_amount(nb, bas, map);
	if (c == 'X' || c == 'F' || c == 'A')
		tab = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		tab = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (bas < 2 || bas > 36)
		return (0);
	str = (char *)printf_calloc(amount + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (amount > 0)
	{
		str[amount - 1] = tab[nb % bas];
		amount--;
		nb = nb / bas;
	}
	return (str);
}
