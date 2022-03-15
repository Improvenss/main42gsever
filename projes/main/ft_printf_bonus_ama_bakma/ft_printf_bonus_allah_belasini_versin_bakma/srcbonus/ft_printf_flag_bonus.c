/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:05:07 by gsever            #+#    #+#             */
/*   Updated: 2022/03/15 14:22:11 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
		-- OK --
	genisligimizi hesaplamaliyiz ki alanimizi acabilelim.
 		%005d %#d %d %d
	dongu ya da kosul icide kullandigimiz break; butun dongulerden ve 
kosullardan cikiyor.
*/
static int	ft_find_width(const char *format)
{
	char	width_char;
	int		width;

	while (!ft_strchr(SPECIFIERS, *format) || *format == '.')
	{
		if (ft_strchr(W_NUMBERS, *format))
		{
			while (!ft_strchr(SPECIFIERS, *format) || *format == '.')
			{
				width_char = ft_strjoin(width_char, *format);
				format++;
			}
			break;
		}
		format++;
	}
	width = ft_atoi(width_char);
	return (width);
}

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
		if (*format == '+')//d,i,p
			flags.plus = 1;
		format++;
	}
	return (flags);
}

/*
		-- daha bitmedi --
	
*/
int	ft_check_flag(va_list arg, const char *format, t_flags flags)
{
	int		printed;
	int		width;
	char	*str;
	char	*buff;
			/* flaglarimiza flags.* = 0 atadik. */
	flags = ft_find_flags(format, ft_newflags());/* flaglarimiz hazir */
	width = ft_find_width(format);/* genisligimiz hazir */
	buff = malloc(sizeof(char) * width);/* genisligimiz kadar yer actik */
	if (!buff)/* |       123| */
		return (NULL);
	printed += ft_print_w_f(format, buff, flags, arg);
	return (printed)
}
