/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:59:34 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/27 12:08:17 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_macos_en.h"

int	zoom(int button, int x, int y, t_fractol *frctl)
{
	t_complex	pos;
	double		zoom;

	if (button == MOUSE_UP || button == MOUSE_DOWN)
	{
		pos.re = frctl->c_min.re + x * frctl->scale.re;
		pos.im = frctl->c_max.im - y * frctl->scale.im;
		if (button == MOUSE_UP)
			zoom = 1.2;
		else
			zoom = 0.8;
		frctl->c_min.re = pos.re + (frctl->c_min.re - pos.re) * zoom;
		frctl->c_max.re = pos.re + (frctl->c_max.re - pos.re) * zoom;
		frctl->c_min.im = pos.im + (frctl->c_min.im - pos.im) * zoom;
		frctl->c_max.im = pos.im + (frctl->c_max.im - pos.im) * zoom;
		fractol_loop(frctl);
	}
	return (0);
}

int	julia_mouse_motion(int x, int y, t_fractol *frctl)
{
	if (!frctl->is_fixed && (frctl->fractal_func == julia))
	{
		frctl->c_julia.re = 4 * ((double)x / SIZE_X - 0.5);
		frctl->c_julia.im = 4 * ((double)(SIZE_Y - y) / SIZE_Y - 0.5);
		fractol_loop(frctl);
	}
	return (0);
}
