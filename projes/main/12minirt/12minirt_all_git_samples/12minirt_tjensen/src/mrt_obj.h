/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_obj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:54:33 by tjensen           #+#    #+#             */
/*   Updated: 2022/11/05 04:30:43 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_OBJ_H
# define MRT_OBJ_H

/* ************************************************************************** */
/* INCLUDES																	  */
/* ************************************************************************** */

# include "../lib/libft/inc/libft.h"
# include "mrt_color.h"
# include "mrt_vec3.h"
# include "trace/mrt_trace.h"
# include "../lib/libmlx/include/MLX42/MLX42.h"

/* ************************************************************************** */
/* DEFINES																	  */
/* ************************************************************************** */

# define DIFFUSE		0
# define SPECULAR		1
# define DIELECTRIC		2
# define EMISSION		3

# define DIFFUSE_LIGHT	4
# define DIFFUSE_COSINE	5

/* ************************************************************************** */
/* STRUCTS																	  */
/* ************************************************************************** */

typedef struct s_hit	t_hit;

typedef t_color			(*t_f_color)(t_list *obj, t_hit *hit);

typedef struct s_texture
{
	char	*name;
	size_t	width;
	size_t	height;
	t_color	*color;
}	t_texture;

typedef struct s_material
{
	t_color			color;
	t_texture		*c_texture;
	t_f_color		get_color;
	int				cb_factor;
	double			surface[4];
	double			fuzz;
	double			refraction_index;
	double			brightness;
}	t_material;

typedef struct s_plane
{
	t_vec3		pos;
	t_vec3		dir;
}	t_plane;

typedef struct s_disc
{
	t_vec3		pos;
	t_vec3		dir;
	double		radius;
}	t_disc;

typedef struct s_sphere
{
	t_vec3		pos;
	t_vec3		rot;
	double		radius;
}	t_sphere;

typedef struct s_tube
{
	t_vec3		pos;
	t_vec3		dir;
	double		radius;
	double		height;
}	t_tube;

typedef struct s_rectangle
{
	t_vec3		pos;
	t_vec3		dir;
	double		width;
	double		height;
	t_vec3		rot;
	t_vec3		rel_pos;
}	t_rectangle;

typedef struct s_ray	t_ray;
typedef struct s_hit	t_hit;

typedef void			(*t_f_print)(t_list *obj);
typedef double			(*t_f_intersect)(t_list *obj, t_ray *ray, double t_min,
	double t_max);
typedef t_vec3			(*t_f_normal)(t_list *obj, t_hit *hit);

typedef struct s_obj
{
	t_material		material;
	t_f_print		print;
	t_f_intersect	intersect;
	t_f_normal		normal;
	union
	{
		t_plane		pl;
		t_disc		di;
		t_sphere	sp;
		t_tube		tb;
		t_rectangle	rt;
	};
}	t_obj;

/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

// OBJECTS
t_list		*obj_new(void);
int			obj_type(t_list *obj);
t_obj		*obj_cont(t_list *obj);
t_color		obj_color(t_list *obj, t_hit *hit __attribute__((unused)));

t_texture	*texture_cont(t_list *texture);
t_list		*texture_new(void);
void		c_texture_destroy(void *in);

t_texture	*obj_c_texture(t_list *obj);
t_material	*obj_material(t_list *obj);

t_color		checkerboard_sphere(t_list *obj, t_hit *hit);
t_color		texture_sphere(t_list *obj, t_hit *hit);

t_color		texture_rectangle_x(t_list *obj, t_hit *hit);
t_color		texture_rectangle_y(t_list *obj, t_hit *hit);
t_color		texture_rectangle_z(t_list *obj, t_hit *hit);
t_color		checkerboard_rectangle(t_list *obj, t_hit *hit);

#endif // MRT_OBJ_H
