/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:36:22 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:57 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//witing integer in the file. '0' + n kismi int'i char'a cevirme
void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n / 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd('0' + n, fd);
}
/*
int	main()
{
	int a = -23232323;
	printf("ft_:%d", ft_putnbr_fd(a, 4));
}
*/