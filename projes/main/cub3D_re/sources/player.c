/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:05:27 by gsever            #+#    #+#             */
/*   Updated: 2023/01/12 14:48:45 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Left & Right rotation okay but now we are not doing up & down look.
 * 
 * @param main main structure
 * @param way up | down | left | right
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
 * @brief W A S D steps for playeer.
 * 
 * @param main 
 * @param way 
 */
void	player_move(t_main *main, int way, double val)
{
	double	last_location_x;
	double	last_location_y;

	last_location_x = main->ply.pos_x;
	last_location_y = main->ply.pos_y;
	if (way & (GO_FORWARD | GO_BACKWARD))
	{
		main->ply.pos_x += val * ((main->ply.walk_speed / BOX_SIZE) * cos(main->ply.rotation_angle * ONE_DEGREE));
		// main->ply.x + (main->ply.walk_speed / BOX_SIZE) * cos(main->ply.rotation_angle * (PI / 180));
		if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
			main->ply.pos_x = last_location_x;
		main->ply.pos_y -= val * ((main->ply.walk_speed / BOX_SIZE) * sin(main->ply.rotation_angle * ONE_DEGREE));
		if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
			main->ply.pos_y = last_location_y;
	}
	if (way & (GO_LEFT | GO_RIGHT))
	{
		main->ply.pos_x += val * ((main->ply.walk_speed / BOX_SIZE) * sin(main->ply.rotation_angle * ONE_DEGREE));
		// main->ply.pos_x -= val * (main->ply.pos_y * main->ply.walk_speed * cos(main->ply.rotation_angle * ONE_DEGREE));
		if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
			main->ply.pos_x = last_location_x;
		main->ply.pos_y += val * ((main->ply.walk_speed / BOX_SIZE) * cos(main->ply.rotation_angle * ONE_DEGREE));
		if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
			main->ply.pos_y = last_location_y;
	}
}
// void	player_move_a_d(t_main *main, int way, double val)
// {
// 	double	last_location_x;
// 	double	last_location_y;

// 	(void)way;
// 	last_location_x = main->ply.pos_x;
// 	last_location_y = main->ply.pos_y;
// 	main->ply.pos_x -= val * (main->ply.pos_y * main->ply.walk_speed);
// 	if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
// 		main->ply.pos_x = last_location_x;
// 	main->ply.pos_y += val * (main->ply.pos_x * main->ply.walk_speed);
// 	if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
// 		main->ply.pos_y = last_location_y;
// }


// void	player_move_w_s(t_main *main, int way, double val)
// {
// 	double	last_location_x;
// 	double	last_location_y;

// 	(void)way;
// 	last_location_x = main->ply.pos_x;
// 	last_location_y = main->ply.pos_y;
// 	main->ply.pos_x += val * (main->ply.pos_x * main->ply.walk_speed);//bu okay ama karakter nereye bakiyorsa oraya dogru ilerlemiyor
// 	// main->ply.pos_x -= val * (PLAYER_WALKSPEED / main->box_size) * cos(main->ply.rotationAngle * (M_PI / 180));
// 	if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
// 		main->ply.pos_x = last_location_x;
// 	main->ply.pos_y += val * (main->ply.pos_y * main->ply.walk_speed);//bu okay ama karakter nereye bakiyorsa oraya dogru ilerlemiyor
// 	// main->ply.pos_y -= val * (PLAYER_WALKSPEED / main->box_size) * sin(main->ply.rotationAngle * (M_PI / 180));
// 	if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
// 		main->ply.pos_y = last_location_y;
// }

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
				main->ply.pos_x = (double)x;
				main->ply.pos_y = (double)y;
				return ;
			}
		}
	}
	return ;
}



// /**
//  * @brief Left & Right rotation okay but now we are not doing up & down look.
//  * 
//  * @param main main structure
//  * @param way up | down | left | right
//  * @param val + or -
//  */
// void	player_turn(t_main *main, int way, double val)
// {
// 	if (way & (TURN_LEFT | TURN_RIGHT))
// 		main->ply.rotation_angle += val * PLAYER_ROTATION_SPEED;
// 	if (main->ply.rotation_angle < 0)
// 		main->ply.rotation_angle = 360;
// 	else if (main->ply.rotation_angle > 360)
// 		main->ply.rotation_angle = 0;
// }

// /**
//  * @brief W A S D steps for playeer.
//  * 
//  * @param main 
//  * @param way 
//  */
// void	player_move(t_main *main, int way, double val)
// {
// 	double	last_location_x;
// 	double	last_location_y;

// 	last_location_x = main->ply.pos_x;
// 	last_location_y = main->ply.pos_y;
// 	if (way & (GO_FORWARD | GO_BACKWARD))
// 	{
// 		main->ply.pos_x += val * (main->ply.pos_x * (double)PLAYER_WALK_SPEED
// 			* cos(main->ply.rotation_angle * ONE_DEGREE));//bu okay ama karakter nereye bakiyorsa oraya dogru ilerlemiyor
// 		// main->ply.pos_x -= val * (PLAYER_WALKSPEED / main->box_size) * cos(main->ply.rotationAngle * (M_PI / 180));
// 		// main->ply.x + (main->ply.walk_speed / BOX_SIZE) * cos(main->ply.rotation_angle * (PI / 180));
// 		if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
// 			main->ply.pos_x = last_location_x;
// 		main->ply.pos_y += val * (main->ply.pos_y * (double)PLAYER_WALK_SPEED
// 			* sin(main->ply.rotation_angle * ONE_DEGREE));//bu okay ama karakter nereye bakiyorsa oraya dogru ilerlemiyor
// 		// main->ply.pos_y -= val * (PLAYER_WALKSPEED / main->box_size) * sin(main->ply.rotationAngle * (M_PI / 180));
// 		if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
// 			main->ply.pos_y = last_location_y;
// 	}
// 	else if (way & (GO_LEFT | GO_RIGHT))
// 	{
// 		main->ply.pos_x -= val * (main->ply.pos_y * (double)PLAYER_WALK_SPEED * cos(main->ply.rotation_angle * ONE_DEGREE));
// 		if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
// 			main->ply.pos_x = last_location_x;
// 		main->ply.pos_y += val * (main->ply.pos_x * (double)PLAYER_WALK_SPEED * sin(main->ply.rotation_angle * ONE_DEGREE));
// 		if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
// 			main->ply.pos_y = last_location_y;
// 	}
// }
// // void	player_move_a_d(t_main *main, int way, double val)
// // {
// // 	double	last_location_x;
// // 	double	last_location_y;

// // 	(void)way;
// // 	last_location_x = main->ply.pos_x;
// // 	last_location_y = main->ply.pos_y;
// // 	main->ply.pos_x -= val * (main->ply.pos_y * (double)PLAYER_WALK_SPEED);
// // 	if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
// // 		main->ply.pos_x = last_location_x;
// // 	main->ply.pos_y += val * (main->ply.pos_x * (double)PLAYER_WALK_SPEED);
// // 	if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
// // 		main->ply.pos_y = last_location_y;
// // }


// // void	player_move_w_s(t_main *main, int way, double val)
// // {
// // 	double	last_location_x;
// // 	double	last_location_y;

// // 	(void)way;
// // 	last_location_x = main->ply.pos_x;
// // 	last_location_y = main->ply.pos_y;
// // 	main->ply.pos_x += val * (main->ply.pos_x * (double)PLAYER_WALK_SPEED);//bu okay ama karakter nereye bakiyorsa oraya dogru ilerlemiyor
// // 	// main->ply.pos_x -= val * (PLAYER_WALKSPEED / main->box_size) * cos(main->ply.rotationAngle * (M_PI / 180));
// // 	if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
// // 		main->ply.pos_x = last_location_x;
// // 	main->ply.pos_y += val * (main->ply.pos_y * (double)PLAYER_WALK_SPEED);//bu okay ama karakter nereye bakiyorsa oraya dogru ilerlemiyor
// // 	// main->ply.pos_y -= val * (PLAYER_WALKSPEED / main->box_size) * sin(main->ply.rotationAngle * (M_PI / 180));
// // 	if (is_wall(main, main->ply.pos_x, main->ply.pos_y))
// // 		main->ply.pos_y = last_location_y;
// // }

// void	update_player_all(t_main *main)
// {
// 	if (main->key.value & GO_FORWARD)
// 		player_move(main, GO_FORWARD, 1);
// 	if (main->key.value & GO_BACKWARD)
// 		player_move(main, GO_BACKWARD, -1);
// 	if (main->key.value & GO_RIGHT)
// 		player_move(main, GO_RIGHT, 1);
// 	if (main->key.value & GO_LEFT)
// 		player_move(main, GO_LEFT, -1);
// 	if (main->key.value & TURN_RIGHT)
// 		player_turn(main, TURN_RIGHT, 1);
// 	if (main->key.value & TURN_LEFT)
// 		player_turn(main, TURN_LEFT, -1);
// 	if (main->key.value & TURN_UP)
// 		player_turn(main, TURN_UP, 1);
// 	if (main->key.value & TURN_DOWN)
// 		player_turn(main, TURN_DOWN, -1);
// 	return ;
// }

// void	init_set_player(t_main *main, int x, int y)
// {
// 	y = -1;
// 	while (main->map.map[++y])
// 	{
// 		x = -1;
// 		while (main->map.map[y][++x])
// 		{
// 			if (ft_strchr("ENWS", main->map.map[y][x]))
// 			{
// 				if (main->map.map[y][x] == 'E')
// 					main->ply.rotation_angle = 0;
// 				else if (main->map.map[y][x] == 'N')
// 					main->ply.rotation_angle = 90;
// 				else if (main->map.map[y][x] == 'W')
// 					main->ply.rotation_angle = 180;
// 				else if (main->map.map[y][x] == 'S')
// 					main->ply.rotation_angle = 270;
// 				main->map.map[y][x] = '0';
// 				main->ply.pos_x = (double)x;
// 				main->ply.pos_y = (double)y;
// 				return ;
// 			}
// 		}
// 	}
// 	return ;
// }
