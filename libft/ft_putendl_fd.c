/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:36:16 by gsever            #+#    #+#             */
/*   Updated: 2022/02/11 12:37:32 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//write "\n" in a new file
void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
/*
passing chars and writing end of the index newline
*/