/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:56:16 by gsever            #+#    #+#             */
/*   Updated: 2022/02/26 18:30:48 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
Printf fonksiyonu istedigimiz seyleri yazdirmanin yaninda kac tane karakter 
yazdirdigimizi da yazdirir (kac karakter yazdirdiysak onu yazdirir 'int')
*/
static int	ft_format(va_list arg, const char *format_string)
{
	int	printed;

	printed = 0;
	if (*format_string == 'c')
		printed += ft_print_char(va_arg(arg, int));
/*
	else if (*format_string == 's')

	else if (*format_string == 'p')

	else if (*format_string == 'd')

	else if (*format_string == 'i')

	else if (*format_string == 'u')

	else if (*format_string == 'x')

	else if (*format_string == 'X')

	else if (*format_string == '%')
*/
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;

	va_start(args, format);
	printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			printed += ft_format(args, (format + 1));
			format++;
		}
		else
			printed += ft_print_char(*format);
		printed++;
	}
	va_end(args);
	return (printed);
}

int	main(void)
{
	char	a;
	char	b;
	char	c;

	a = 'a';
	b = 'b';
	c = 'c';
	printf("%d", printf("org:%c, %c, %c\n", a, b, c));
	printf("%d", ft_printf("ft_:%c, %c, %c\n", a, b, c));
	return (0);
}
