/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_print_obj_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:57:23 by tjensen           #+#    #+#             */
/*   Updated: 2022/06/09 14:57:23 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt_print.h"

void	print_obj_sphere(t_list *obj)
{
	t_obj	*c_obj;

	c_obj = obj_cont(obj);
	printf("SPHERE: (%p)\n", c_obj);
	print_vec3(c_obj->sp.pos, "pos:", COLOR_BL);
	print_scene_double(c_obj->sp.radius, "radius:", COLOR_NO);
	print_vec3(c_obj->sp.rot, "rot:", COLOR_NO);
	print_material(&(c_obj->material));
	printf("\n");
}
