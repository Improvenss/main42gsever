/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_longlongfinders.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 14:40:30 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 12:17:01 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_longlongfinder3(const char *s, t_map *map, va_list *args)
{
	long long int			*n;

	if (s[map->pos] == 'n')
	{
		n = va_arg(*args, long long *);
		*n = map->size;
		map->pos++;
		return (1);
	}
	return (0);
}

int	ft_longlongfinder2(const char *s, t_map *map, va_list *args)
{
	char					*string;
	unsigned long long int	u;

	if (s[map->pos] == 'o')
	{
		u = va_arg(*args, unsigned long long int);
		string = ft_itoa_base(u, 8, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'x' || s[map->pos] == 'X')
	{
		u = va_arg(*args, unsigned long long int);
		string = ft_itoa_base(u, 16, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (ft_longlongfinder3(s, map, args));
}

int	ft_longlongfinder(const char *s, t_map *map, va_list *args)
{
	long long int			i;
	unsigned long long int	u;
	char					*string;

	map->typ = s[map->pos];
	if (s[map->pos] == 'd' || s[map->pos] == 'i')
	{
		i = va_arg(*args, long long int);
		string = ft_itoa_base(i, 10, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'u')
	{
		u = va_arg(*args, unsigned long long int);
		string = ft_itoa_base(u, 10, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (ft_longlongfinder2(s, map, args));
}
