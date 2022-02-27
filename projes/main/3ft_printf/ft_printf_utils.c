/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:42:55 by gsever            #+#    #+#             */
/*   Updated: 2022/02/27 18:46:45 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
yazdirmak istedigimiz char'i int olarak gonderiyoruz cunku bazi char'lara
fonksiyonu int olarak tanimladigimiz zaman ulasamiyoruz o yuzden int tanimlioz
*/
int	ft_print_char(const int c)
{
	write(1, &c, 1);
	return (1);
}
/*
string'i direkt yazdiriyoruz. her functionumuzu int tanimlamamiz gerekiyor, 
cunku 
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
