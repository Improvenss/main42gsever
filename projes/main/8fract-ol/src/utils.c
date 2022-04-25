/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:36:28 by tjensen           #+#    #+#             */
/*   Updated: 2022/02/01 10:14:11 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	complex_set(t_complex *z, double re, double im)
{
	z->re = re;
	z->im = im;
}

void	my_mlx_pixel_put(t_mlximg *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	print_help(void)
{
	ft_printf("Unfortunately your input is not valid.\n");
	ft_printf("Please use one of the following parameters: ");
	ft_printf("[mandelbrot, julia, celtic_mandelbrot, burning_ship]\n");
	ft_printf("Sample usage: ./fractol mandelbrot\n");
}
