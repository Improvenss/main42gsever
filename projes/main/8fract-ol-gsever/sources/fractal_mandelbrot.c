/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:35:00 by gsever            #+#    #+#             */
/*   Updated: 2022/06/06 18:10:22 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
	Keyboard --> 1
		https://en.wikipedia.org/wiki/Mandelbrot_set

			z = z^2 + c --> ! Formula !

			z = x + iy
			z^2= x^2 + i2xy - y^2
			c = x_0 + iy_0

			x = Re(z^2+c) = x^2 - y^2 + x_0 and y = Im(z^2 + c) = 2xy + y_0

	x0 = scaled x coordinate of pixel --> frctl->c.re -> real part
		(scaled to lie in the Mandelbrot X scale)
	y0 = scaled y coordinate of pixel --> frctl->c.im -> imaginart part
		(scaled to lie in the Mandelbrot Y scale)
	x = z.re; --> t_complex z; -> xtemp
	y = z.im;
	iteration		= frctl->iter
	max_iteration	= frctl->max_iter
	x*x = tmp.re; --> x^2
	y*y = tmp.im; --> y^2
*/
void	mandelbrot(t_fractol *frctl)
{
	t_complex	z;
	t_complex	tmp;

	z.re = frctl->c.re;
	z.im = frctl->c.im;
	tmp.re = z.re * z.re;
	tmp.im = z.im * z.im;
	frctl->iter = 0;
	while ((tmp.re + tmp.im <= 4) && frctl->iter < frctl->max_iter)
	{
		z.im = 2 * z.re * z.im + frctl->c.im;
		z.re = tmp.re - tmp.im + frctl->c.re;
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		frctl->iter++;
	}
}

/*
	Keyboard --> 5
*/
void	multibrot_set(t_fractol *frctl)
{
	t_complex	z;
	t_complex	tmp;

	z.re = frctl->c.re;
	z.im = frctl->c.im;
	tmp.re = z.re * z.re;
	tmp.im = z.im * z.im;
	frctl->iter = 0;
	while ((tmp.re + tmp.im <= 4) && frctl->iter < frctl->max_iter)
	{
		z.im = 3 * (z.re * z.re) * z.im - (tmp.im * z.im) + frctl->c.im;
		z.re = (tmp.re * z.re) - 3 * z.re * tmp.im + frctl->c.re;
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		frctl->iter++;
	}
}
