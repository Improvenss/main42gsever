/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:01:28 by gsever            #+#    #+#             */
/*   Updated: 2022/06/05 16:12:49 by gsever           ###   ########.fr       */
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
	'offset'
	mlx_get_data_addr() funcionundan alinan satir uzunlugunu kullanarak 
		bellek offset'ini(noktadan noktaya olan uzaklik) hesaplamaliyiz.
*/
void	my_mlx_pixel_put(t_mlximg *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	draw_help(t_fractol *frctl)
{
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 350, 300, COLOR_SILVER,
		"Controls");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 300, 340, COLOR_SILVER,
		"Other Fractals   - 1, 2, 3, 4 and Color Scheme --> 9");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 300, 370, COLOR_SILVER,
		"Reset            - R");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 300, 400, COLOR_SILVER,
		"Color Shift      - C");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 300, 430, COLOR_SILVER,
		"Move             - Arrows");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 300, 460, COLOR_SILVER,
		"Zoom             - Mouse Scroll");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 300, 490, COLOR_SILVER,
		"Iterations       - +/-");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 300, 520, COLOR_SILVER,
		"Julia Constant   - Mouse");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 300, 550, COLOR_SILVER,
		"Mouse Lock       - Space");
	mlx_string_put(frctl->mlx->ptr, frctl->mlx->win, 300, 580, COLOR_SILVER,
		"Close Help       - H");
}

void	help(t_fractol *frctl)
{
	size_t	x;
	size_t	y;

	if (frctl->is_help)
	{
		y = 0;
		while (y < SIZE_Y)
		{
			x = 0;
			while (x < SIZE_X)
			{
				my_mlx_pixel_put(&frctl->mlx->img, x, y, COLOR_BLACK);
				x++;
			}
			y++;
		}
		mlx_put_image_to_window(frctl->mlx->ptr, frctl->mlx->win,
			frctl->mlx->img.ptr, 0, 0);
		draw_help(frctl);
		printf("Help Page Opened! :)\n");
	}
}

void	print_help(void)
{
	printf("Unfortunately your input is not valid.\n");
	printf("Please use one of the following parameters: ");
	printf("[mandelbrot, julia, celtic_mandelbrot, burning_ship]\n");
	printf("Sample usage: ./fractol mandelbrot\n");
}
