/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:56:16 by gsever            #+#    #+#             */
/*   Updated: 2022/03/04 15:31:10 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
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

/*
					-- Bonusta ne istiyor bizden? --
	Bu adama beton yetmez!
		-> https://alvinalexander.com/programming/printf-format-cheat-sheet/

		%[Flags][Width].[Precision][Specifier]
		%[İşaretler][Genişlik].[Hassasiyet][Belirleyici]
						%
1->	[w]	(%5d)	5 dedigimiz yer bizim genisligimiz oluyor, toplamda 5
	karakterlik yer acmis oluyoruz.
	ornek --> printf("|%5d|", 123); --> |  123| oluyor.
				***********************
	[-]	(%-5d)	Eger 5'in basinda - varsa yazilarimizi sola yapistiriyor.
	ornek --> printf("|%-5d|", 123); --> |123  | oluyor.
				***********************
	[+]	(%+5d)	Eger 5'in basinda + varsa sayimizin pozitif/negatif gore + -
					pozitifse = +		koyuyor.
		ornek --> printf("|%+5d|", 123); --> | +123| oluyor.
					negatifse = -		koyuyor.
		ornek --> printf("|%+5d|", -123); --> | -123| oluyor.
				***********************
	[0]	(%05s)	Eger 5'in basinda 0 (SIFIR) varsa bosluklar yerine 0 koyuyor.
	ornek --> printf("|%5s|", "abc"); --> |00abc| oluyor.
				***********************
	[#]	(%#5d)	Eger 5'in basinda # varsa hexadecimal yazdirilan yani x - X
	ile ciktisi istenilen ciktinin basina 0x - 0X koyuyor. #'siz yazdigimizda 
	sadece hex hali yaziliyor. (Adres yazdirir gibi)
				-- Sadece x, X, p ile kullanilabilinir. Bunlar hex cikiyor.
									p haricmis...
		ornek --> printf("|%#5x|", 123); --> | 0x7b| oluyor.
		ornek --> printf("|%#5X|", 123); --> | 0X7B| oluyor.
				***********************
	[ ]	(% 5s)	
				***********************
	[.]	(%.5f)	.'dan sonra verilen sayi kadar virgullu sayinin virgulden 
	sonrasinin kac basamak yazilacagini belirliyor. (Float)
		ornek --> printf("|%10.3f|", 123.12345); --> |   123.123| oluyor.
*/
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

void	ft_test_c(void);
void	ft_test_s(void);
void	ft_test_p(void);
void	ft_test_d(void);
void	ft_test_i(void);
void	ft_test_u(void);
void	ft_test_x(void);
void	ft_test_X(void);
void	ft_test_percent(void);

void	ft_test_bonus_width(void);
void	ft_test_bonus_left(void);
void	ft_test_bonus_plus(void);
void	ft_test_bonus_zero(void);
void	ft_test_bonus_hashtag(void);
void	ft_test_bonus_space(void);
void	ft_test_bonus_dot(void);


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

	ft_test_bonus_width();
	//ft_test_bonus_left();
	//ft_test_bonus_plus();
	//ft_test_bonus_zero();
	//ft_test_bonus_hashtag();
	//ft_test_bonus_space();
	//ft_test_bonus_dot();
}
