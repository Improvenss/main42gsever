/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:10:35 by gsever            #+#    #+#             */
/*   Updated: 2023/01/11 23:30:02 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	xpm_file_check(char *str, char *name)
{
	int	fd;

	if (ft_strcmp_edited(".xpm", &str[ft_strlen(str) - 4]) \
		|| ft_strlen(str) < 5 || str[ft_strlen(str) - 5] == '/')
	{
		write(2, RED, ft_strlen(RED));
		write(2, name, ft_strlen(name));
		write(2, ": ", 2);
		return (print_error(PROMPT, NULL, NULL, RED ERR_FILE_WRONG END));
	}
	fd = open(str, F_OK);
	if (fd == -1)
	{
		write(2, RED, ft_strlen(RED));
		write(2, name, ft_strlen(name));
		write(2, ": ", 2);
		return (print_error(PROMPT, NULL, NULL, RED ERR_FILE_NOT_FOUND END));
	}
	close(fd);
	return (0);
}

int	map_definitions_check(int count, char *line, int limit, t_main *main)
{
	if (count != 6 \
	|| !main->texture.no || !main->texture.so \
	|| !main->texture.we || !main->texture.ea \
	|| !main->texture.f || !main->texture.c)
	{
		free_definitions(main);
		return (print_error(PROMPT, NULL, NULL, RED ERR_DEF_MISSING END));
	}
	if (xpm_file_check(main->texture.no, "NO") == ERROR \
	|| xpm_file_check(main->texture.so, "SO") == ERROR \
	|| xpm_file_check(main->texture.we, "WE") == ERROR \
	|| xpm_file_check(main->texture.ea, "EA") == ERROR)
	{
		free_definitions(main);
		return (ERROR);
	}
	if (map_definitions_check_rgb(main) == ERROR)
	{
		free_definitions(main);
		return (ERROR);
	}
	return (map_map(line, limit, main));
}
