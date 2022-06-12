/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:06:40 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/14 11:23:22 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putunbr_fd(u_long n, int fd)
{
	if (n >= 10)
		ft_putunbr_fd((n / 10), fd);
	ft_putchar_fd((n % 10 + '0'), fd);
}

int	ft_putunbr_fd(u_long n, int fd)
{
	putunbr_fd(n, fd);
	return (ft_get_unumlen(n));
}
