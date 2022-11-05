/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_trace_light_pdf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:54:56 by tjensen           #+#    #+#             */
/*   Updated: 2022/06/09 14:54:56 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt_trace.h"

double	pdf_sphere(t_list *light, t_hit *hit)
{
	t_sphere	*sp;
	t_vec3		light_dir;
	double		cos_theta_max;
	double		solid_angle;

	sp = &(light_cont(light)->linked_c_obj->sp);
	light_dir = vec3_sub(sp->pos, hit->p);
	cos_theta_max = sqrt(1.0 - sp->radius * sp->radius
			/ vec3_dot(light_dir, light_dir));
	solid_angle = 2.0 * M_PI * (1.0 - cos_theta_max);
	return (1.0 / solid_angle);
}

double	pdf_disc(t_list *light, t_hit *hit)
{
	t_disc	*di;
	t_vec3	light_dir;
	double	cosine;
	double	length_squared;

	di = &(light_cont(light)->linked_c_obj->di);
	light_dir = vec3_sub(di->pos, hit->p);
	length_squared = vec3_dot(light_dir, light_dir);
	light_dir = vec3_norm(light_dir);
	cosine = fabs(vec3_dot(light_dir, di->dir));
	return (length_squared / (cosine * M_PI * di->radius * di->radius));
}

double	pdf_rectangle(t_list *light, t_hit *hit)
{
	t_rectangle	*rt;
	t_vec3		light_dir;
	double		cosine;
	double		length_squared;

	rt = &(light_cont(light)->linked_c_obj->rt);
	light_dir = vec3_sub(rt->pos, hit->p);
	length_squared = vec3_dot(light_dir, light_dir);
	light_dir = vec3_norm(light_dir);
	cosine = fabs(vec3_dot(light_dir, rt->dir));
	return (length_squared / (cosine * rt->width * rt->height));
}
