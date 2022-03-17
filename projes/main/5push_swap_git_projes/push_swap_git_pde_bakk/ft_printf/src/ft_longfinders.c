/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_longfinders.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 14:36:31 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 12:16:46 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_longdoublefinder(const char *s, t_map *map, va_list *args)
{
	long double		f;
	long long		dec;
	char			*string;
	char			*decstring;

	if (s[map->pos] == 'f' || s[map->pos] == 'F')
	{
		f = va_arg(*args, long double);
		dec = ft_round(f, map, 10);
		string = ft_itoa_base(ft_floatrect(f, map), 10, map, s[map->pos]);
		decstring = ft_itoa_base(dec, 10, map, s[map->pos]);
		string = ft_floatjoin(string, decstring, map);
		ft_floatflagger(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (0);
}

int	ft_longfinder3(const char *s, t_map *map, va_list *args)
{
	long int			*n;

	if (s[map->pos] == 'n')
	{
		n = va_arg(*args, long *);
		*n = map->size;
		map->pos++;
		return (1);
	}
	return (ft_longdoublefinder(s, map, args));
}

int	ft_longfinder2(const char *s, t_map *map, va_list *args)
{
	char				*string;
	unsigned long int	u;

	if (s[map->pos] == 'o')
	{
		u = va_arg(*args, unsigned long int);
		string = ft_itoa_base(u, 8, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'x' || s[map->pos] == 'X')
	{
		u = va_arg(*args, unsigned long int);
		string = ft_itoa_base(u, 16, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (ft_longfinder3(s, map, args));
}

int	ft_longfinder(const char *s, t_map *map, va_list *args)
{
	long int			i;
	unsigned long int	u;
	char				*string;

	map->typ = s[map->pos];
	if (s[map->pos] == 'd' || s[map->pos] == 'i')
	{
		i = va_arg(*args, long int);
		string = ft_itoa_base(i, 10, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'u')
	{
		u = va_arg(*args, unsigned long int);
		string = ft_itoa_base(u, 10, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (ft_longfinder2(s, map, args));
}

int	ft_thebigshort(const char *s, t_map *map, va_list *args)
{
	if (map->bon == 1)
		return (ft_longfinder(s, map, args));
	else if (map->bon == 2)
		return (ft_longlongfinder(s, map, args));
	else if (map->bon == 3)
		return (ft_shortfinder(s, map, args));
	else if (map->bon == 4)
		return (ft_shortshortfinder(s, map, args));
	else if (map->bon == 5)
		return (ft_longdoublefinder(s, map, args));
	else
		return (0);
}
