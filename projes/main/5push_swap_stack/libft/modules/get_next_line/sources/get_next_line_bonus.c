/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:14:11 by gsever            #+#    #+#             */
/*   Updated: 2022/08/01 20:20:50 by gsever           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

char	*ft_strjoin_ch(char *save, char *buffer)
{
	char	*temp;
	int		i;
	int		l;

	if (!save)
	{
		save = (char *)malloc(sizeof(char) * 1);
		save[0] = '\0';
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen_ch(save) +\
				ft_strlen_ch(buffer) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (save[i] != '\0')
	{
		temp[i] = save[i];
		i++;
	}
	l = 0;
	while (buffer[l] != '\0')
		temp[i++] = buffer[l++];
	temp[i] = '\0';
	free(save);
	return (temp);
}

char	*read_file(int fd, char *save)
{
	char	*buffer;
	int		count;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	count = 1;
	while (!ft_strchr_ch(save, '\n') && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[count] = '\0';
		save = ft_strjoin_ch(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*short_do_line(char *save)
{
	char	*temp;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		temp[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		temp[i] = save[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*save_last_word(char *save)
{
	char	*temp;
	int		i;
	int		l;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen_ch(save) - i));
	if (!temp)
		return (NULL);
	i++;
	l = 0;
	while (save[i] != '\0')
		temp[l++] = save[i++];
	temp[l] = '\0';
	free(save);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = read_file(fd, save);
	if (!save)
		return (NULL);
	line = short_do_line(save);
	save = save_last_word(save);
	return (line);
}
