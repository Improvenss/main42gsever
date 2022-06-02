/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:01:28 by gsever            #+#    #+#             */
/*   Updated: 2022/06/02 17:51:00 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	complex_set(t_complex *z, double re, double im)
{
	z->re = re;
	z->im = im;
}

/*
	img'mize yazilmiz olan piksellerimizi --> img'yi window'a koyuyoruz.
*/
void	my_mlx_pixel_put(t_mlximg *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	help(t_fractol *frctl)
{
	frctl->is_help = !frctl->is_help;
	if (frctl->is_help)
	{
		frctl->iter = 1;
		frctl->fractal_func = draw_help;
	}
	else
	{
		set_defaults(frctl);
	}
}

void	draw_help(t_fractol *frctl)
{
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 460, 330, COLOR_SILVER,
		"Controls");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 385, 370, COLOR_SILVER,
		"Other Fractals		- 1, 2, 3, 4 and Color Scheme --> 9");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 385, 400, COLOR_SILVER,
		"Reset				- R");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 385, 430, COLOR_SILVER,
		"Color Shift		- C");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 385, 460, COLOR_SILVER,
		"Move				- Arrows");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 385, 490, COLOR_SILVER,
		"Zoom				- Mouse Scroll");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 385, 520, COLOR_SILVER,
		"Iterations			- +/-");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 385, 550, COLOR_SILVER,
		"Julia Constant		- Mouse");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 385, 580, COLOR_SILVER,
		"Mouse Lock			- Space");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 385, 610, COLOR_SILVER,
		"Close Help			- H");
}

void	print_help(void)
{
	printf("Unfortunately your input is not valid.\n");
	printf("Please use one of the following parameters: ");
	printf("[mandelbrot, julia, celtic_mandelbrot, burning_ship]\n");
	printf("Sample usage: ./fractol mandelbrot\n");
}
