/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:35:00 by gsever            #+#    #+#             */
/*   Updated: 2022/06/05 23:05:39 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
	Keyboard --> 1
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
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		z.im = 3 * (z.re * z.re) * z.im - (tmp.im * z.im) + frctl->c.im;
		z.re = (tmp.re * z.re) - 3 * z.re * tmp.im + frctl->c.re;
		frctl->iter++;
	}
}
