/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:50:02 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/23 02:43:37 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>

t_pixel		julia_pixel(int x, int y, t_viewport *v, t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int			i;

	(void)mlx;
	z = screen_to_complex(x, y, v);
	c = v->mouse;
	i = 0;
	while (z.r * z.r + z.i * z.i < (1 << 8) && i < v->max)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = v->max;
			break ;
		}
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	return ((t_pixel){.c = z, .i = i});
}

void		julia_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
}
