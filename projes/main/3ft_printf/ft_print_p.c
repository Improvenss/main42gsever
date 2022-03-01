/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:25:15 by gsever            #+#    #+#             */
/*   Updated: 2022/03/01 14:10:24 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
Amacimiz pointer'in adressini yazdirma.

original_printf: Bellekteki adresini yazdiriyor. Bu olayi Hexadecimal(16)
olarak yazdiriyor. "unsigned long long kullaniyoruz" 20 basamak olarak oluyor 
bu adressler. ornek: "0xfffffffffffffffff"
Yazdirabilmemiz icin; decimal degerini ya da octal degerini 
hexadecimale cevirmemiz gerekiyor.

ft_printf: Allocation islemi yapmamizi istemiyor, o yuzden sadece bellekteki 
adresini yazdirma gibi bir durumumuz olmayacak. Sadece Hexadecimale cevirip, 

*/
int	ft_print_pointer(unsigned long long address)
{
	unsigned long long write_adress;
	
}