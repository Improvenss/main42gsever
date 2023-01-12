/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:18:29 by gsever            #+#    #+#             */
/*   Updated: 2023/01/12 17:53:20 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void put_pixel(double x, int y, double color, t_mlximg *img)//eskisi
// {
// 	int	i;
// 	int	j;
// 	i = -1;
// 	while (++i < BOX_SIZE)
// 	{
// 		if (color == -123.0)
// 			break ;
// 		j = -1;
// 		while (++j < BOX_SIZE)
// 		{
// 			img->addr[(int)(WINDOW_W * (y + i) + (x + j))] = color;
// 			if (j == BOX_SIZE - 1)
// 				img->addr[(int)(WINDOW_W * (y + i) + (x + j))] = COLOR_TUNDORA;
// 		}
// 		if (i == BOX_SIZE - 1)
// 		{
// 			j = -1;
// 			while (++j < BOX_SIZE)
// 				img->addr[(int)(WINDOW_W * (y + i) + (x + j))] = COLOR_TUNDORA;
// 		}
// 	}
// }

void put_pixel(double x, int y, double color, t_mlximg *mini_map, t_main *main)//yenisi
{
	int i;
	int j;

	i = -1;
	while (++i < BOX_SIZE)
	{
		if (color == -123.0)
			break ;
		j = -1;
		while (++j < BOX_SIZE)
		{
			mini_map->addr[(int)((BOX_SIZE * (main->map.max_x+1)) * (y + i) + (x + j))] = color;
			if (j == BOX_SIZE - 1)
				mini_map->addr[(int)((BOX_SIZE * (main->map.max_x+1)) * (y + i) + (x + j))] = COLOR_TUNDORA;
			//mini_map->addr[(int)(WINDOW_W * (y + i) + (x + j))] = color;
		}
		if (i == BOX_SIZE - 1)
		{
			j = -1;
			while (++j < BOX_SIZE)
				mini_map->addr[(int)((BOX_SIZE * (main->map.max_x+1)) * (y + i) + (x + j))] = COLOR_TUNDORA;
				// mini_map->addr[(int)(WINDOW_W * (y + i) + (x + j))] = COLOR_TUNDORA;
		}
	}
}

// void	draw_minimap_test(t_main *main)// eskisi
// {
// 	int	x;
// 	int y;
// 	y = -1;
// 	while (++y <= main->map.max_y)
// 	{
// 		x = -1;
// 		while (++x <= main->map.max_x)
// 		{
// 			if (main->map.map[y][x] == '1')
// 				put_pixel(BOX_SIZE * x, BOX_SIZE * y, 0xffffff, &(main->mini_map));
// 			else if (main->map.map[y][x] == '0')
// 				put_pixel(BOX_SIZE * x, BOX_SIZE * y, 0x000000, &(main->mini_map));
// 			// else
// 				// put_pixel(BOX_SIZE * x, BOX_SIZE * y, -123.0, &(main->img));
// 		}
// 	}
// }

/**
 * @brief Player's rotation_angle (one line) RED
 * @param main 
 */
void	draw_player_directory(t_main *main)
{
	double ydy;
	double ydx;
	ydy = 1 * sin((main->ply.rotation_angle + 180) * ONE_DEGREE);
	ydx = 1 * cos((main->ply.rotation_angle + 180) * ONE_DEGREE);
    double    ray_x;
    double    ray_y;
    double    dx;
    double    dy;
    // double    max_value;
    
    ray_x = main->ply.pos_x;
    ray_y = main->ply.pos_y;
    dx = (main->ply.pos_x - ydx) - main->ply.pos_x;
    dy = (main->ply.pos_y + ydy) - main->ply.pos_y;

    // max_value = fmax(fabs(dx), fabs(dy));
    // dx /= max_value;
    // dy /= max_value;
    while (1)
    {
        if (!is_wall(main, ray_x, ray_y))
            main->mini_map.addr[(BOX_SIZE * (main->map.max_x+1)) * (int)floor(BOX_SIZE * ray_y) + (int)floor(BOX_SIZE * ray_x)] = COLOR_RED;
        else
            break;
        ray_x += dx / 2000;
        ray_y += dy / 2000;
    }
	//printf("x:%f y:%f\n", ray_x, ray_y);
}

void	draw_minimap_test(t_main *main)// yenisi
{
	int	x;
	int y;
// int color = 255*(main->texture.rgb_c[0] * 65536) + (main->texture.rgb_c[1] * 256) + main->texture.rgb_c[2];

	y = -1;
	while (++y <= main->map.max_y)
	{
		x = -1;
		while (++x <= main->map.max_x)
		{
			if (main->map.map[y][x] == '1')
				put_pixel(BOX_SIZE * x, BOX_SIZE * y, 0xffffff, &(main->mini_map), main);
			else if (main->map.map[y][x] == '0')
				put_pixel(BOX_SIZE * x, BOX_SIZE * y, 0x000000, &(main->mini_map), main);
			else
				put_pixel(BOX_SIZE * x, BOX_SIZE * y, -123.0, &(main->mini_map), main);
				// put_pixel(BOX_SIZE * x, BOX_SIZE * y, color, &(main->mini_map), main);
		}
	}
}

void	draw_player_test(t_main *main)
{
	int	x;
	int	y;
	int l;

	l = (BOX_SIZE / PLAYER_THICKNESS) / 2;
	y = -1 * l;
	while (y <= l)
	{
		x = -1 * l;
		while (x <= l)
		{
			main->mini_map.addr[(int)(BOX_SIZE * (main->map.max_x+1)) * (int)(BOX_SIZE * main->ply.pos_y + y) + (int)(BOX_SIZE * main->ply.pos_x + x)] = 0xff0000;
			x++;
		}
		y++;
	}
}

void	draw_background( t_main *main)
{
//White RGB code = 255*65536+255*256+255 = #FFFFFF        başına bitanadaha koy şaffaflığ ıçın
	int	y = 0;
	int ceil = (main->texture.rgb_c[0] * 65536) + (main->texture.rgb_c[1] * 256) + main->texture.rgb_c[2];
	int floor = (main->texture.rgb_f[0] * 65536) + (main->texture.rgb_f[1] * 256) + main->texture.rgb_f[2];
//	printf("ceil: %d floor: %d\n", ceil, floor);
	while (y < WINDOW_H / 2)
	{
		int x = 0;
		while (x < WINDOW_W)
		{
			main->screen.addr[WINDOW_W * y + x] = ceil;
			x++;
		}
		y++;
	}
	while (y < WINDOW_H)
	{
		int x = 0;
		while (x < WINDOW_W)
		{
			main->screen.addr[WINDOW_W * y + x] = floor;
			x++;
		}
		y++;
	}
}

double	ray_vertical(t_main *main, double angle, double dir_x, double dir_y, bool *hit)
{
	double vdy;
	double vdx;

	if (dir_x == -1)
		vdx = main->ply.pos_x - floor(main->ply.pos_x);
	else
		vdx = ceil(main->ply.pos_x) - main->ply.pos_x;
	vdy = fabs(tan(angle * ONE_DEGREE) * vdx);

	double tmp_x = vdx*dir_x;
	double tmp_y = vdy*dir_y;
	// printf("Box:Vx: %f Vy:%f\n", tmp_x, tmp_y);
	while (main->ply.pos_x + vdx*dir_x >= 0 && main->ply.pos_x + vdx*dir_x <= main->map.max_x
	&& main->ply.pos_y + vdy*dir_y >= 0 && main->ply.pos_y + vdy*dir_y <= main->map.max_y)
	{
		// printf("---\n");
		vdx = vdx + 0.001;
		if (is_wall_v2(main, main->ply.pos_x + vdx*dir_x, main->ply.pos_y + vdy*dir_y))
		{
			*hit = true;
			// printf("V:ture\n");
			tmp_x = vdx*dir_x;
			tmp_y = vdy*dir_y;
			// printf("Vx: %f Vy:%f\n", tmp_x, tmp_y);
			// printf("Px: %f Py:%f\n", main->ply.pos_x, main->ply.pos_y);
			break;
		}
		vdx = vdx + 1 - 0.001;
		vdy = fabs(tan(angle * ONE_DEGREE) * vdx);
	}

	// if (!is_wall(main->ply.pos_x + vdx*dir_x, main->ply.pos_y + vdy*dir_y, main))
	// {
	// 	while (1)
	// 	{
	// 		vdx = vdx + 1;
	// 		vdy = fabs(tan(angle * ONE_DEGREE) * vdx);
	// 		if (!is_wall(main->ply.pos_x + vdx*dir_x, main->ply.pos_y + vdy*dir_y, main))
	// 		{
	// 			tmp_x = vdx*dir_x;
	// 			tmp_y = vdy*dir_y;
	// 		}
	// 		else
	// 			break ;
	// 	}
	// }
	double distance;
	if (*hit == true)
		distance = sqrt((tmp_x*tmp_x) + (tmp_y*tmp_y));
	else
		distance = 10000;
	return (distance);
}

double ray_horizonal(t_main *main, double angle, double dir_x, double dir_y, bool *hit)
{
	double hdy;
	double hdx;

	if (dir_y == -1)
		hdy = main->ply.pos_y - floor(main->ply.pos_y);
	else
		hdy = ceil(main->ply.pos_y) - main->ply.pos_y;
	hdx = fabs(hdy / tan(angle * ONE_DEGREE));

	double tmp_y = hdy*dir_y;
	double tmp_x = hdx*dir_x;
// printf("Box:Hx: %f Hy:%f\n", tmp_x, tmp_y);
	if (!is_wall(main, main->ply.pos_x + hdx*dir_x, main->ply.pos_y + hdy*dir_y))
	{
		while (main->ply.pos_x + hdx*dir_x >= 0 && main->ply.pos_x + hdx*dir_x <= main->map.max_x
		&& main->ply.pos_y + hdy*dir_y >= 0 && main->ply.pos_y + hdy*dir_y <= main->map.max_y)
		{
		// printf("---\n");
			hdy = hdy + 0.001;
			if (is_wall_v2(main, main->ply.pos_x + hdx*dir_x, main->ply.pos_y + hdy*dir_y))
			{
				*hit = true;
			// printf("H:ture\n");
				tmp_x = hdx*dir_x;
				tmp_y = hdy*dir_y;
			// printf("Hx: %f Hy:%f\n", tmp_x, tmp_y);
			// printf("Px: %f Py:%f\n", main->ply.pos_x, main->ply.pos_y);
				break;
			}
			hdy = hdy + 1 - 0.001;
			hdx = fabs(hdy / tan(angle * ONE_DEGREE));
		}
	}
	else
		*hit = true;

	// if (!is_wall(main->ply.pos_x + hdx*dir_x, main->ply.pos_y + hdy*dir_y, main))
	// {
	// 	while (1)
	// 	{
	// 		hdy = hdy + 1;
	// 		hdx = fabs(hdy / tan(angle * ONE_DEGREE));
	// 		if (!is_wall(main->ply.pos_x + hdx*dir_x, main->ply.pos_y + hdy*dir_y, main))
	// 		{
	// 			tmp_y = hdy*dir_y;
	// 			tmp_x = hdx*dir_x;
	// 		}
	// 		else
	// 			break;
	// 	}
	// }
	double distance;
	if (*hit == true)
		distance = sqrt((tmp_x*tmp_x) + (tmp_y*tmp_y));
	else
		distance = 10000;
	return (distance);
}



void _3D(t_main *main, double distance, int ray_count)
{
	int loc;
	int mid;
	double oran;
	int	i;
	int color;
	distance = distance * (double)BOX_SIZE * 0.7;
	i = 0;
	mid = WINDOW_H / 2;
	loc = (WINDOW_W * mid) - ray_count;
	oran = ((double)WINDOW_H / 2 / distance) * (double)BOX_SIZE;
	// if (distance > 3)
	// {
		if (main->test._hith == true && main->test._hitv == false)
		{
			color = COLOR_D_PURPLE;
		}
		else if (main->test._hith == false && main->test._hitv == true)
		{
			color = COLOR_D_GREEN;
		}
	// }
	// else
	// 	color = COLOR_TUNDORA;
	while (i < oran && i < WINDOW_H / 2.0)
	{
		main->screen.addr[(loc + (WINDOW_W * i))] = color;
		main->screen.addr[(loc - (WINDOW_W * i))] = color;
		i++;
	}
}

/**
 * @brief Minimap's ray's and 3D renders print func().
 * 
 * @param distance 
 * @param dir_x 
 * @param dir_y 
 * @param main 
 * @param angle 
 * @param ray_count 
 */
void draw_ray(double distance, int dir_x, int dir_y, t_main *main, double angle, int ray_count)
{
    double    ray_x;
    double    ray_y;
    double    dx;
    double    dy;
    
    ray_x = main->ply.pos_x;
    ray_y = main->ply.pos_y;
    dx = distance * fabs(cos(angle * ONE_DEGREE)) * dir_x;
    dy = distance * fabs(sin(angle * ONE_DEGREE)) * dir_y;
    while (1)
    {
        if (!is_wall(main, ray_x, ray_y))
            main->mini_map.addr[(BOX_SIZE * (main->map.max_x +1)) * (int)floor(BOX_SIZE * ray_y) + (int)floor(BOX_SIZE * ray_x)] = 0x00ff00;// player's minimap rays.
        else
		{
			_3D(main, distance, ray_count);
            break;
		}
        ray_x += dx / 2000;
        ray_y += dy / 2000;
    }
	(void)ray_count;
}

void	raycasting(t_main *main, double angle, int ray_count)
{
	int dir_x = ((cos(angle * ONE_DEGREE) > 0) * 2) - 1;
	int dir_y = ((sin(angle * ONE_DEGREE) > 0) * -2) + 1;
	double distance_v;
	double distance_h;
	double distance;
	bool hitv = false;
	bool hith = false;
	distance_v = ray_vertical(main, angle, dir_x, dir_y, &hitv); //dikey
	distance_h = ray_horizonal(main, angle, dir_x, dir_y, &hith); //yatay
	// printf("V: %f H:%f\n", distance_v, distance_h);

//**************************************************************************************
	// if ((hitv == true && hith == true) || (hitv == false && hith == false))
	// {
	// 	if (distance_v < distance_h)
	// 		distance = distance_v;
	// 	else
	// 		distance = distance_h;
	// }
	// else if (hitv == false && hith == true)
	// 	distance = distance_h;
	// else
	// 	distance = distance_v;
//**************************************************************************************
	if (distance_v < distance_h)
	{
		distance = distance_v;
main->test._hith = false;
main->test._hitv = true;
	}
	else
{
		distance = distance_h;
main->test._hith = true;
main->test._hitv = false;
}
//**************************************************************************************

	draw_ray(distance, dir_x, dir_y, main, angle, ray_count);
}

void	draw_with_ray_casting(t_main *main)
{
	draw_background(main);// floor and ceil
	draw_minimap_test(main);

	double angle;
	angle = -1 * (FOV / 2.0);
	int ray_count = 0;
	while (angle <= (FOV / 2.0))// angle: -30º <= 30º -> arasinda 60º
	{
		raycasting(main, main->ply.rotation_angle + angle, ray_count);
		angle += (FOV / 2.0) / ((FOV_THICKNESS - 1) / 2.0);
		ray_count++;
	}
	draw_player_test(main);// player's red square.
	draw_player_directory(main);// player's rotation_angle (one line).
	mlx_put_image_to_window(main->mlx.ptr, main->mlx.win,
		main->screen.ptr, 0, 0);
	mlx_put_image_to_window(main->mlx.ptr, main->mlx.win,
		main->mini_map.ptr, 0, 0);
}

void	draw_text_on_window(t_main *main)
{
	mlx_string_put(main->mlx.ptr, main->mlx.win, WINDOW_W - 80, WINDOW_H - 20, COLOR_TUNDORA, "H - Help");// Burasi H tusuna bastigimizda help ekrani acilacak. onun icin. Belki bunu ayarlar icin sekme flaan da yapabilirisz simdilik boyle dusundum.
	mlx_string_put(main->mlx.ptr, main->mlx.win, WINDOW_W - 80, WINDOW_H - 120, COLOR_TUNDORA, ft_itoa((int)main->ply.rotation_angle));
	mlx_string_put(main->mlx.ptr, main->mlx.win, WINDOW_W - 140, WINDOW_H - 150, COLOR_TUNDORA, "x:");
	mlx_string_put(main->mlx.ptr, main->mlx.win, WINDOW_W - 120, WINDOW_H - 150, COLOR_TUNDORA, ft_itoa((int)main->ply.pos_x));
	mlx_string_put(main->mlx.ptr, main->mlx.win, WINDOW_W - 100, WINDOW_H - 150, COLOR_TUNDORA, "x:");
	mlx_string_put(main->mlx.ptr, main->mlx.win, WINDOW_W - 80, WINDOW_H - 150, COLOR_TUNDORA, ft_itoa((int)main->ply.pos_y));
	// mlx_string_put(main->mlx.ptr, main->mlx.win, WINDOW_W - 80,
		// WINDOW_H - 20 - 100, COLOR_TUNDORA, ft_itoa(main->key.value));
}

int	ft_loop(t_main *main)
{
	update_player_all(main);
	draw_with_ray_casting(main);
	draw_text_on_window(main);// txt put to window
	// printf("player x[%f] y[%f]", main->ply.pos_x, main->ply.pos_y);
	// printf("ply.rotation_angle[%f]\n", main->ply.rotation_angle);
	return (0);
}

int	draw_mlx_window(t_main *main)
{

	mlx_loop_hook(main->mlx.ptr, ft_loop, main);
	mlx_hook(main->mlx.win, 2, 1L<<0, &key_press, main);
	mlx_hook(main->mlx.win, 3, 1L<<1, &key_release, main);
	mlx_hook(main->mlx.win, 17, (0L), &ft_exit, main);
	mlx_loop(main->mlx.ptr);
	return (0);
}