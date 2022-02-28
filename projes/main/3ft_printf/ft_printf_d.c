/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:46:34 by gsever            #+#    #+#             */
/*   Updated: 2022/02/28 16:27:34 by gsever           ###   ########.fr       */
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
int	ft_print_decimal(const int dec)
{
	int		printed;
	char	*value;

	printed = 0;
	value = ft_itoa(dec);
	printed = ft_print_string(value);
	free(value);
	return (printed);
}
