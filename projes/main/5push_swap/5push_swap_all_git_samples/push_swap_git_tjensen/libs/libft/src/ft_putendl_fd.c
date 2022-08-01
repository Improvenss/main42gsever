/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:11:09 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/14 16:45:24 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	count;

	if (s == NULL)
		return (0);
	count = ft_putstr_fd(s, fd);
	count += ft_putchar_fd('\n', fd);
	return (count);
}
