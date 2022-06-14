/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:36:27 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:59 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//file descriptor'a stringi yaz
void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s)
		write(fd, s++, 1);
}
