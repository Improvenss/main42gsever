/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:36:38 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/24 10:32:05 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	long	result;
	int		offset;
	int		sign;

	result = 0;
	offset = 0;
	sign = 1;
	while (nptr[offset] == ' ' || (nptr[offset] >= 9 && nptr[offset] <= 13))
		offset++;
	if (nptr[offset] == '-')
	{
		sign *= -1;
		offset++;
	}
	else if (nptr[offset] == '+')
		offset++;
	while (ft_isdigit(nptr[offset]))
	{
		result *= 10;
		result += nptr[offset] - '0';
		offset++;
	}
	return (result * sign);
}
