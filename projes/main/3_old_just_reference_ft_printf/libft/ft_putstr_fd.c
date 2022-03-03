/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:36:27 by gsever            #+#    #+#             */
/*   Updated: 2022/02/11 12:35:06 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//file descriptor'a stringi yaz
void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s)
		write(fd, s++, 1);
}
