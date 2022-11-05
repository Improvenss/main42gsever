/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_trace_light_random.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:54:58 by tjensen           #+#    #+#             */
/*   Updated: 2022/06/09 14:54:59 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt_trace.h"
#include "mrt_trace_onb.h"

static inline t_vec3	random_to_sphere(double radius, double dist_squared);

t_vec3	random_dir_to_sphere(t_list *light, t_hit *hit)
{
	t_obj	*c_obj;
	t_onb	uvw;
	t_vec3	light_dir;
	double	dist_squared;

	c_obj = light_cont(light)->linked_c_obj;
	light_dir = vec3_sub(c_obj->sp.pos, hit->p);
	dist_squared = vec3_dot(light_dir, light_dir);
	uvw = onb_build(vec3_norm(light_dir));
	return (onb_transform(uvw,
			random_to_sphere(c_obj->sp.radius, dist_squared)));
}

static inline t_vec3	random_to_sphere(double radius, double dist_squared)
{
	t_vec3	vec3;
	double	r1;
	double	r2;
	double	phi;

	r1 = ft_rand();
	r2 = ft_rand();
	vec3.z = 1.0 + r2 * (sqrt(1.0 - radius * radius / dist_squared) - 1.0);
	phi = 2.0 * M_PI * r1;
	vec3.x = cos(phi) * sqrt(1.0 - vec3.z * vec3.z);
	vec3.y = sin(phi) * sqrt(1.0 - vec3.z * vec3.z);
	return (vec3);
}

t_vec3	random_dir_to_disc(t_list *light, t_hit *hit)
{
	t_obj	*c_obj;
	t_onb	uvw;
	t_vec3	rand_point;
	double	r1;
	double	r2;

	c_obj = light_cont(light)->linked_c_obj;
	uvw = onb_build(c_obj->di.dir);
	while (1)
	{
		r1 = ft_rand_range(-(c_obj->di.radius), c_obj->di.radius);
		r2 = ft_rand_range(-(c_obj->di.radius), c_obj->di.radius);
		if (r1 * r1 + r2 * r2 <= c_obj->di.radius * c_obj->di.radius)
			break ;
	}
	rand_point = vec3_add(c_obj->di.pos, vec3_lin_comb(r1, uvw.u, r2, uvw.v));
	return (vec3_norm(vec3_sub(rand_point, hit->p)));
}

t_vec3	random_dir_to_rectangle(t_list *light, t_hit *hit)
{
	t_obj	*c_obj;
	t_vec3	rand_point;
	double	r1;
	double	r2;

	c_obj = light_cont(light)->linked_c_obj;
	r1 = ft_rand_range(c_obj->rt.width / -2.0, c_obj->rt.width / 2.0);
	r2 = ft_rand_range(c_obj->rt.height / -2.0, c_obj->rt.height / 2.0);
	if (fabs(c_obj->rt.dir.x) > 0.9)
		rand_point = vec3_add(c_obj->rt.pos, (t_vec3){0.0, r1, r2});
	else if (fabs(c_obj->rt.dir.y) > 0.9)
		rand_point = vec3_add(c_obj->rt.pos, (t_vec3){r1, 0.0, r2});
	else
		rand_point = vec3_add(c_obj->rt.pos, (t_vec3){r1, r2, 0.0});
	return (vec3_norm(vec3_sub(rand_point, hit->p)));
}
