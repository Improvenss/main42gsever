/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:04:12 by gsever            #+#    #+#             */
/*   Updated: 2022/02/18 19:56:27 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
\n gorene kadar BUFFER_SIZE * n kadar okuyacagiz
*/

char	*get_next_line(int fd)
{
	static char *line;
	char *buff;
	int rd_bytes;
	int counter;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	rd_bytes = 1;
	while (!ft_strchr(line, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		buff[rd_bytes] = '\0';
		line = ft_strjoin(line, buff);
	}
	counter = 0;
	while (line[counter] != '\n' && line[counter] != '\0')
		counter++;
	
}
/*
int	main()
{
 	int fd = open("test1", O_RDONLY);
 	int resfd = open("result", O_RDWR);
  	char  *str;

 	for (int i = 0; i < 10; i++) {
   		str = get_next_line(fd);
  		write(resfd, str, ft_strlen(str));
 	}
}
*/