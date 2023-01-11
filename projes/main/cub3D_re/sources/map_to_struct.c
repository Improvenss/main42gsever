/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:37:03 by gsever            #+#    #+#             */
/*   Updated: 2022/12/05 14:12:05 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief 
 * 			TOP
 * 		------------>
 *		^			|
 * LEFT	|			|  RIGHT
 *		|			|
 *		|<----------v
 * 		  BOTTOM			
 * 
 * @param main 
 * @return int 
 */
int	map_borders(t_main *main)
{
	// int write = 0;
	// printf("//----------MAP----------//\n");
	// while (main->map->map[write])
	// 	printf("#%s#\n",main->map[write++]);
	// printf("//----------MAP----------//\n");

	main->map.max_x = (ft_strlen(main->map.map[0]) - 1);
	main->map.max_y = 0;
	while (main->map.map[main->map.max_y])
		main->map.max_y++;
	main->map.max_y--;
	if (map_borders_top(main) == ERROR \
	|| map_borders_right(main) == ERROR \
	|| map_borders_bottom(main) == ERROR \
	|| map_borders_left(main) == ERROR \
	|| map_borders_inside(main) == ERROR)
	{
		free_pstr(main->map.map);
		free_definitions(main);
		free(main->texture.rgb_f);
		free(main->texture.rgb_c);
		return (ERROR);
	}
	return (0);
}

int map_max_lenght(char *line, char c)
{
	int i;
	int lenght;
	int max;
	
	i = 0;
	max = 0;
	lenght = 0;
	while (line[i])
	{
		if (ft_strchr(" 10NSEW", line[i]))
			lenght++;
		if (line[i] == c)
		{
			if (lenght > max)
				max = lenght;
			lenght = 0;
		}
		i++;
	}
	if (line[i] == '\0')
	{
		if (lenght > max)
			max = lenght;
	}
	return (max);
}

int	map_find_borders(char *line, int start, int *map_end)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (line[i] && ft_strchr(MAP_ARGUMENTS, line[i]))
	{
		if (line[i] && ft_strchr(MAP_CHARACTER_ANGLE, line[i]))
			count++;
		if (ft_strchr("01NSEW", line[i]))
			*map_end = i;
		i++;
	}
	if (*map_end == start)
		return (print_error(PROMPT, ERR_BORDER, ERR_SET_MAP, "😠"));
	if (line[i] != '\0')
		return (print_error(PROMPT, ERR_BORDER, NULL, ERR_WRONG_CHAR));
	if (count > 1)
		return (print_error(PROMPT, ERR_BORDER, NULL, ERR_SPAWN_MULTIPLE));
	else if (count == 0)
		return (print_error(PROMPT, ERR_BORDER, NULL, ERR_SPAWN_NOT_SET));
	return (0);
}

int	map_skip_empty_line(char *line, int limit)
{
	int		i;

	i = limit;
	while (ft_strchr(" \r\n", line[i]) && !ft_strchr("10NSEW", line[i]))
	{
		if (line[i] == '\r')
			limit = i;
		i++;
	}
	if (line[limit] == '\r')
		limit++;
	return (limit);
}

int	map_map(char *line, int start, t_main *main)
{
	int	map_end;

	start = map_skip_empty_line(line, start);
	map_end = start;
	if (map_find_borders(line, start, &map_end) == ERROR)
	{
		free_definitions(main);
		free(main->texture.rgb_f);
		free(main->texture.rgb_c);
		return (ERROR);
	}
	main->map.l_free = ft_substr(line, start, (map_end - start + 1));
	main->map.map = map_split(main->map.l_free, '\n',\
		map_max_lenght(main->map.l_free, '\n'));
	free(main->map.l_free);
	return (map_borders(main));
}
