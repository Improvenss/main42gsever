/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:46:10 by gsever            #+#    #+#             */
/*   Updated: 2022/02/17 20:03:06 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char    *ft_read_lines_to_left(int fd, char *first);
char    *ft_get_line(char *first); 
//utils
size_t	ft_strlen(const char *s);
static	char *ft_strcpy(char *dst, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
