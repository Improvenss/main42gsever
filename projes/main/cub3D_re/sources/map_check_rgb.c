/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:26:09 by gsever            #+#    #+#             */
/*   Updated: 2022/12/05 11:52:58 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_definitions_rgb_c(t_main *main)
{
	int	i;
	int	l;
	int	count;

	i = 0;
	l = 0;
	count = 0;
	while (main->texture.c[i] && count < 3)
	{
		if (main->texture.c[i] == ',' || main->texture.c[i + 1] == '\0')
		{
			main->map.l_free = ft_substr(main->texture.c, l, i);
			main->texture.rgb_c[count++] = ft_atoi(main->map.l_free);
			free(main->map.l_free);
			if (main->texture.rgb_c[count - 1] > 255)
				return (ERROR);
			//printf("#%d#\n", main->texture.rgb_c[count - 1]);
			l = i + 1;
		}
		i++;
	}
	if (main->texture.c[i] != '\0' || count != 3)
		return (ERROR);
	return (0);
}

int	map_definitions_rgb_f(t_main *main)
{
	int	i;
	int	l;
	int	count;

	i = 0;
	l = 0;
	count = 0;
	while (main->texture.f[i] && count < 3)
	{
		if (main->texture.f[i] == ',' || main->texture.f[i + 1] == '\0')
		{
			main->map.l_free = ft_substr(main->texture.f, l, i);
			main->texture.rgb_f[count++] = ft_atoi(main->map.l_free);
			free(main->map.l_free);
			if (main->texture.rgb_f[count - 1] > 255)
				return (ERROR);
			// printf("#%d#\n", main->texture.rgb_f[count - 1]);
			l = i + 1;
		}
		i++;
	}
	if (main->texture.f[i] != '\0' || count != 3)
		return (ERROR);
	return (0);
}

int	map_definitions_rgb(t_main *main)
{
	if (map_definitions_rgb_f(main) == ERROR)
	{
		free(main->texture.rgb_f);
		free(main->texture.rgb_c);
		return (print_error(PROMPT, NULL, NULL, RED ERR_MAP_F END));
	}

	if (map_definitions_rgb_c(main) == ERROR)
	{
		free(main->texture.rgb_f);
		free(main->texture.rgb_c);
		return (print_error(PROMPT, NULL, NULL, RED ERR_MAP_C END));
	}
	return (0);
}

int	map_definitions_check_rgb(t_main *main)
{
	int		i;

	i = 0;
	while (main->texture.f[i] && ft_strchr(RGB_CHR, main->texture.f[i]))
		i++;
	if (main->texture.f[i] != '\0')
		return (print_error(PROMPT, NULL, NULL, RED ERR_MAP_F END));
	i = 0;
	while (main->texture.c[i] && ft_strchr(RGB_CHR, main->texture.c[i]))
		i++;
	if (main->texture.c[i] != '\0')
		return (print_error(PROMPT, NULL, NULL, RED ERR_MAP_C END));
	main->texture.rgb_f = (int *)malloc(sizeof(int) * 3);
	if (!main->texture.rgb_f)
		return (print_error(PROMPT, NULL, NULL, strerror(errno)));
	main->texture.rgb_c = (int *)malloc(sizeof(int) * 3);
	if (!main->texture.rgb_c)
	{
		free(main->texture.rgb_f);
		return (print_error(PROMPT, NULL, NULL, strerror(errno)));
	}
	return (map_definitions_rgb(main));
}