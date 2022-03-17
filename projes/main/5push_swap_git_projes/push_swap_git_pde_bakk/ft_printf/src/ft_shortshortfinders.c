/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shortshortfinders.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 14:46:34 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 12:57:00 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_shortshortfinder3(const char *s, t_map *map, va_list *args)
{
	signed char	*n;

	if (s[map->pos] == 'n')
	{
		n = va_arg(*args, signed char *);
		*n = map->size;
		map->pos++;
		return (1);
	}
	return (0);
}

int	ft_shortshortfinder2(const char *s, t_map *map, va_list *args)
{
	char			*string;
	unsigned char	u;

	if (s[map->pos] == 'o')
	{
		u = va_arg(*args, int);
		string = ft_itoa_base(u, 8, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'x' || s[map->pos] == 'X')
	{
		u = va_arg(*args, int);
		string = ft_itoa_base(u, 16, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (ft_shortshortfinder3(s, map, args));
}

int	ft_shortshortfinder(const char *s, t_map *map, va_list *args)
{
	signed char		i;
	unsigned char	u;
	char			*string;

	map->typ = s[map->pos];
	if (s[map->pos] == 'd' || s[map->pos] == 'i')
	{
		i = va_arg(*args, int);
		string = ft_itoa_base(i, 10, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'u')
	{
		u = va_arg(*args, int);
		string = ft_itoa_base(u, 10, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (ft_shortshortfinder2(s, map, args));
}
