/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:36:20 by akaraca           #+#    #+#             */
/*   Updated: 2022/11/06 01:29:11 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

char	*read_file(int fd, char *save);
char	*short_do_line(char	*save);
char	*save_last_word(char	*save);

size_t	ft_strlen_gn(char *save);
char	*ft_strjoin_gn(char *save, char *buffer);
char	*ft_strchr_gn(char *save, int c);
#endif
