/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:31:18 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/27 11:56:44 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	process_decimal(const char *nptr)
{
	size_t	count;
	double	decimal;

	decimal = ft_atol(nptr);
	count = 0;
	while (ft_isdigit(nptr[count]))
		count++;
	return (decimal / ft_iterative_power(10, count));
}

double	ft_atod(const char *nptr)
{
	int8_t	sign;
	size_t	offset;
	double	result;

	sign = 1;
	offset = 0;
	while (nptr[offset] == ' ' || (nptr[offset] >= 9 && nptr[offset] <= 13))
		offset++;
	if (nptr[offset] == '-')
	{
		sign *= -1;
		offset++;
	}
	else if (nptr[offset] == '+')
		offset++;
	result = ft_atol(&nptr[offset]);
	offset += ft_get_unumlen(result);
	if (nptr[offset] == '.' || nptr[offset] == ',')
		result += process_decimal(&nptr[offset + 1]);
	return (sign * result);
}
