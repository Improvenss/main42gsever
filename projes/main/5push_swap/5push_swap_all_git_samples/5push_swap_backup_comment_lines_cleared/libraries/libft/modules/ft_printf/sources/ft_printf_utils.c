/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:42:55 by gsever            #+#    #+#             */
/*   Updated: 2022/03/03 12:05:43 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
		-- %c icin yapildi --
yazdirmak istedigimiz char'i int olarak gonderiyoruz cunku bazi char'lara
fonksiyonu int olarak tanimladigimiz zaman ulasamiyoruz o yuzden int tanimlioz
*/
int	ft_print_char(const int c)
{
	write(1, &c, 1);
	return (1);
}

/*
		-- %s icin yapildi --
string'i direkt yazdiriyoruz. Her functionumuzu int tanimlamamiz gerekiyor, 
cunku printf() fonksiyonunda ekstra ozellik olarak kac karakter yazdirdiysan 
yazdirdigin karakter sayisi kadar cikti alabiliyorsun.
*/
int	ft_print_string(const char *str)
{
	int	printed;

	printed = 0;
	if (str == NULL)
		return (ft_print_string("(null)"));
	while (*str)
		printed += ft_print_char(*str++);
	return (printed);
}

/*
		-- %d icin yapildi --
	10'luk tabanda decimal sayi yazdiriyor.
	int->degerini
	char->bytesini yani dec degerini
	string->bellekte adresini yaziyor sanirim (random sayi yazdiriyor). AMA!!
string'in index'iyle birlikte gonderirsen characterini belirttigin icin
char olarak decimal degerini yazdiriyor. 43. satirda belirttigim sey.
*/
int	ft_print_decimal(int dec)
{
	int		printed;
	char	*value;

	printed = 0;
	value = ft_itoa(dec);
	printed = ft_print_string(value);
	free(value);
	return (printed);
}

//		-- %% icin yapildi --
int	ft_print_percent(void)
{
	return (ft_print_char('%'));
}
