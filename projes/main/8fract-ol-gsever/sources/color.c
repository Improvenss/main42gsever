/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:23:05 by gsever            #+#    #+#             */
/*   Updated: 2022/06/01 22:38:53 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
	Iter sayisi kacsa ona gore renklendirme oluyor.
	Getting color's iteration from frctl's iter.
*/
int	get_color(t_fractol *frctl)
{
	return (frctl->color_scheme[frctl->iter]);
}

/*
	uint8_t	---> 8 byte unsigned type (char) 
				--> stdint.h -> 8 bit = 1 byte => 0 - 255
	size_t --> unsigned int
	pow()	---> x^y = pow(x, y) --> 2^3 = pow(2, 3) = 2x2x2 = 8
	
	cs	= 0 between 255 can allowing.
	div	=> division -->  ̶B̶o̶l̶e̶n̶ B̶o̶l̶u̶n̶e̶n̶ >Bolum< K̶a̶l̶a̶n̶
	
*/
/*
	Doing; Calculating color.
*/
static int	calc_color(t_fractol *frctl, size_t i)
{
	uint8_t	cs;
	uint8_t	rgb[3];
	double	div;

	cs = frctl->color_shift;
	div = (double)i / frctl->max_iter;
	if (frctl->color_shift < 3)
	{
		rgb[cs % 3] = 9 * (1 - div) * pow(div, 3) * 255;
		rgb[(cs + 1) % 3] = 15 * pow((1 - div), 2) * pow(div, 2) * 255;
		rgb[(cs + 2) % 3] = 9 * pow((1 - div), 3) * div * 255;
	}
	else
	{
		cs -= 3;
		rgb[cs % 3] = 9 * pow((1 - div), 3) * div * 255;
		rgb[(cs + 1) % 3] = 15 * pow((1 - div), 2) * pow(div, 2) * 255;
		rgb[(cs + 2) % 3] = 9 * (1 - div) * pow(div, 3) * 255;
	}
	return (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

/*
	Setting color's to array.
*/
void	set_color_array(t_fractol *frctl)
{
	size_t	i;

	i = 0;
	while (i <= frctl->max_iter)
	{
		frctl->color_scheme[i] = calc_color(frctl, i);
		i++;
	}
}
