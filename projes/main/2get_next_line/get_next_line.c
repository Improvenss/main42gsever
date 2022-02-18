/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:04:12 by gsever            #+#    #+#             */
/*   Updated: 2022/02/18 13:14:46 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_left_str(char *first)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	while (first[i] && first[i] != '\n')
		i++;
	if (!first[i])
	{
		free(first);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(first) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (first[i])
		str[j] = first[i];
	str[j] = '\0';
	free(first);
	return (str);
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

char *get_next_line(int fd)
{
	char *str;
	static char *first;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	first = ft_read_lines_to_left(fd, first);
	if (!first)
		return (NULL);
	str = ft_get_line(first);
	first = ft_new_left_str(first);
	return (str);
}
int	main()
{
	char *ft_txt;
	int fd = open("test1", O_RDONLY);
	int ft_res_fd = open("result", O_RDWR);
	
	for (int i = 0; i < 10; i++)
	{
		ft_txt = get_next_line(fd);
		write (ft_res_fd, ft_txt, ft_strlen(ft_txt));
	}
}
/*
1-Ilk basta fd'miz ve BUFFER_SIZE'miz islenebilen bir degerse devam.
2-Girdigimiz BS kadar satiri okuyacagiz.
3-'\n' gorene kadar, BS kadar read()'le okuyacagiz.
4-
*/