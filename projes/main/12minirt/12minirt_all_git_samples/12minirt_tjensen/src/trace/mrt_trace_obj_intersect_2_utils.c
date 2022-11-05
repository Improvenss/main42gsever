/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_trace_obj_intersect_2_utils.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:55:30 by tjensen           #+#    #+#             */
/*   Updated: 2022/06/09 14:55:31 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt_trace.h"

static void	rotate_ray_x(t_ray *ray, double rot_x);
static void	rotate_ray_y(t_ray *ray, double rot_y);
static void	rotate_ray_z(t_ray *ray, double rot_z);

void	intersect_rectangle_move_rotate_ray(t_ray *ray, t_list *obj)
{
	ray->pos = vec3_sub(ray->pos, obj_cont(obj)->rt.pos);
	if (obj_cont(obj)->rt.rot.z != 0.0)
		rotate_ray_z(ray, obj_cont(obj)->rt.rot.z);
	if (obj_cont(obj)->rt.rot.y != 0.0)
		rotate_ray_y(ray, obj_cont(obj)->rt.rot.y);
	if (obj_cont(obj)->rt.rot.x != 0.0)
		rotate_ray_x(ray, obj_cont(obj)->rt.rot.x);
	ray->pos = vec3_sub(ray->pos, obj_cont(obj)->rt.rel_pos);
}

static void	rotate_ray_x(t_ray *ray, double rot_x)
{
	double	sine;
	double	cosine;
	double	tmp;

	sine = sin(rot_x * (M_PI / 180.0));
	cosine = cos(rot_x * (M_PI / 180.0));
	tmp = cosine * ray->pos.y - sine * ray->pos.z;
	ray->pos.z = sine * ray->pos.y + cosine * ray->pos.z;
	ray->pos.y = tmp;
	tmp = cosine * ray->dir.y - sine * ray->dir.z;
	ray->dir.z = sine * ray->dir.y + cosine * ray->dir.z;
	ray->dir.y = tmp;
}

static void	rotate_ray_y(t_ray *ray, double rot_y)
{
	double	sine;
	double	cosine;
	double	tmp;

	sine = sin(rot_y * (M_PI / 180.0));
	cosine = cos(rot_y * (M_PI / 180.0));
	tmp = cosine * ray->pos.x + sine * ray->pos.z;
	ray->pos.z = -sine * ray->pos.x + cosine * ray->pos.z;
	ray->pos.x = tmp;
	tmp = cosine * ray->dir.x + sine * ray->dir.z;
	ray->dir.z = -sine * ray->dir.x + cosine * ray->dir.z;
	ray->dir.x = tmp;
}

static void	rotate_ray_z(t_ray *ray, double rot_z)
{
	double	sine;
	double	cosine;
	double	tmp;

	sine = sin(rot_z * (M_PI / 180.0));
	cosine = cos(rot_z * (M_PI / 180.0));
	tmp = cosine * ray->pos.x - sine * ray->pos.y;
	ray->pos.y = sine * ray->pos.x + cosine * ray->pos.y;
	ray->pos.x = tmp;
	tmp = cosine * ray->dir.x - sine * ray->dir.y;
	ray->dir.y = sine * ray->dir.x + cosine * ray->dir.y;
	ray->dir.x = tmp;
}
