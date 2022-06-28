/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:01:44 by gsever            #+#    #+#             */
/*   Updated: 2022/06/06 02:42:55 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
	ASCII to LONG
*/
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

/*
	In math library == pow(x, y)
	x^y --> x=2 y=3 -> x.x.x = x^3
*/
int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = nb;
	while (power > 1)
	{
		result *= nb;
		power--;
	}
	return (result);
}

/*
	
*/
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
