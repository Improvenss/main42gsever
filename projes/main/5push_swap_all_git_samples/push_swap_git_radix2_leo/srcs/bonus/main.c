/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 21:22:47 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:42:06 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		*arr;
	int		arr_size;
	t_list	*instructions;
	char	*line;
	int		fd;

	arr_size = get_nbr_in_line(&arr, argc, argv);
	instructions = NULL;
	fd = open("instructions", O_RDONLY);
	if (fd < 0)
		error_exit();
	while (get_next_line(fd, &line) == 1)
	{
		check_instructions(line);
		ft_lstadd_back(&instructions, ft_lstnew(line));
	}
	close(fd);
	if (arr_size == 0)
		normal_exit();
	check_bonus(arr, arr_size, instructions);
	return (0);
}
