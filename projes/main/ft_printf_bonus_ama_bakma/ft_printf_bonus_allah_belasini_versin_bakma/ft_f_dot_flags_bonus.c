/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_dot_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:20:32 by gsever            #+#    #+#             */
/*   Updated: 2022/03/11 21:51:24 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
s1 = "gorkem" | s2 = "sever" --> gorkemsever
2 stringi birlestiriyor.
not: static char -> sadece bu fonksiyon icinde kullanilabilinir. bu ft_strjoin.c
dosyasini baska dosyalarda kullanacagin zaman, ft_strcpy() diye cagiramazsin.
*/
char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (*src)
		dst[i++] = *((char *)src++);
	dst[i] = '\0';
	return (dst);
}

int	ft_f_minus(const char *format, int buff, t_flags f, va_list arg)
{
	if (f.minus && f.zero)//all --> sola yapistiriyoruz.
	{
		if (f.plus && f.space)// + varsa ' ' varsa [0]'a "+" yaz
			buff = ft_strjoin(buff, plus(f, arg));
		else if (!f.plus && f.space)// + yoksa ' ' varsa [0]'a space yaz.
			buff = ft_strjoin(buff, " ");
		else if (!f.plus && !f.space)// + yoksa ' ' yoksa [0]'a sayiyi yaz.
			buff = ft_strjoin(buff, va_arg(arg, ));
	}
	else if (f.minus && !f.zero)
	{
		
	}
}

int	ft_f_zero(const char *format, int buff, t_flags f, va_list arg)
{
	
}

static char	*ft_sharp(const char *format)
{
	if (*format == 'X')
		return ("0X");
	return ("0x");
}

int	ft_f_hashtag(const char *format, int buff, t_flags f, va_list arg)
{
	if (f.minus)
	{
		if (f.plus || f.space)
		{
			buff = ft_strjoin(buff, ft_sharp(format));
			buff = ft_strjoin(buff, arg);
		}
	}
}
