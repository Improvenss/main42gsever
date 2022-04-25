/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:45:29 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/15 19:25:48 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_gnl_free_all(char *buf, t_gnl_list **t_fd, int fd)
{
	free(buf);
	ft_gnl_free_lst(t_fd, fd);
	return (NULL);
}
