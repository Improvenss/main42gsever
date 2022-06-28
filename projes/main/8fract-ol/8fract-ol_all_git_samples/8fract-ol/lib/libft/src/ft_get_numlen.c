/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_numlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:20:19 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/14 11:23:22 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_numlen(long n)
{
	int	numlen;

	numlen = 1;
	if (n < 0)
		numlen++;
	while (n / 10)
	{
		numlen++;
		n /= 10;
	}
	return (numlen);
}

int	ft_get_numlen_base(long n, u_int base)
{
	int	numlen;

	numlen = 1;
	if (n < 0)
		numlen++;
	while (n / base)
	{
		numlen++;
		n /= base;
	}
	return (numlen);
}
