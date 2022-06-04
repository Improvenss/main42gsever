/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:36:31 by gsever            #+#    #+#             */
/*   Updated: 2022/06/04 00:22:49 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
	When we enter terminal argument; working here.
*/
void	set_input(int argc, char *argv[], t_fractol *frctl)
{
	frctl->fractal_func = NULL;
	if ((argc == 2 || argc == 4) && !ft_strncmp(argv[1], "julia", 6))
	{
		frctl->fractal_func = julia;
		if (argc == 4)
		{
			frctl->c_julia.re = ft_atod(argv[2]);
			frctl->c_julia.im = ft_atod(argv[3]);
		}
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		frctl->fractal_func = mandelbrot;
	else if (argc == 2 && !ft_strncmp(argv[1], "celtic_mandelbrot", 9))
		frctl->fractal_func = celtic_mandelbrot;
	else if (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 9))
		frctl->fractal_func = burning_ship;
	else
		print_help();
	if (frctl->fractal_func == NULL)
		fractol_free_kill_all(frctl);
}

void	setup_mlx(t_fractol *frctl)
{
	t_mlx	*mlx;

	frctl->mlx = malloc(sizeof(t_mlx));
	if (frctl->mlx == NULL)
		fractol_free_kill_all(frctl);
	mlx = frctl->mlx;
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		fractol_free_kill_all(frctl);
	mlx->win = mlx_new_window(mlx->ptr, SIZE_X, SIZE_Y, "fractol");
	if (mlx->win == NULL)
		fractol_free_kill_all(frctl);
	mlx->img.ptr = mlx_new_image(mlx->ptr, SIZE_X, SIZE_Y);
	if (mlx->img.ptr == NULL)
		fractol_free_kill_all(frctl);
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	if (mlx->img.addr == NULL)
		fractol_free_kill_all(frctl);
	mlx_hook(mlx->win, 2, 0, key_actions, frctl);
	mlx_hook(mlx->win, 4, 0, zoom, frctl);
	mlx_hook(mlx->win, 17, 0, fractol_free_kill_all, frctl);
	mlx_hook(mlx->win, 6, 0, julia_mouse_motion, frctl);
}

/*
		for; frctl's defaults values entering.
	SIZE_T and SIZE_Y for window's 1000x1000px image. px == pixel
	Hazir fractallarin varsayilan degerlerini ayarliyor.
	Sonra set_color_array() fonksiyonundan color hesaplattiriyor.
*/
int	set_defaults(t_fractol *frctl)
{
	frctl->max_iter = 25;
	frctl->is_fixed = true;
	if (SIZE_X == SIZE_Y)
	{
		complex_set(&frctl->c_max, 2, 2);
		complex_set(&frctl->c_min, -2, -2);
	}
	else
	{
		complex_set(&frctl->c_min, -2, -2);
		frctl->c_max.im = 2;
		frctl->c_max.re = (SIZE_X / SIZE_Y
				* (frctl->c_max.im - frctl->c_min.im)
				+ frctl->c_min.re);
	}
	complex_set(&frctl->c_julia, -0.6, 0.6);
	set_color_array(frctl);
	return (0);
}

/*
	Clearing all opened area in memory. :)
*/
int	fractol_free_kill_all(t_fractol *frctl)
{
	if (frctl->mlx != NULL)
	{
		mlx_destroy_window(frctl->mlx->ptr, frctl->mlx->win);
		mlx_destroy_image(frctl->mlx->ptr, frctl->mlx->img.ptr);
		free(frctl->mlx);
	}
	free(frctl->color_scheme);
	free(frctl);
	exit(EXIT_SUCCESS);
}

/*
	initialization --> init -> baslatma
	Fractal starting here.

	Fractal'a;
		color_scheme icin malloc'la yer actik,
		set_defaults'la standart girdiyi girdiriyoruz,
		set_input'la hangi kumeyi kullanacagiz onu giriyoruz.
*/
t_fractol	*frctl_init(int argc, char **argv)
{
	t_fractol	*frctl;

	frctl = malloc(sizeof(t_fractol));
	if (frctl == NULL)
		return (NULL);
	frctl->color_scheme = malloc((5000 + 1) * sizeof(int));
	if (frctl->color_scheme == NULL)
		fractol_free_kill_all(frctl);
	frctl->mlx = NULL;
	frctl->color_shift = 0;
	set_defaults(frctl);
	set_input(argc, argv, frctl);
	return (frctl);
}
