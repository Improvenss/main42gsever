/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:50:59 by gsever            #+#    #+#             */
/*   Updated: 2023/01/11 23:00:02 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_map(t_main *main, char **argv)
{
	char	*line;
	int		fd;

	fd = open(argv[1], F_OK);
	if (fd == -1)
		return (print_error(PROMPT, NULL, NULL, RED ERR_ARGS_EXIST END));
	line = map_read(fd);
	if (!line)
		return (print_error(PROMPT, NULL, NULL, RED ERR_MAP_EMPTY END));
	if (map_definitions(line, main) == ERROR)
	{
		free(line);
		return (ERROR);
	}
	else
		free(line);
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2)
		return (print_error(PROMPT, NULL, NULL, RED ERR_ARGS END));
	if (argc > 2)
		return (print_error(PROMPT, NULL, NULL, RED ERR_ARGS_MANY END));
	if (ft_strcmp_edited(".cub", &argv[1][ft_strlen(argv[1]) - 4]) \
		|| ft_strlen(argv[1]) < 5 || argv[1][ft_strlen(argv[1]) - 5] == '/')
		return (print_error(PROMPT, NULL, NULL, RED ERR_EXTENSION END));
	return (0);
}