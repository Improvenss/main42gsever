/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:09:34 by gsever            #+#    #+#             */
/*   Updated: 2022/05/26 16:44:35 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SIZE_X 1000.0
# define SIZE_Y 1000.0

//for; size_t
# include <stdlib.h>
//for; bool
# include <stdbool.h>
//for; EXIT_SUCCESS
# include <stdlib.h>
//for; MinilibX
# include "../libraries/minilibx_opengl/mlx.h"


typedef void				(*t_funcptr)(t_fractol *frctl);

/*
	Complex number
*/
/*
		re — real part
		im — imaginary part
	Bu 'struct' fraktal icin 2 tane deger girmemizi istiyor, o degerleri 
her parametre icin uretmis oluyoruz.
*/
typedef struct s_complex{
	double		re;
	double		im;
}	t_complex;

/*
	Image
*/
/*
	image			— image identifier
	addr			— image
	bits_per_pixel	— depth of image
	size_line		— number of bytes used to store one line of image
	endian			— little or big endian --> arab and eng keyboard types.
*/
typedef struct s_mlximg{
	void		*ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_mlximg;

typedef struct s_mlx{
	void		*ptr;
	void		*win;
	t_mlximg	img;
}	t_mlx;

/*
	Fract'ol
*/
typedef struct s_fractol{
	t_mlx		*mlx;
	t_complex	c;
	t_complex	c_julia;
	t_complex	c_max;
	t_complex	c_min;
	t_complex	scale;
	size_t		iter;
	size_t		max_iter;
	t_funcptr	fractal_func;
	uint8_t		color_shift;
	int			*color_scheme;
	bool		is_fixed;
}	t_fractol;

/*
	
*/
int	fractol(int argc, char **argv);


int	frctl_init(int argc, char **argv);

/*
	UTILS_C
*/

void	complex_set(t_complex *z, double re, double im);


# endif