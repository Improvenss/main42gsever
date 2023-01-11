/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:11:08 by gsever            #+#    #+#             */
/*   Updated: 2022/12/05 11:53:47 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void free_definitions(t_main *main)
{
	if (main->texture.no != NULL)
		free(main->texture.no);
	if (main->texture.so != NULL)
		free(main->texture.so);
	if (main->texture.we != NULL)
		free(main->texture.we);
	if (main->texture.ea != NULL)
		free(main->texture.ea);
	if (main->texture.f != NULL)
		free(main->texture.f);
	if (main->texture.c != NULL)
		free(main->texture.c);
}
