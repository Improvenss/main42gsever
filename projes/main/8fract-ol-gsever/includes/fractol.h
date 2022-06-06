/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:09:34 by gsever            #+#    #+#             */
/*   Updated: 2022/06/06 18:04:25 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>
# include <math.h>
//for; size_t, EXIT_SUCCESS
# include <stdlib.h>
//for; bool
# include <stdbool.h>
//for; printf
# include <stdio.h>
//for; u_long u_int
# include <sys/types.h>
//for; MinilibX
# include "../libraries/minilibx_opengl/mlx.h"
# include "key_macos_en.h"
//for; Libft
# include "../libraries/libft/includes/libft.h"

# define SIZE_X 		800.0
# define SIZE_Y 		800.0

# define COLOR_SILVER	0xCCCCCC
# define COLOR_TUNDORA	0x444444
# define COLOR_BLACK	0x000000

typedef struct s_complex	t_complex;
typedef struct s_mlximg		t_mlximg;
typedef struct s_mlx		t_mlx;
typedef struct s_fractol	t_fractol;
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
/*
for;
	color_shift		-->	Color key.	-->	Renk degisimi -> R[255] G[255] B[255]
	color_scheme	--> Color combination.
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
	bool		is_help;
}	t_fractol;

/*
	Fract-ol starting here.
*/
int			fractol(int argc, char **argv);
t_fractol	*frctl_init(int argc, char **argv);
void		setup_mlx(t_fractol *frctl);
int			fractol_loop(t_fractol *frctl);
int			draw_fractal_while(t_fractol *frctl);


/*
	--FRACTALS--
*/
void		mandelbrot(t_fractol *frctl);
void		julia(t_fractol *frctl);
void		celtic_mandelbrot(t_fractol *frctl);
void		burning_ship(t_fractol *frctl);
void		multibrot_set(t_fractol *frctl);

/*
	KEY_ACTIONS
*/
int			key_actions(int key, t_fractol *frctl);
void		move(int key, t_fractol *frctl);
void		fractal_change(int key, t_fractol *frctl);
void		color_shift(t_fractol *frctl);
void		change_maxiter(int key, t_fractol *frctl);
void		draw_help(t_fractol *frctl);

/*
	MOUSE_ACTIONS_C
*/
int			zoom(int button, int x, int y, t_fractol *frctl);
int			julia_mouse_motion(int x, int y, t_fractol *frctl);

/*
	COLOR_C
*/
int			get_color(t_fractol *frctl);
void		set_color_array(t_fractol *frctl);

/*
	UTILS_C
*/
void		complex_set(t_complex *z, double re, double im);
void		my_mlx_pixel_put(t_mlximg *img, int x, int y, int color);
void		print_help(void);
void		help(t_fractol *frctl);


/*
	UTILS_P2_C
*/
long		ft_atol(const char *nptr);
int			ft_iterative_power(int nb, int power);
double		ft_atod(const char *nptr);
int			ft_get_unumlen(u_long nb);
int			ft_get_unumlen_base(u_long n, u_int base);

/*
	FREE_C
*/
void		set_input(int argc, char *argv[], t_fractol *frctl);
int			set_defaults(t_fractol *frctl);
int			fractol_free_kill_all(t_fractol *frctl);
void		setup_mlx(t_fractol *frctl);

/*
	Samples --> Ornekler
*/
void	color_map(t_fractol *frctl, int w, int h);

# endif