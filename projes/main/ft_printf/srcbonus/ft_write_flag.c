/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:23:27 by gsever            #+#    #+#             */
/*   Updated: 2022/03/04 15:39:55 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int ft_write_flag_space(va_list arg, )
{
	int	printed;

	printed = 0;
	if ()
	return (printed);
}

int ft_write_flag_zero(long long number)
{
	int	printed;

	printed = 0;
	if (number >= 0)
		printed += write(1, "+", 1);
	else
		printed += write(1, "-", 1);
	return (printed);
}

int ft_write_flag_pos_neg(long long number)
{
	int	printed;

	printed = 0;
	if (number >= 0)
		printed += write(1, "+", 1);
	else
		printed += write(1, "-", 1);
	return (printed);
}
