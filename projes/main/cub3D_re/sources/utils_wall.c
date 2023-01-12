/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:53:55 by gsever            #+#    #+#             */
/*   Updated: 2023/01/12 13:53:08 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_wall(t_main *main, double x, double y)
{
	int	x_x;
	int	y_y;

	if (x < 0 || x > main->map.max_x || y < 0 || y > main->map.max_y)
		return (1);
	x_x = floor(x);
	y_y = floor(y);
	//printf("xX:%d, yY:%d\n", xX, yY);
	if (main->map.map[y_y][x_x] != '1')
		return (0);
	return (1);
}

int is_wall_v2(t_main *main, double x, double y)
{
	int xX;
	int yY;

	xX = (int)floor(x);
	yY = (int)floor(y);
	return (ft_strchr("0NSEW", main->map.map[yY][xX]) == NULL);
}