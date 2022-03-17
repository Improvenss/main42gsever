/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floats.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: peerdb <peerdb@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 17:03:06 by peerdb        #+#    #+#                 */
/*   Updated: 2021/03/29 12:15:10 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

long long	ft_round(double f, t_map *map, int base)
{
	long long	result;

	result = (f - (long long)f) * ft_precpower(map, base) * base;
	if (f >= 0)
		result = (result + 5) / base;
	else
		result = (result - 5) / base;
	while (map->typ == 'g' && result % base == 0)
		result = result / base;
	return (result);
}

long long	ft_divpower(long long nb)
{
	long long	result;

	result = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		result = result * 10;
	}
	return (result);
}

void	ft_floathandler(double f, long long base, t_map *map)
{
	char		*string;
	char		*decstring;
	long long	dec;

	dec = ft_round(f, map, base);
	string = ft_itoa_base(ft_floatrect(f, map), base, map, map->typ);
	decstring = ft_itoa_base(dec, base, map, map->typ);
	string = ft_floatjoin(string, decstring, map);
	ft_floatflagger(string, 1, map);
	free(string);
	return ;
}

void	ft_science(double f, t_map *map)
{
	long long	div;

	div = ft_divpower((long long)f);
	map->sci = (long long)f;
	f = f / div;
	ft_floathandler(f, 10, map);
	return ;
}

int	ft_floatfinder(const char *s, t_map *map, va_list *args)
{
	double		f;

	if (s[map->pos] == 'f' || s[map->pos] == 'F' || s[map->pos] == 'g'
		|| s[map->pos] == 'G' || s[map->pos] == 'e' || s[map->pos] == 'E')
	{
		f = va_arg(*args, double);
		if (ft_floatingpointexception(f, map) == 1)
			return (1);
		if (s[map->pos] == 'f' || s[map->pos] == 'F')
		{
			ft_floathandler(f, 10, map);
			map->pos++;
			return (1);
		}
		if (s[map->pos] == 'e' || s[map->pos] == 'E')
		{
			ft_science(f, map);
			map->pos++;
			return (1);
		}
		return (ft_g_finder(s, map, f));
	}
	return (0);
}
