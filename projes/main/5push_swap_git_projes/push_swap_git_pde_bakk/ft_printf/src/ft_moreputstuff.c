/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_moreputstuff.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 19:24:51 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 13:03:35 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

char	*ft_apostrophe(char *s, t_map *map)
{
	char	*ret;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (map->apos <= -1 || map->typ == 'x' || map->typ == 'X')
		return (s);
	ret = printf_calloc(printf_strlen(s) + map->apos + 1, sizeof(char));
	if (!ret)
		return (0);
	while (s[n])
	{
		ret[i] = s[n];
		i++;
		n++;
		if ((printf_strlen(s) - n) % 3 == 0 && map->apos > 0)
		{
			ret[i] = ',';
			i++;
			map->apos--;
		}
	}
	free(s);
	return (ret);
}

void	ft_put0x(int fd, t_map *map)
{
	if (map->nb == 0 && map->prec == 0 && map->hash == 1 && map->typ == 'o')
		ft_putchar_flags('0', fd, map, 0);
	if (map->bon != 5 && (map->typ == 'p' || map->typ == 'a' || map->typ == 'A'
			|| (map->hash == 1 && map->nb != 0 && (map->typ == 'x'
					|| map->typ == 'X' || map->typ == 'o'))))
	{
		ft_putchar_flags('0', fd, map, 0);
		if (map->min == 1)
		{
			if (map->typ == 'o')
				map->pfill--;
			else
				map->pad--;
		}
		if (map->typ == 'x' || map->typ == 'p' || map->typ == 'X'
			|| map->typ == 'A' || map->typ == 'a')
		{
			if (map->typ == 'X' || map->typ == 'A')
				ft_putchar_flags('X', fd, map, 0);
			else
				ft_putchar_flags('x', fd, map, 0);
			if (map->min == 1)
				map->pad--;
		}
	}
}

void	ft_nbrflagger_flags(char *s, int fd, t_map *map)
{
	if ((map->plus == 1 && map->nb >= 0) || map->nb < 0)
		map->pad--;
	if (map->zero == 1 && map->pad > 0 && map->prec > -1)
		map->zero = 0;
	if (map->spac == 1 && map->plus == 0 && map->hash == 0 && map->nb >= 0)
	{
		ft_putchar_flags(' ', fd, map, 0);
		map->pad--;
	}
	if (map->nb == 0 && map->prec == 0 && map->width > 1)
		map->pad++;
	if (map->prec == -1 && map->typ == 'o' && map->hash == 1 && map->nb != 0)
		map->pad--;
	if (map->prec < (int)printf_strlen(s) && map->prec != -1 && map->typ == 'o'
		&& map->hash == 1)
		map->pad--;
	if (map->hash == 1 && map->nb != 0 && map->min == 0)
	{
		if (map->typ == 'o')
			map->pfill--;
		if (map->typ == 'x' || map->typ == 'X')
			map->pad = map->pad - 2;
	}
}

static void	norm_v3_doesnt_allow_ternaries_anymore(t_map *map, const char *s)
{
	if (map->prec > (int) printf_strlen(s))
		map->pad = map->width - map->prec;
	else
		map->pad = map->width - printf_strlen(s);
}

char	*ft_nbrputter_flags(char *s, int fd, t_map *map)
{
	s = ft_apostrophe(s, map);
	map->pfill = map->prec - printf_strlen(s);
	if (map->width > (int)printf_strlen(s) && map->width > map->prec)
		norm_v3_doesnt_allow_ternaries_anymore(map, s);
	ft_nbrflagger_flags(s, fd, map);
	if (map->typ == 'p' && map->min == 0)
		map->pad = map->pad - 2;
	while (map->pad > 0 && map->min == 0 && map->zero == 0)
	{
		ft_putchar_flags(' ', fd, map, 0);
		map->pad--;
	}
	ft_putsign_fd(fd, map);
	ft_put0x(fd, map);
	while (map->zero == 1 && map->pad > 0)
	{
		ft_putchar_flags('0', fd, map, 0);
		map->pad--;
	}
	ft_lastputstuff(s, fd, map);
	return (s);
}
