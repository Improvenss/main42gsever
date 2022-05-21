/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_flags.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/29 20:51:26 by pde-bakk      #+#    #+#                 */
/*   Updated: 2020/10/24 11:38:38 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	ft_bonusflagfinder(const char *s, t_map *map)
{
	if (s[map->pos] == 'l')
	{
		map->bon = 1;
		map->pos++;
		if (s[map->pos] == 'l')
		{
			map->bon = 2;
			map->pos++;
		}
	}
	if (s[map->pos] == 'h')
	{
		map->bon = 3;
		map->pos++;
		if (s[map->pos] == 'h')
		{
			map->bon = 4;
			map->pos++;
		}
	}
}

void	ft_thirdflagfinder(const char *s, t_map *map, va_list *args)
{
	while (s[map->pos] >= '0' && s[map->pos] <= '9' && s[map->pos - 1] != '.')
	{
		map->width = map->width * 10 + s[map->pos] - 48;
		map->pos++;
	}
	if (s[map->pos] == '.')
	{
		map->pos++;
		map->prec = 0;
		while (s[map->pos] >= '0' && s[map->pos] <= '9')
		{
			map->prec = map->prec * 10 + s[map->pos] - 48;
			map->pos++;
		}
		if (s[map->pos] == '*')
		{
			map->prec = va_arg(*args, int);
			map->pos++;
		}
	}
}

void	ft_secondflagfinder(const char *s, t_map *map, va_list *args)
{
	if (s[map->pos] == '#')
	{
		map->hash = 1;
		map->pos++;
	}
	if (s[map->pos] == '0')
	{
		map->zero = 1;
		map->pos++;
	}
	if (s[map->pos] == '*' && s[map->pos - 1] != '.')
	{
		map->width = va_arg(*args, int);
		map->pos++;
		if (map->width < 0)
		{
			map->min = 1;
			map->width = ft_absolutely(map->width);
		}
	}
}

void	ft_flagfinder(const char *s, t_map *map, va_list *args)
{
	while (printf_strchr("cspdiouxX%nfFgGeEaA", s[map->pos]) == 0)
	{
		while (s[map->pos] == '-')
		{
			map->min = 1;
			map->pos++;
		}
		if (s[map->pos] == '+')
		{
			map->plus = 1;
			map->pos++;
		}
		if (s[map->pos] == ' ')
		{
			map->spac = 1;
			map->pos++;
		}
		ft_secondflagfinder(s, map, args);
		ft_thirdflagfinder(s, map, args);
		ft_bonusflagfinder(s, map);
		ft_morebonusflags(s, map);
	}
	return ;
}

void	ft_flagfiller(int fd, t_map *map, char *s)
{
	if ((int)printf_strlen(s) > map->prec && map->prec != -1)
		map->pad = map->width - map->prec;
	else
		map->pad = map->width - printf_strlen(s);
	while (map->min == 0 && map->pad > 0)
	{
		if (map->zero == 1)
			ft_putchar_flags('0', fd, map, 0);
		else
			ft_putchar_flags(' ', fd, map, 0);
		map->pad--;
	}
	return ;
}
