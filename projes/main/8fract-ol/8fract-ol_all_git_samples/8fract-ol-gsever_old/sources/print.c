/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:35:26 by gsever            #+#    #+#             */
/*   Updated: 2022/05/26 12:44:18 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_help(void)
{
	ft_putendl_fd("Usage: ./fractol <name>", 1);
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("You can specify from 1 to 10 names of fractals", 1);
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("List of available fractals:", 1);
	ft_putendl_fd(" * Mandelbrot", 1);
	ft_putendl_fd(" * Julia", 1);
	ft_putendl_fd(" * Burning Ship", 1);
	ft_putendl_fd(" * Mandelbar", 1);
	ft_putendl_fd(" * Celtic Mandelbrot", 1);
	ft_putendl_fd(" * Celtic Mandelbar", 1);
	ft_putendl_fd(" * Celtic Perpendicular", 1);
	ft_putendl_fd(" * Perpendicular Mandelbrot", 1);
	ft_putendl_fd(" * Perpendicular Burning Ship", 1);
	ft_putendl_fd(" * Perpendicular Buffalo", 1);
}
