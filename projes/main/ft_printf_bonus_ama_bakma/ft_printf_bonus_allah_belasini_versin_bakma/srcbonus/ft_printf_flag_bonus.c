/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:05:07 by gsever            #+#    #+#             */
/*   Updated: 2022/03/08 15:15:48 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
/*
	%[-, 0, ., #,  , +][sayi w yani].[float'in .'si][SPECIFIERS]
*/
static t_flags	ft_find_flags(const char *format, t_flags flags)
{
	while (*format != '.' && !ft_strchr(SPECIFIERS, *format))//s, d, i, u ,x, X
	{
		if (*format == '-')//all
			flags.minus = 1;
		if (*format == '0' && !ft_isdigit(*(format - 1)))//d,i,u,x,X
			flags.zero = 1;
		if (*format == '#')//x,X
			flags.hashtag = 1;
		if (*format == ' ')//s, d, i
			flags.space = 1;
		if (*format == '+')//d,i
			flags.plus = 1;
		format++;
	}
	return (flags);
}

//genisligimizi hesaplamaliyiz ki alanimizi acabilelim.
// %005d %#d %d %d
static int	ft_find_width(const char *format, va_list ap, t_flags f)
{
	int		width;
	char	width_char;
	int		specified;

	while (*format != '.' && !ft_strchr(SPECIFIERS, *format))
		format++;
	format--;
	while (*format == '0' && !ft_strchr(W_NUMBERS, *format - 1))
	{
		
	}
	return (width);
}

int	ft_check_flag(va_list arg, const char *format, t_flags flags)
{
	int		printed;
	int		width;
	char	*str;
	char	*buff;

	flags = ft_newflags();
	flags = ft_find_flags(format, flags);
	width = ft_find_width(format, arg, flags);
	buff = malloc(sizeof(char) * width);
	if (!buff)
		return (NULL);
	str = ft_write_all(format, width, buff, flags, )
	printed = 0;
	return (printed)
}
