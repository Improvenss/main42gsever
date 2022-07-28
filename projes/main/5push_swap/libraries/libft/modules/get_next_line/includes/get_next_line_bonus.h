/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:38:21 by gsever            #+#    #+#             */
/*   Updated: 2022/07/29 00:14:46 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*save_last_word(char *save);
char	*short_do_line(char *save);
char	*read_file(int fd, char *save);
char	*ft_strjoin_ch(char *save, char *buffer);

//UTILS
char	*ft_strchr_ch(char *save, int c);
size_t	ft_strlen_ch(const char *s);

#endif