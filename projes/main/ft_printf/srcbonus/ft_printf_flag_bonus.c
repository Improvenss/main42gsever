/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:05:07 by gsever            #+#    #+#             */
/*   Updated: 2022/03/05 18:55:34 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
/*
	%[-, 0, ., #,  , +][sayi w yani].[float'in .'si][SPECIFIERS]
*/
static t_flags	ft_find_flags(const char *format, t_flags flags)
{
	while (*format != '.' && !ft_strchr(SPECIFIERS, *format))
	{
		if (*format == '-')
			flags.minus = 1;
		if (*format == '0' && !ft_isdigit(*(format - 1)))
			flags.zero = 1;
		if (*format == '#')
			flags.hashtag = 1;
		if (*format == ' ')
			flags.space = 1;
		if (*format == '+')
			flags.plus = 1;
		format++;
	}
	return (flags);
}

static int	ft_find_width(const char *format, va_list ap, t_flags f)
{
	int	width;

	while (*format != '.' && !ft_strchr(SPECIFIERS, *format))
		format++;
	while ()
	{

	}
	return (width);
}

int	ft_check_flag(va_list arg, const char *format, t_flags flags)
{
	int		printed;
	int		width;

	flags = ft_find_flags(format, ft_newflags());
	width = ft_find_width(format, arg, flags);
	printed = 0;
	return (printed)
}
