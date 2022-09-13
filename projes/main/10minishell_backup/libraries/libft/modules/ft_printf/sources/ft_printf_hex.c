/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:21:35 by gsever            #+#    #+#             */
/*   Updated: 2022/03/03 12:05:13 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//it's calculating value's lengt and return lengt.
static int	ft_hexadecimal_len(unsigned int number)
{
	int	printed;

	printed = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 16;
		printed++;
	}
	return (printed);
}

/*
64bit sistemlerde pointer boyutu 8 bytedir, hex yazdirma islemi 
ise 4 byte uzerinden yapilir.
*/
int	ft_print_hex(unsigned int value, const char format)
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
