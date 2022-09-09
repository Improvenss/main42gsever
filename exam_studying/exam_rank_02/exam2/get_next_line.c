/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:38:18 by tmerida-          #+#    #+#             */
/*   Updated: 2022/04/07 20:42:18 by gsever           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char *ft_strdup(char *str)
{
	int i;
	char *alan;
	int len;

	i = 0;
	len = ft_strlen(str);
	alan = malloc(len + 1);
	if (!alan)
	{
		return (NULL);
	}
	while (str[i])
	{
		alan[i] = str[i];
		i++;
	}
	alan[i] = 0;
	return (alan);
}

char *get_next_line(int fd)
{
	char buffer;
	char rtn[7000000];
	int i;
	int num;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	i = 0;
	num = read(fd, &buffer, 1);
	while (num > 0)
	{
		rtn[i++] = buffer;
		if (buffer == '\n')
			break;
		num = read(fd, &buffer, 1);
	}
	rtn[i] = 0;
	if (num <= 0 && i == 0)
		return (0);
	return (ft_strdup(rtn));
}

int	main(void)
{
	char *line;
	char *line2;
	int fd;
	int fd2;


	fd2 = open("sdf.txt", O_RDONLY);

	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
}
