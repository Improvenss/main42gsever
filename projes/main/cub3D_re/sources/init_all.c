/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:45:58 by gsever            #+#    #+#             */
/*   Updated: 2023/01/12 14:12:12 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	init_mlx_draw(t_main *main)
{
	init_set_player(main, 0, 0);
	main->ply.walk_speed = PLAYER_WALK_SPEED;
	// main->key.left = false;
	// main->key.right = false;
	// main->key.up = false;
	// main->key.down = false;
	// main->key.r_left = false;
	// main->key.r_right = false;
	return (0);
}

// int	init_mlx_hooking(t_main *main)
// {

// 	mlx_loop_hook(main->mlx.ptr, ft_loop, main);
// 	mlx_hook(main->mlx.win, 2, 1L<<0, &key_press, main);
// 	mlx_hook(main->mlx.win, 3, 1L<<1, &key_release, main);
// 	mlx_hook(main->mlx.win, 17, (0L), &ft_exit, main);
// 	mlx_loop(main->mlx.ptr);
// 	return (0);

// 	// // ft_putstr_fd(B_CYAN"hooking() girildi \n"END, 1);
// 	// mlx_hook(main->mlx.win, 2, 1L << 0, &key_press, main);
// 	// ft_putstr_fd(B_CYAN"mlx_hook key_press OK\n"END, 1);
// 	// mlx_hook(main->mlx.win, 3, 1L << 1, &key_release, main);
// 	// // mlx_hook(mlx->win, 4, 0, &actions_mouse, main);
// 	// mlx_hook(main->mlx.win, 17, 0, &mlx_free_kill_all, main);// close_window(); yapilacak
// 	// return (0);
// }

static int	init_minimap_image(t_main *main)
{
	main->mini_map.ptr = mlx_new_image(main->mlx.ptr, BOX_SIZE * (main->map.max_x+1), BOX_SIZE * (main->map.max_y+1));
	if (main->mini_map.ptr == NULL)
		return (print_error(PROMPT, "minimap", "mlx_new_image()", "error."));
	main->mini_map.addr = (int *)mlx_get_data_addr(main->mini_map.ptr, &main->mini_map.bpp,
			&main->mini_map.line_size, &main->mini_map.endian);
	if (main->mini_map.addr == NULL)
		return (print_error(PROMPT, "minimap",
			"mlx_get_data_addr()", "error."));
	return (0);
}

static int	init_minimap(t_main *main)
{
	// if ((MINIMAP_RATE_H / main->map.max_y)
	// 	> (MINIMAP_RATE_W / main->map.max_x))
	// 	main->minimap.box_size = MINIMAP_RATE_W / main->map.max_x;
	// else
	// 	main->minimap.box_size = MINIMAP_RATE_H / main->map.max_y;
	if (init_minimap_image(main) == ERROR)// image init area
		return (ERROR);
	return (0);
}

static int	init_cub3d_image(t_main *main)
{
	main->screen.ptr = mlx_new_image(main->mlx.ptr, (int)(WINDOW_W), (int)(WINDOW_H));
	if (main->screen.ptr == NULL)
	{
		mlx_destroy_window(main->mlx.ptr, main->mlx.win);
		linux_mlx_free(main);
		return (print_error(PROMPT, "mlx", "mlx_new_image()", "error."));
	}
	main->screen.addr = (int *)mlx_get_data_addr(main->screen.ptr, &main->screen.bpp,
			&main->screen.line_size, &main->screen.endian);
	if (main->screen.addr == NULL)
		return (print_error(PROMPT, "mlx", "mlx_get_data_addr()", "error."));
	return (0);
}

static int	init_cub3d_window(t_main *main)
{
	main->mlx.win = mlx_new_window(main->mlx.ptr, WINDOW_W, WINDOW_H, PROMPT);
	if (main->mlx.win == NULL)
	{
		linux_mlx_free(main);
		return (print_error(PROMPT, "mlx", "mlx_new_window()", "error."));
	}
	return (0);
}

static int	init_cub3d(t_main *main)
{
	main->mlx.ptr = mlx_init();
	if (main->mlx.ptr == NULL)
		return (print_error(PROMPT, "mlx", "mlx_init()", "error."));
	if (init_cub3d_window(main) == ERROR)// window init area
		return (ERROR);
	if (init_cub3d_image(main) == ERROR)// image init area (screen)
		return (ERROR);
	return (0);
}

int	init_all(t_main *main)
{
	if (init_cub3d(main) == ERROR)// malloc init area
		return (ERROR);
	if (init_minimap(main) == ERROR)// image init area
		return (ERROR);
	if (init_mlx_draw(main) == ERROR)// ply_location...
		return (ERROR);
	// if (init_mlx_hooking(main) == ERROR)// key, mouse, click hooking area
	// 	return (ERROR);
	return (0);
}