/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:04:12 by gsever            #+#    #+#             */
/*   Updated: 2022/02/23 14:30:40 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
FD'den aldigimiz 1 satiri okuyup yazdiktan sonra okudugumuz satiri 
cikartip kalan satirlari tekrardan yazmamiz gerekiyor.
Bu yuzden fonksiyona line'yi ve fd'yi gondermemiz gerekiyor.
ornek -> fd = fd - line;
Burada tanimladigimiz counter'le line'yi saydiriyoruz.
*/
char	*ft_remove_writed_line(char *line)
{
	int		counter;
	int		counter_removed;
	char	*new_removed_file;

	counter = 0;
	//line'nin 1 satirini saydiriyoruz.
	while (line[counter] && line[counter] != '\n')
		counter++;
	if (!line[counter])
	{
		free(line);
		return (NULL);
	}
	//fd'den line'yi cikarip kalan kisim kadar yer ayirmamiz gerekiyor.
	new_removed_file = malloc(sizeof(char) * (ft_strlen(line) - counter + 1));
	if (!new_removed_file)
		return (NULL);
	//'\n'i atliyoruz.
	counter++;
	counter_removed = 0;
	while (line[counter])
		new_removed_file[counter_removed++] = line[counter++];
	new_removed_file[counter_removed] = '\0';
	free(line);
	return (new_removed_file);
}
/*
Ayirmak istedigimiz karakter miktarini sayiyoruz.
2 fazlasi kadar malloc'la yer aciyoruz, \n & \0 icin.
Sonra sirasiyla \n ve \0 koyuyoruz.
ft_write_readed_line ---> "okunan line" + \n + \0.
Okudugumuz line'yi new_writed_line'ye yazdik ve return ettik.
*/

char	*ft_write_readed_line(char *line)
{
	int		counter;
	char	*new_writed_line;

	counter = 0;
	if (!line[counter])
		return (NULL);
	while (line[counter] != '\n' && line[counter] != '\0')
		counter++;
	new_writed_line = malloc(sizeof(char) * counter + 2);
	if (!new_writed_line)
		return (NULL);
	counter = 0;
	while (line[counter] && line[counter] != '\n')
	{
		new_writed_line[counter] = line[counter];
		counter++;
	}
	if (line[counter] == '\n')
	{
		new_writed_line[counter] = line[counter];
		counter++;
	}
	new_writed_line[counter] = '\0';
	return (new_writed_line);
}
/*
\n gorene kadar BUFFER_SIZE * n kadar okuyacagiz
ft_strjoin'de malloc'la yer ayirdigimiz icin ilk bastaki 4 char icin yer
acmak yeterli oluyor.
*/

char	*ft_read_line(int fd, char *line)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	//Burada 1 satirin tamamini okuyoruz ve buff'a yaziyoruz.
	while (!ft_strchr(line, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		//Burada line = line + buff; yapiyoruz. Line'miz hazir.
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*write_readed_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_line(fd, line);
	if (!line)
		return (NULL);
	write_readed_line = ft_write_readed_line(line);
	line = ft_remove_writed_line(line);
	return (write_readed_line);
}
/*
int	main()
{
 	int fd = open("test1", O_RDONLY);
 	int resfd = open("result", O_RDWR);
  	char  *str;

	//str = get_next_line(fd);
	//write (resfd, str, ft_strlen(str));

 	for (int i = 0; i < 10; i++) {
   		str = get_next_line(fd);
  		write(resfd, str, ft_strlen(str));
 	}
}
*/