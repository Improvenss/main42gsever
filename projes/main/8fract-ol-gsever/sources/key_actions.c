/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:40:14 by gsever            #+#    #+#             */
/*   Updated: 2022/05/27 18:56:56 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_actions(int key, t_fractol *frctl)
{
	if (key == MAINP_ESC)
		fractol_free_kill_all(frctl);
	else if (key == MAINP_R)
		set_defaults(frctl);
	else if (key == ARROW_UP || key == ARROW_DOWN)
		move(key, frctl);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT)
		move(key, frctl);
	else if (key == MAINP_PLUS || key == NUMP_PLUS)
		change_maxiter(key, frctl);
	else if (key == MAINP_MINUS || key == NUMP_MINUS)
		change_maxiter(key, frctl);
	else if (key >= MAINP_1 && key <= MAINP_4)
		fractal_change(key, frctl);
	else if (key >= NUMP_1 && key <= NUMP_4)
		fractal_change(key, frctl);
	else if (key == MAINP_SPACE)
		frctl->is_fixed = !frctl->is_fixed;
	else if (key == MAINP_DOT)
		color_shift(frctl);
	fractol_loop(frctl);
	return (0);
}
