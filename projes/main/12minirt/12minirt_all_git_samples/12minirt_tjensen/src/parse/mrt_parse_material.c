/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_material.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:56:44 by tjensen           #+#    #+#             */
/*   Updated: 2022/06/09 14:56:44 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt_parse.h"

static int	str_to_surfaces(const char *str, double surf[4], int line_num);

int	parse_material(t_material *material, char **split, int line_num)
{
	double	surf_sum;

	if (parse_color(split[0], &(material->color)))
		return (print_error_scene(line_num, ERR_PARSE, ERR_COLOR, NULL));
	if (str_to_surfaces(split[1], material->surface, line_num))
		return (-1);
	surf_sum = material->surface[DIFFUSE]
		+ material->surface[SPECULAR]
		+ material->surface[DIELECTRIC]
		+ material->surface[EMISSION];
	if (surf_sum != 1.0)
		return (print_error_scene(line_num, ERR_PARSE, ERR_SURF_SUM, NULL));
	if (double_from_str(split[2], 1, 2, &(material->fuzz))
		|| material->fuzz < 0.0 || material->fuzz > 9.99)
		return (print_error_scene(line_num, ERR_PARSE, ERR_FUZZ, NULL));
	if (double_from_str(split[3], 1, 2, &(material->refraction_index))
		|| (material->surface[DIELECTRIC] > 0.0
			&& (material->refraction_index < 1.0
				|| material->refraction_index > 2.0)))
		return (print_error_scene(line_num, ERR_PARSE, ERR_REFRACTION, NULL));
	material->brightness = 1.0;
	material->get_color = &obj_color;
	return (0);
}

static int	str_to_surfaces(const char *str, double surf[4], int line_num)
{
	int		error;
	char	**split_surf;

	error = false;
	split_surf = ft_split(str, ',');
	if (split_surf == NULL)
		return (print_error_scene(-1, ERR_PARSE, strerror(errno), NULL));
	if (ft_split_count_str(split_surf) != 3)
		error = -1;
	if (!error)
		error = double_from_str(split_surf[0], 1, 2, &(surf[DIFFUSE]));
	if (!error)
		error = double_from_str(split_surf[1], 1, 2, &(surf[SPECULAR]));
	if (!error)
		error = double_from_str(split_surf[2], 1, 2, &(surf[DIELECTRIC]));
	if (error
		|| surf[DIFFUSE] > 1.0 || surf[DIFFUSE] < 0.0
		|| surf[SPECULAR] > 1.0 || surf[SPECULAR] < 0.0
		|| surf[DIELECTRIC] > 1.0 || surf[DIELECTRIC] < 0.0)
		error = print_error_scene(line_num, ERR_PARSE, ERR_SURF, NULL);
	ft_free_split(&split_surf);
	return (error);
}
