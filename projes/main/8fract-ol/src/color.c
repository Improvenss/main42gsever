/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:21:56 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/29 13:53:26 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calc_color(t_fractol *frctl, size_t i);

int	get_color(t_fractol *frctl)
{
	return (frctl->color_scheme[frctl->iter]);
}

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
