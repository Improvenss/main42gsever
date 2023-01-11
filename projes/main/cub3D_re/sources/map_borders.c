/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_borders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:45:23 by gsever            #+#    #+#             */
/*   Updated: 2022/12/05 11:51:55 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_borders_inside(t_main *main)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (main->map.map[y])
	{
		while (main->map.map[y][x])
		{
			if (ft_strchr("0NSEW", main->map.map[y][x]) \
			&& (ft_strchr(" \0", main->map.map[y][x - 1]) \
			|| ft_strchr(" \0", main->map.map[y][x + 1]) \
			|| ft_strchr(" \0", main->map.map[y - 1][x - 1]) \
			|| ft_strchr(" \0", main->map.map[y - 1][x + 1]) \
			|| ft_strchr(" \0", main->map.map[y + 1][x - 1]) \
			|| ft_strchr(" \0", main->map.map[y + 1][x + 1])))
				return (print_error(PROMPT, ERR_BORDER, NULL, ERR_MAP_CHARS));
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	map_borders_left(t_main *main)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	while (main->map.map[y])
	{
		count = 0;
		while (main->map.map[y][x])
		{
			if (main->map.map[y][x] == '1')
				count++;
			else if (count == 0 && ft_strchr("0NSEW", main->map.map[y][x]))
				return (print_error(PROMPT, ERR_BORDER, ERR_ARG_OOB, "LEFT"));
			x++;
		}
		x = 0;
		if (count == 0)
			return(print_error(PROMPT, ERR_BORDER, ERR_EMPTY_L, "LEFT"));
		//printf("--->count:%d\n", count);
		y++;
	}
	return (0);
}

int	map_borders_bottom(t_main *main)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = main->map.max_y;
	while (main->map.map[y][x])
	{
		count = 0;
		while (y >= 0)
		{
			if (main->map.map[y][x] == '1')
				count++;
			else if (count == 0 && ft_strchr("0NSEW", main->map.map[y][x]))
				return (print_error(PROMPT, ERR_BORDER, ERR_ARG_OOB, "BOTTOM"));
			y--;
		}
		y = main->map.max_y;
		if (count == 0)
			return (print_error(PROMPT, ERR_BORDER, ERR_EMPTY_L, "BOTTOM"));
		//printf("--->count:%d\n", count);
		x++;
	}
	return (0);
}

int map_borders_right(t_main *main)
{
	int	x;
	int	y;
	int	count;

	x = main->map.max_x;
	y = 0;
	while (main->map.map[y])
	{
		count = 0;
		while (x >= 0)
		{
			if (main->map.map[y][x] == '1')
				count++;
			else if (count == 0 && ft_strchr("0NSEW", main->map.map[y][x]))
				return (print_error(PROMPT, ERR_BORDER, ERR_ARG_OOB, "RIGHT"));
			x--;
		}
		x = main->map.max_x;
		if (count == 0)
			return (print_error(PROMPT, ERR_BORDER, ERR_EMPTY_L, "RIGHT"));
		//printf("--->count:%d\n", count);
		y++;
	}
	return (0);
}

int	map_borders_top(t_main *main)
{
	int x;
	int y;
	int count;

	x = 0;
	y = 0;
	while (main->map.map[y][x])
	{
		count = 0;
		while (main->map.map[y] && main->map.map[y][x])
		{
			if (main->map.map[y][x] == '1')
				count++;
			else if (count == 0 && ft_strchr("0NSEW", main->map.map[y][x]))
				return (print_error(PROMPT, ERR_BORDER, ERR_ARG_OOB, "TOP"));
			y++;
		}
		y = 0;
		if (count == 0)
			return (print_error(PROMPT, ERR_BORDER, ERR_EMPTY_L, "TOP"));
		//printf("--->count:%d\n", count);
		x++;
	}
	return (0);
}

