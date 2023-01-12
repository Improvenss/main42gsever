/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:29:23 by akaraca           #+#    #+#             */
/*   Updated: 2023/01/12 13:40:53 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	update_player(t_main *main)
// {
// 	double	newPlayerX = main->ply.pos_x;
// 	double	newPlayerY = main->ply.pos_y;

// 	if (main->key.up == true)
// 	{
// 		newPlayerX = main->ply.pos_x + (main->ply.walk_speed / BOX_SIZE) * cos(main->ply.rotation_angle * ONE_DEGREE);
// 		newPlayerY = main->ply.pos_y - (main->ply.walk_speed / BOX_SIZE) * sin(main->ply.rotation_angle * ONE_DEGREE);
// 	}
// 	if (main->key.down == true)
// 	{
// 		newPlayerX = main->ply.pos_x - (main->ply.walk_speed / BOX_SIZE) * cos(main->ply.rotation_angle * ONE_DEGREE);
// 		newPlayerY = main->ply.pos_y + (main->ply.walk_speed / BOX_SIZE) * sin(main->ply.rotation_angle * ONE_DEGREE);
// 	}
// 	if (main->key.left == true)
// 	{
// 		newPlayerX = main->ply.pos_x - (main->ply.walk_speed / BOX_SIZE) * sin(main->ply.rotation_angle * ONE_DEGREE);
// 		newPlayerY = main->ply.pos_y - (main->ply.walk_speed / BOX_SIZE) * cos(main->ply.rotation_angle * ONE_DEGREE);
// 	}
// 	if (main->key.right == true)
// 	{
// 		newPlayerX = main->ply.pos_x + (main->ply.walk_speed / BOX_SIZE) * sin(main->ply.rotation_angle * ONE_DEGREE);
// 		newPlayerY = main->ply.pos_y + (main->ply.walk_speed / BOX_SIZE) * cos(main->ply.rotation_angle * ONE_DEGREE);
// 	}
// 	// printf("newPlayerX: %f\n", main->ply.pos_x + (main->ply.walk_speed / BOX_SIZE) * cos(main->ply.rotation_angle * ONE_DEGREE));
// 	// printf("newPlayerY: %f\n", main->ply.pos_y - (main->ply.walk_speed / BOX_SIZE) * sin(main->ply.rotation_angle * ONE_DEGREE));
// 	if (!is_wall(main, newPlayerX, newPlayerY))
// 	{
// 		main->ply.pos_x = newPlayerX;
// 		main->ply.pos_y = newPlayerY;
// 		printf("	plyr_map x: %f y:%f\n", main->ply.pos_x * BOX_SIZE, main->ply.pos_y * BOX_SIZE);
// 		printf("	plyr_ x: %f y:%f\n", main->ply.pos_x, main->ply.pos_y);
// 	}
// 	return (0);
// }

// void	key_function(t_main *main)
// {
// 	if (main->key.r_left == true)
// 	{
// 		if (main->ply.rotation_angle == 360)
// 			main->ply.rotation_angle = PLAYER_ROTATION_SPEED;
// 		else
// 			main->ply.rotation_angle = main->ply.rotation_angle + PLAYER_ROTATION_SPEED;
// 		if (main->ply.rotation_angle == 360)
// 			main->ply.rotation_angle = 0;
// 	}
// 	if (main->key.r_right == true)
// 	{
// 		if (main->ply.rotation_angle == 0)
// 			main->ply.rotation_angle = 360 - PLAYER_ROTATION_SPEED;
// 		else
// 			main->ply.rotation_angle = main->ply.rotation_angle - PLAYER_ROTATION_SPEED;
// 	}
// 	// printf("rotation_angle: %f\n", main->ply.rotation_angle);
// 	update_player(main);
// }

// int	key_press(int keycode, t_main *main)
// {
// 	if (keycode == KEY_A)
// 		main->key.left = true;
// 	if (keycode == KEY_D)
// 		main->key.right = true;
// 	if (keycode == KEY_W)
// 		main->key.up = true;
// 	if (keycode == KEY_S)
// 		main->key.down = true;
// 	if (keycode == KEY_ARROW_LEFT)
// 		main->key.r_left = true;
// 	if (keycode == KEY_ARROW_RIGHT)
// 		main->key.r_right = true;
// 	if (keycode == KEY_ESC)
// 		ft_exit(main);
//     return (0);
// }

// int	key_release(int keycode, t_main *main)
// {
// 	if (keycode == KEY_A)
// 		main->key.left = false;
// 	if (keycode == KEY_D)
// 		main->key.right = false;
// 	if (keycode == KEY_W)
// 		main->key.up = false;
// 	if (keycode == KEY_S)
// 		main->key.down = false;
// 	if (keycode == KEY_ARROW_LEFT)
// 		main->key.r_left = false;
// 	if (keycode == KEY_ARROW_RIGHT)
// 		main->key.r_right = false;
// 	return (0);
// }