/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:21:35 by gsever            #+#    #+#             */
/*   Updated: 2022/03/02 13:42:24 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long value, const char format)
{
	if (value == 0)
	{
		ft_putstr_fd("0", 1);
		return (1);
	}
	if (value >= 16)
	{
		ft_print_hex(value / 16, format);
		ft_print_hex(value % 16, format);
	}
	else
	{
		if (value <= 9)
			ft_putchar_fd(value + '0', 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd(value - 10 + 'a', 1);
			else if (format == 'X')
				ft_putchar_fd(value - 10 + 'A', 1);
		}
	}
	return (ft_hexadecimal_len(value));
}
