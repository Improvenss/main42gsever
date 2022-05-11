/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:33:04 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/23 02:42:28 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

t_fractal	*get_fractals(void)
{
	static t_fractal array[8] = {
		{"mandelbrot", mandelbrot_viewport, mandelbrot_pixel, 0},
		{"julia", julia_viewport, julia_pixel, 1},
		{"burningship", burningship_viewport, burningship_pixel, 0},
		{NULL, NULL, NULL, 0}
	};

	return (array);
}

t_fractal	*fractal_match(char *str)
{
	t_fractal	*f;
	int			i;

	f = get_fractals();
	i = 0;
	while (f[i].name != NULL)
	{
		if (ft_strcmp(f[i].name, str) == 0)
			return (&f[i]);
		i++;
	}
	return (&f[i]);
}
