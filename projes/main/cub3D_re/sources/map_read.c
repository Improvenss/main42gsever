/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:58:30 by gsever            #+#    #+#             */
/*   Updated: 2023/01/11 23:17:46 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_definitions_invalid_input(char *line, int limit, t_main *main)
{
	if (!ft_strchr(MAP_WHITESPACES, line[limit]))
	{
		free_definitions(main);
		return (ERROR);
	}
	return (0);
}

char	*map_read_definitions(char *line, int *limit, int *count, int size)
{
	int		i;
	char	*str;

	str = NULL; 
	if ((*limit) == 0 || line[(*limit) - 1] == '\n')
	{
		(*count)++;
		*limit = (*limit) + size;
		while (line[*limit] && (line[*limit] == ' ' || line[*limit] == '\t'))
			(*limit)++;
		i = *limit;
		while (line[i] && !ft_strchr(WHITESPACES, line[i]))
			i++;
		// if (line[i] == '\n')
		if (line[i] == '\n' || line[i] == '\r')
			i--;
		else
			return (NULL);
		if (i > (*limit) + 3)
			str = ft_substr(&line[*limit], 0, ++i - (*limit));
		else
			return (NULL);
		*limit = i;
	}
	return (str);
}

void	map_definitions_init(t_main *main)
{
	main->texture.no = NULL;
	main->texture.so = NULL;
	main->texture.we = NULL;
	main->texture.ea = NULL;
	main->texture.f = NULL;
	main->texture.c = NULL;
}

/**
 * @brief	Map definitions read first entries, Don't repeat entries!
 *			Skipped if there are different entries before definitions.
 * @param line 
 * @param main 
 * @return int 
 */
int	map_definitions(char *line, t_main *main)
{
	int	count;
	int	limit;

	limit = 0;
	count = 0;
	map_definitions_init(main);
	while (line[limit] && count < 6)
	{
		if (!main->texture.no && ft_strncmp_edited("NO ", &line[limit], 3))
			main->texture.no = map_read_definitions(line, &limit, &count, 3);
		if (!main->texture.so && ft_strncmp_edited("SO ", &line[limit], 3))
			main->texture.so = map_read_definitions(line, &limit, &count, 3);
		if (!main->texture.we && ft_strncmp_edited("WE ", &line[limit], 3))
			main->texture.we = map_read_definitions(line, &limit, &count, 3);
		if (!main->texture.ea && ft_strncmp_edited("EA ", &line[limit], 3))
			main->texture.ea = map_read_definitions(line, &limit, &count, 3);
		if (!main->texture.f && ft_strncmp_edited("F ", &line[limit], 2))
			main->texture.f = map_read_definitions(line, &limit, &count, 2);
		if (!main->texture.c && ft_strncmp_edited("C ", &line[limit], 2))
			main->texture.c = map_read_definitions(line, &limit, &count, 2);
		if (map_definitions_invalid_input(line, limit, main) == ERROR)
			return (print_error(PROMPT, NULL, NULL, RED ERR_INVALID_INPUT END));
		limit++;
	}
	return (map_definitions_check(count, line, limit, main));
}

char	*map_read(int fd)
{
	char	*line;
	char	*tmp;

	line = NULL;
	tmp = get_next_line(fd);
	while (tmp)
	{
		line = ft_strjoin(line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (line);
}
