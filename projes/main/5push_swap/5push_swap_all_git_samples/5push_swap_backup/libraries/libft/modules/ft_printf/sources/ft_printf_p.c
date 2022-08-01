/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:25:15 by gsever            #+#    #+#             */
/*   Updated: 2022/03/08 13:58:30 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
	Amacimiz pointer'in adressini yazdirma.

	original_printf: Bellekteki adresini yazdiriyor. Bu olayi Hexadecimal(16)
olarak yazdiriyor. "unsigned long long kullaniyoruz" ki 20 basamak oluyor 
bu adresler. 20 basamak yazdirabilmemiz icin. ornek: "0xfffffffffffffffff"
			Yazdirabilmemiz icin; decimal degerini ya da octal degerini 
hexadecimale cevirmemiz gerekiyor.

	ft_printf: Allocation islemi yapmamizi istemiyor, o yuzden sadece bellekteki 
adresini yazdirma gibi bir durumumuz olmayacak. Sadece Hexadecimale cevirip, 
teker teker char olarak yani sonucunda string olarak cikti alacagiz.
*/
static int	ft_pointer_len(unsigned	long number)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 16;
		count++;
	}
	return (count);
}

//hexadecimal olrak stdout olarak yaziyoruz (write(1, value, 1))
static int	ft_print_ptr(unsigned long long value)
{
	if (value >= 16)
	{
		ft_print_ptr(value / 16);
		ft_print_ptr(value % 16);
	}
	else
	{
		if (value <= 9)
			ft_putchar_fd(value + '0', 1);
		else
			ft_putchar_fd(value - 10 + 'a', 1);
	}
	return (ft_pointer_len(value));
}

int	ft_print_pointer(unsigned long long address)
{
	int	printed;

	printed = 0;
	printed += ft_print_string("0x");
	if (address == 0)
		printed += write(1, "0", 1);
	else
		printed += ft_print_ptr(address);
	return (printed);
}
