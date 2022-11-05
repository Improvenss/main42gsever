/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_graphic_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:55:47 by tjensen           #+#    #+#             */
/*   Updated: 2022/06/09 14:55:47 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt_graphic.h"

void	move(t_scene *scene, t_vec3 new_pos)
{
	scene->cam.pos = new_pos;
	scene->img.pos = vec3_add(vec3_add(scene->cam.pos, scene->cam.dir),
			vec3_add(scene->img.qx, scene->img.qy));
	reset_sampling(scene);
}

void	reset_cam(t_scene *scene)
{
	scene->cam.pos = scene->cam.pos_initial;
	scene->cam.dir = scene->cam.dir_initial;
	scene_calc_img_pos(scene);
	reset_sampling(scene);
}

void	reset_sampling(t_scene *scene)
{
	scene->sampling.samp = 0;
	ft_bzero(scene->img.pixel, scene->img.width
		* scene->img.height * sizeof(t_color));
}
