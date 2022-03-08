/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flag_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:23:27 by gsever            #+#    #+#             */
/*   Updated: 2022/03/08 12:44:53 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
//width kadar space atilacak ama + var mi 0 var mi kontrol edilecek
int	ft_write_flag_space(va_list arg, const char *format)
{
	int	printed;

	printed = 0;
	if (ft_strchr(format, '0'))
	{
		
	}
	return (printed);
}

int	ft_write_flag_zero(long long number)
{
	int	printed;

	printed = 0;

	return (printed);
}
//sayi pozitifse +, negatifse - yazdir.
int	ft_write_flag_pos_neg(long long number, const char *format)
{
	int	printed;

	printed = 0;
	if (number >= 0)
		printed += write(1, "+", 1);
	else
		printed += write(1, "-", 1);
	return (printed);
}

int	ft_write_(const char *format)
{

}
