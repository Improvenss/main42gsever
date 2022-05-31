/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_unumlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:30:52 by gsever            #+#    #+#             */
/*   Updated: 2022/05/31 14:32:48 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_get_unumlen(u_long nb)
{
	int	count;

	count = 1;
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_get_unumlen_base(u_long n, u_int base)
{
	int	numlen;

	numlen = 1;
	while (n / base)
	{
		numlen++;
		n /= base;
	}
	return (numlen);
}
