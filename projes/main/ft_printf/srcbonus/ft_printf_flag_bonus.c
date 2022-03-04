/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:05:07 by gsever            #+#    #+#             */
/*   Updated: 2022/03/04 19:26:36 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_calc_number_value(const char *format)
{
	int	value;

	value = 0;
	while (*format != '.' && !ft_strchr(SPECIFIERS, *format))
	{
		
	}
}

int	ft_check_flag(va_list arg, const char *format)
{
	int	printed;

	printed = 0;
	while (format++ != SPECIFIERS)
	{
		if (*format == ' ')
			format++;
		else if (*format == '0')
			printed += 
		else if (*format == '+')
			printed += 
		else if (*format == '-')
			printed += 
		else if (*format == '.')
			return (ft_calc_float_dig(format)); 
		else if (*format == '#')
			printed += 
		else if (*format >= '0' && *format <= '9')
			printed += ft_calc_number_value(*format);
	}
	return (printed)
}
