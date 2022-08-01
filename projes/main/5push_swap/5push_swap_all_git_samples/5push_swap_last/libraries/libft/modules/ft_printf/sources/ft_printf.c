/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:56:16 by gsever            #+#    #+#             */
/*   Updated: 2022/03/02 21:39:22 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
Printf fonksiyonu istedigimiz seyleri yazdirmanin yaninda kac tane karakter 
yazdirdigimizi da yazdirir (kac karakter yazdirdiysak onu yazdirir 'int')
*/
static int	ft_format(va_list arg, const char *format)
{
	int	printed;

	printed = 0;
	if (*format == 'c')
		printed += ft_print_char(va_arg(arg, int));
	else if (*format == 's')
		printed += ft_print_string(va_arg(arg, char *));
	else if (*format == 'p')
		printed += ft_print_pointer(va_arg(arg, unsigned long long));
	else if (*format == 'd' || *format == 'i')
		printed += ft_print_decimal(va_arg(arg, int));
	else if (*format == 'u')
		printed += ft_print_udecimal(va_arg(arg, unsigned int));
	else if (*format == 'x' || *format == 'X')
		printed += ft_print_hex(va_arg(arg, unsigned long long), *format);
	else if (*format == '%')
		printed += ft_print_percent();
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
		format++;
	}
	va_end(args);
	return (printed);
}
/*
void	ft_test_c(void);
void	ft_test_s(void);
void	ft_test_p(void);
void	ft_test_d(void);
void	ft_test_i(void);
void	ft_test_u(void);
void	ft_test_x(void);
void	ft_test_X(void);
void	ft_test_percent(void);

int	main(void)
{
	//ft_test_c();
	//ft_test_s();
	//ft_test_p();
	//ft_test_d();
	//ft_test_i();
	//ft_test_u();
	//ft_test_x();
	//ft_test_X();
	//ft_test_percent();
}
*/