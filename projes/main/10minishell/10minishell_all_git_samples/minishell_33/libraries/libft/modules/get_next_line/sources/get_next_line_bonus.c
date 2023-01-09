/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:14:11 by gsever            #+#    #+#             */
/*   Updated: 2022/07/29 00:14:28 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

// /*
// FD'den aldigimiz 1 satiri okuyup yazdiktan sonra okudugumuz satiri 
// cikartip kalan satirlari tekrardan yazmamiz gerekiyor.
// Bu yuzden fonksiyona line'yi ve fd'yi gondermemiz gerekiyor.
// ornek -> fd = fd - line;
// */
// char	*ft_remove_writed_line(char *line)
// {
// 	int		counter;
// 	int		counter_removed;
// 	char	*new_removed_file;

// 	counter = 0;
// 	while (line[counter] && line[counter] != '\n')
// 		counter++;
// 	if (!line[counter])
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	new_removed_file = malloc(sizeof(char)* (ft_strlen(line) - counter + 1));
// 	if (!new_removed_file)
// 		return (NULL);
// 	counter++;
// 	counter_removed = 0;
// 	while (line[counter])
// 		new_removed_file[counter_removed++] = line[counter++];
// 	new_removed_file[counter_removed] = '\0';
// 	free(line);
// 	return (new_removed_file);
// }
// /*
// Ayirmak istedigimiz karakter miktarini sayiyoruz.
// 2 fazlasi kadar malloc'la yer aciyoruz, \n & \0 icin.
// Sonra sirasiyla \n ve \0 koyuyoruz.
// ft_write_readed_line ---> "okunan line" + \n + \0.
// Okudugumuz line'yi new_writed_line'ye yazdik ve return ettik.
// */

// char	*ft_write_readed_line(char *line)
// {
// 	int		counter;
// 	char	*new_writed_line;

// 	counter = 0;
// 	if (!line[counter])
// 		return (NULL);
// 	while (line[counter] != '\n' && line[counter] != '\0')
// 		counter++;
// 	new_writed_line = malloc(sizeof(char) * counter + 2);
// 	if (!new_writed_line)
// 		return (NULL);
// 	counter = 0;
// 	while (line[counter] && line[counter] != '\n')
// 	{
// 		new_writed_line[counter] = line[counter];
// 		counter++;
// 	}
// 	if (line[counter] == '\n')
// 	{
// 		new_writed_line[counter] = line[counter];
// 		counter++;
// 	}
// 	new_writed_line[counter] = '\0';
// 	return (new_writed_line);
// }
// /*
// \n gorene kadar BUFFER_SIZE * n kadar okuyacagiz
// ft_strjoin'de malloc'la yer ayirdigimiz icin ilk bastaki 4 char icin yer
// acmak yeterli oluyor.
// */

// char	*ft_read_line(int fd, char *line)
// {
// 	char	*buff;
// 	int		rd_bytes;

// 	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
// 	if (!buff)
// 		return (NULL);
// 	rd_bytes = 1;
// 	while (!ft_strchr(line, '\n') && rd_bytes != 0)
// 	{
// 		rd_bytes = read(fd, buff, BUFFER_SIZE);
// 		if (rd_bytes == -1)
// 		{
// 			free(buff);
// 			return (NULL);
// 		}
// 		buff[rd_bytes] = '\0';
// 		line = ft_strjoin_gnl(line, buff);
// 	}
// 	free(buff);
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*line[1000];
// 	char		*write_readed_line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	line[fd] = ft_read_line(fd, line[fd]);
// 	if (!line[fd])
// 		return (NULL);
// 	write_readed_line = ft_write_readed_line(line[fd]);
// 	line[fd] = ft_remove_writed_line(line[fd]);
// 	return (write_readed_line);
// }
// /*
// int	main()
// {
//  	int fd = open("test1", O_RDONLY);
// 	int	fd2 = open("test2", O_RDONLY);
//  	int resfd = open("result", O_RDWR);
//   	char  *str;

// 	//str = get_next_line(fd);
// 	//write (resfd, str, ft_strlen(str));

//  	for (int i = 0; i < 10; i++) {
//  		if (i%2)
//  			str = get_next_line(fd2);
//  		else
//  			str = get_next_line(fd);
//   		write(resfd, str, ft_strlen(str));
//  	}
// }
// */
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
