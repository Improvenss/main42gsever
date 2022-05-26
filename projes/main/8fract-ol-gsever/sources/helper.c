/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:36:31 by gsever            #+#    #+#             */
/*   Updated: 2022/05/26 16:05:43 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_defaults(t_fractol *frctl)
{
	frctl->max_iter = 50;
	frctl->is_fixed = true;
	if(SIZE_X == SIZE_Y)
	{
		complex_set(&frctl->c_max, 2, 2);
		complex_set(&frctl->c_min, -2, -2);
	}
	else
	{
		complex_set(&frctl->c_min, -2, -2);
		frctl->c_max.im = 2;
		frctl->c_max.re = (SIZE_X / SIZE_Y * (frctl->c_max.im)
	}
}

int	fractol_free_kill_all(t_fractol *frctl)
{
	if(frctl->mlx != NULL)
	{
		mlx_destroy_window(frctl->mlx->ptr, frctl->mlx->win);
		mlx_destroy_image(frctl->mlx->ptr, frctl->mlx->img.ptr);
		free(frctl->mlx);
	}
	free(frctl->color_scheme);
	free(frctl);
	exit(EXIT_SUCCESS);
}

/*
	initialization --> init -> baslatma
	Fractal starting here.
*/
int	frctl_init(int argc, char **argv)
{
	t_fractol	*frctl;

	frctl = malloc(sizeof(t_fractol));
	if(frctl == NULL)
		return (NULL);
	frctl->color_scheme = malloc((5000 + 1) * sizeof(int));
	if(frctl->color_scheme == NULL)
		fractol_free_kill_all(frctl);
	frctl->mlx = NULL;
	frctl->color_shift = 0;
	set_defaults(frctl);
}