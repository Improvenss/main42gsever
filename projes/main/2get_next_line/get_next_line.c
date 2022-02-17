/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:04:12 by gsever            #+#    #+#             */
/*   Updated: 2022/02/17 20:48:52 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_left_str(char *first)
{
	
}

char	*ft_get_line(char *first)
{
	char	*str;
	int	i;

	i = 0;
	if (!first[i])
	 	return (NULL);
	while (first[i] && first[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	while (first[i] && first[i] != '\n')
	{
		str[i] = first[i];
		i++;
	}
	if (first[i] == '\n')
	{
		str[i] = first[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_read_lines_to_left(int fd, char *first)
{
	char	*buff;
	int	read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(first, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		first = ft_strjoin(first, buff);
	}
	free(buff);
	return (first);
}

char *get_next_line(int fd);
{
	char *str;
	static char *first;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	first = ft_read_lines_to_left(fd, first);
	if (!first)
		return (NULL);
	str = ft_get_line(first);
	first = ft_new_left_str();
}

#include <stdio.h>

int	main()
{
	int fd = open("test1", O_RDONLY);
	int res = open("result", O_RDWR);
	fprintf(test1, "ft_:%s\n", 50);
}
/*
1-Ilk basta fd'miz ve BUFFER_SIZE'miz islenebilen bir degerse devam.
2-Girdigimiz BS kadar satiri okuyacagiz.
3-'\n' gorene kadar, BS kadar read()'le okuyacagiz.
4-
*/