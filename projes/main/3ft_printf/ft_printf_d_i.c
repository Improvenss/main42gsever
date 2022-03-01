/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:46:34 by gsever            #+#    #+#             */
/*   Updated: 2022/03/01 13:23:59 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
	10'luk tabanda decimal sayi yazdiriyor.
	int->degerini
	char->bytesini yani dec degerini
	string->bellekte adresini yaziyor sanirim (random sayi yazdiriyor). AMA!!
string'in index'iyle birlikte gonderirsen characterini belirttigin icin
char olarak decimal degerini yazdiriyor. 17. satirda belirttigim sey.
*/
int	ft_print_decimal(const long dec)
{
	int		printed;
	char	*value;

	printed = 0;
	value = ft_itoa(dec);
	printed = ft_print_string(value);
	free(value);
	return (printed);
}
/*
alt tarafi %i icin yapildi, yukaridaki fonksiyonu cagirarak;
decimal to octal yaptiktan sonta yani 10->8, bunu char olarak yazdiriyoruz.
*/

int	ft_decimal_to_octal(long dec)
{
	long	octal_number;
	long	i;
	int		remainder;
	int		printed;

	i = 1;
	octal_number = 0;
	while (dec != 0)
	{
		remainder = dec % 8;
		dec = dec / 8;
		octal_number = octal_number + (remainder * i);
		i = i * 10;
	}
	printed = ft_print_decimal(octal_number);
	return (printed);
}
