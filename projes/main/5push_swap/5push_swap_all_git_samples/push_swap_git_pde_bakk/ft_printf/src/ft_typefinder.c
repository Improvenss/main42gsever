/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_typefinder.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 21:32:40 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 12:57:57 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_typefinder5(const char *s, t_map *map, va_list *args)
{
	if (s[map->pos] == '%')
	{
		ft_putchar_flags('%', map->fd, map, 1);
		map->pos++;
		return (1);
	}
	if (ft_floatfinder(s, map, args) == 1)
		return (1);
	while (printf_strchr("cspdiuxX%nfFgGeEaA", s[map->pos]) == 0)
		map->pos++;
	return (0);
}

int	ft_typefinder4(const char *s, t_map *map, va_list *args)
{
	void	*ptr;
	int		*n;
	char	*string;

	if (s[map->pos] == 'p')
	{
		ptr = va_arg(*args, void *);
		string = ft_ultoa((unsigned long long)ptr, 16, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'n')
	{
		n = va_arg(*args, int *);
		*n = map->size;
		map->pos++;
		return (1);
	}
	return (ft_typefinder5(s, map, args));
}

int	ft_typefinder3(const char *s, t_map *map, va_list *args)
{
	unsigned int	o;
	int				i;
	char			*string;

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
		o = va_arg(*args, unsigned);
		string = ft_itoa_base(o, 10, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (ft_typefinder4(s, map, args));
}

int	ft_typefinder2(const char *s, t_map *map, va_list *args)
{
	unsigned int	o;
	char			*string;

	if (s[map->pos] == 'o')
	{
		o = va_arg(*args, unsigned);
		string = ft_itoa_base(o, 8, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'x' || s[map->pos] == 'X')
	{
		o = va_arg(*args, unsigned);
		string = ft_itoa_base(o, 16, map, s[map->pos]);
		string = ft_nbrputter_flags(string, map->fd, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (ft_typefinder3(s, map, args));
}

int	ft_typefinder(const char *s, t_map *map, va_list *args)
{
	char	*string;
	char	c;

	map->typ = s[map->pos];
	if (s[map->pos] == 's')
	{
		string = va_arg(*args, char *);
		if (string == NULL)
			ft_putstr_flags("(null)", map->fd, map, 1);
		else
			ft_putstr_flags(string, map->fd, map, 1);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'c')
	{
		c = va_arg(*args, int);
		ft_putchar_flags(c, map->fd, map, 1);
		map->pos++;
		return (1);
	}
	return (ft_typefinder2(s, map, args));
}
