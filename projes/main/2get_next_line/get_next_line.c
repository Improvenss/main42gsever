/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:04:12 by gsever            #+#    #+#             */
/*   Updated: 2022/02/17 15:58:50 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char *get_next_line(int fd);
{
	char str;
	static char res;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	res = 
}

#include <stdio.h>

int	main()
{
	int fd = open("test1", O_RDONLY);
	int res = open("result", O_RDWR);
	fprintf(test1, "ft_:%s\n", 50);
}
