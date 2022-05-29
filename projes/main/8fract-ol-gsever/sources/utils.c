/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:01:28 by gsever            #+#    #+#             */
/*   Updated: 2022/05/29 15:45:40 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
