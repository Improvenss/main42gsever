/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:07:11 by gsever            #+#    #+#             */
/*   Updated: 2022/06/07 12:12:59 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	draw_fractal_while(t_fractol *frctl)
{
	size_t	x;
	size_t	y;

	if (frctl->is_help)
		return (0);
	frctl->scale.re = (frctl->c_max.re - frctl->c_min.re) / SIZE_X;
	frctl->scale.im = (frctl->c_max.im - frctl->c_min.im) / SIZE_Y;
	y = 0;
	while (y < SIZE_Y)
	{
		frctl->c.im = frctl->c_max.im - y * frctl->scale.im;
		x = 0;
		while (x < SIZE_X)
		{
			frctl->c.re = frctl->c_min.re + x * frctl->scale.re;
			frctl->fractal_func(frctl);
			my_mlx_pixel_put(&frctl->mlx->img, x, y, get_color(frctl));
			x++;
		}
		y++;
	}
	return (0);
}

int	fractol_loop(t_fractol *frctl)
{
	draw_fractal_while(frctl);
	mlx_put_image_to_window(frctl->mlx->ptr, frctl->mlx->win,
		frctl->mlx->img.ptr, 0, 0);
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 720, 780, COLOR_TUNDORA,
		"H - Help");
	if (frctl->is_help)
		help(frctl);
	return (0);
}

int	fractol(int argc, char **argv)
{
	t_fractol	*frctl;

	frctl = frctl_init(argc, argv);
	if (frctl == NULL)
		return (-1);
	setup_mlx(frctl);
	fractol_loop(frctl);
	mlx_loop(frctl->mlx->ptr);
	return (0);
}
