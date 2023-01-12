/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:05:27 by gsever            #+#    #+#             */
/*   Updated: 2023/01/12 16:42:08 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Left & Right rotation okay but now we are not doing up & down look.
 * 
 * @param main main structure
 * @param way up | down | left | right -> bitwise val.
 * @param val + or -
 */
void	player_turn(t_main *main, int way, double val)
{
	if (way & (TURN_LEFT | TURN_RIGHT))
		main->ply.rotation_angle -= val * PLAYER_ROTATION_SPEED;
	if (main->ply.rotation_angle < 0)
		main->ply.rotation_angle = 360;
	else if (main->ply.rotation_angle > 360)
		main->ply.rotation_angle = 0;
}

/**
 * @brief W A S D steps for player.
 */
void	player_move(t_main *main, int way, double val)
{
	double	last_location_x;
	double	last_location_y;

	last_location_x = main->ply.pos_x;
	last_location_y = main->ply.pos_y;
	if (way & (GO_FORWARD | GO_BACKWARD))
	{
		main->ply.pos_x += val * ((main->ply.walk_speed / BOX_SIZE)
			* cos(main->ply.rotation_angle * ONE_DEGREE));
		if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
			main->ply.pos_x = last_location_x;
		main->ply.pos_y -= val * ((main->ply.walk_speed / BOX_SIZE)
			* sin(main->ply.rotation_angle * ONE_DEGREE));
		if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
			main->ply.pos_y = last_location_y;
	}
	if (way & (GO_LEFT | GO_RIGHT))
	{
		main->ply.pos_x += val * ((main->ply.walk_speed / BOX_SIZE)
			* sin(main->ply.rotation_angle * ONE_DEGREE));
		if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
			main->ply.pos_x = last_location_x;
		main->ply.pos_y += val * ((main->ply.walk_speed / BOX_SIZE)
			* cos(main->ply.rotation_angle * ONE_DEGREE));
		if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
			main->ply.pos_y = last_location_y;
	}
}

void	update_player_all(t_main *main)
{
	if (main->key.value & GO_FORWARD)// W
		player_move(main, GO_FORWARD, 1.0);
	if (main->key.value & GO_BACKWARD)// S
		player_move(main, GO_BACKWARD, -1.0);
	if (main->key.value & GO_RIGHT)// D
		player_move(main, GO_RIGHT, 1.0);
	if (main->key.value & GO_LEFT)// A
		player_move(main, GO_LEFT, -1.0);
	if (main->key.value & TURN_RIGHT)// ➡
		player_turn(main, TURN_RIGHT, 1.0);
	if (main->key.value & TURN_LEFT)// ⬅
		player_turn(main, TURN_LEFT, -1.0);
	if (main->key.value & TURN_UP)// ⬆
		player_turn(main, TURN_UP, 1.0);
	if (main->key.value & TURN_DOWN)// ⬇
		player_turn(main, TURN_DOWN, -1.0);
	return ;
}

void	set_player_default_pos(t_main *main)
{
	main->ply.pos_x = main->ply.default_pos_x;
	main->ply.pos_y = main->ply.default_pos_y;
	main->ply.rotation_angle = main->ply.default_rotation_angle;
}

void	init_set_player(t_main *main, int x, int y)
{
	y = -1;
	while (main->map.map[++y])
	{
		x = -1;
		while (main->map.map[y][++x])
		{
			if (ft_strchr("ENWS", main->map.map[y][x]))
			{
				if (main->map.map[y][x] == 'E')
					main->ply.rotation_angle = 0;
				else if (main->map.map[y][x] == 'N')
					main->ply.rotation_angle = 90;
				else if (main->map.map[y][x] == 'W')
					main->ply.rotation_angle = 180;
				else if (main->map.map[y][x] == 'S')
					main->ply.rotation_angle = 270;
				main->map.map[y][x] = '0';
				main->ply.default_rotation_angle = main->ply.rotation_angle;
				main->ply.pos_x = (double)x;
				main->ply.default_pos_x = (double)x;
				main->ply.pos_y = (double)y;
				main->ply.default_pos_y = (double)y;
				return ;
			}
		}
	}
	return ;
}
