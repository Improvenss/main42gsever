/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:25:25 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/29 14:02:09 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol(int argc, char *argv[])
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

int	fractol_loop(t_fractol *frctl)
{
	size_t	x;
	size_t	y;

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
	mlx_put_image_to_window(frctl->mlx->ptr, frctl->mlx->win,
		frctl->mlx->img.ptr, 0, 0);
	return (0);
}
