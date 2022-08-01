/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:45:48 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/15 19:25:03 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_gnl
{
	int				fd;
	char			*rd_str;
	struct s_gnl	*next;
}	t_gnl_list;

/* get_next_line.c */
char			*get_next_line(int fd);
char			*process_next_line(char *buf, t_gnl_list **t_list, int fd);
t_gnl_list		*ft_lst_foc(t_gnl_list **lst, int fd);
t_gnl_list		*ft_gnl_lstnew(int fd);
void			ft_gnl_free_lst(t_gnl_list **lst, int fd);

/* get_next_line_utils.c */
void			*ft_gnl_free_all(char *buf, t_gnl_list **t_fd, int fd);

#endif
