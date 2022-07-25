/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:46:34 by gsever            #+#    #+#             */
/*   Updated: 2022/03/03 12:07:16 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
		-- %i icin yapildi - (ama printf cok ultra muk bir fonksiyon
		oldugu icin %d ile %i ayni boku yapiyor... -_- -
ft_print_decimal() fonksiyonu cagirarak; decimal to octal yaptiktan sonra 
yani 10->8, bunu char olarak yazdiriyoruz.

int	ft_print_decimal_to_octal(int dec)
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
*/
static int	ft_number_len(unsigned int number)
{
	int	len;

	len = 0;
	while (number != 0)
	{
		len++;
		number /= 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int number)
{
	char	*str;
	int		len;

	len = ft_number_len(number);
	str = malloc (sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (number != 0)
	{
		str[len - 1] = number % 10 + '0';
		number /= 10;
		len--;
	}
	return (str);
}

/*
		-- %u icin yapildi --
	unsigned integer olarak gonderilen degerimizi yazdirmamizi istiyor.
*/
int	ft_print_udecimal(unsigned int value)
{
	int		printed;
	char	*str;

	printed = 0;
	if (value == 0)
		printed += write(1, "0", 1);
	else
	{
		str = ft_uitoa(value);
		printed += ft_print_string(str);
		free(str);
	}
	return (printed);
}
