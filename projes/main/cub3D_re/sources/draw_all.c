/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:18:29 by gsever            #+#    #+#             */
/*   Updated: 2023/01/12 00:02:25 by gsever           ###   ########.fr       */
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
		j = -1;
		while (++j < BOX_SIZE)
		{
			mini_map->addr[(int)((BOX_SIZE * (main->map.max_x+1)) * (y + i) + (x + j))] = color;
			//mini_map->addr[(int)(WINDOW_W * (y + i) + (x + j))] = color;
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

void	draw_minimap_test(t_main *main)// yenisi
{
	int	x;
	int y;
int color = 255*(main->texture.rgb_c[0] * 65536) + (main->texture.rgb_c[1] * 256) + main->texture.rgb_c[2];

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
				put_pixel(BOX_SIZE * x, BOX_SIZE * y, color, &(main->mini_map), main);
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

void	draw_with_ray_casting(t_main *main)
{
	// sent_ray(main);
	draw_background(main);
	draw_player_test(main);
	mlx_put_image_to_window(main->mlx.ptr, main->mlx.win,
		main->screen.ptr, 0, 0);
	mlx_put_image_to_window(main->mlx.ptr, main->mlx.win,
		main->mini_map.ptr, 0, 0);
}

void	draw_text_on_window(t_main *main)
{
	mlx_string_put(main->mlx.ptr, main->mlx.win,
		WINDOW_W - 80, WINDOW_H - 20, COLOR_TUNDORA, "H - Help");// Burasi H tusuna bastigimizda help ekrani acilacak. onun icin. Belki bunu ayarlar icin sekme flaan da yapabilirisz simdilik boyle dusundum.
	// mlx_string_put(main->mlx.ptr, main->mlx.win, WINDOW_W - 80,
		// WINDOW_H - 20 - 100, COLOR_TUNDORA, ft_itoa(main->key.value));
}

int	ft_loop(t_main *main)
{
	key_function(main);// update_player_all(main);
	// printf("line: %d\n", __LINE__);
	draw_with_ray_casting(main);
	draw_text_on_window(main);// txt put to window
	// printf("player x[%f] y[%f]", main->ply.pos_x, main->ply.pos_y);
	// printf("ply.angle[%f]\n", main->ply.angle);
	return (0);
}

int	draw_mlx_window(t_main *main)
{
	// ft_putstr_fd("loop started\n", 1);
	mlx_loop_hook(main->mlx.ptr, ft_loop, main);
	mlx_hook(main->mlx.win, 2, 1L << 0, &key_press, main);
	mlx_hook(main->mlx.win, 3, 1L << 1, &key_release, main);
	// mlx_hook(mlx->win, 4, 0, &actions_mouse, main);
	mlx_hook(main->mlx.win, 17, 0, &ft_exit, main);// close_window(); yapilacak
	mlx_loop(main->mlx.ptr);
	return (0);
}