/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_putwchar.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:39:50 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 08:03:40 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			bitlen(unsigned int value)
{
	size_t		len;

	len = 0;
	while (value)
	{
		value = value >> 1;
		len++;
	}
	return (len);
}

void			fill_mask2(unsigned int input, int nbits)
{
	unsigned int	res[5];

	if (nbits <= 16)
	{
		res[0] = 0b11100000 | (input >> 12);
		res[1] = 0b10000000 | ((input >> 6) & 0b111111);
		res[2] = 0b10000000 | (input & 0b111111);
		res[3] = 0;
	}
	else
	{
		res[0] = 0b11110000 | (input >> 18);
		res[1] = 0b10000000 | ((input >> 12) & 0b111111);
		res[2] = 0b10000000 | ((input >> 6) & 0b111111);
		res[3] = 0b10000000 | ((input & 0b111111));
		res[4] = 0;
	}
	ft_putstri(res);
}

void			fill_mask(unsigned int input, int nbits)
{
	unsigned int	res[4];

	if (nbits <= 7)
	{
		res[0] = input;
		res[1] = 0;
		ft_putstri(res);
	}
	else if (nbits <= 11)
	{
		res[0] = 0b11000000 | (input >> 6);
		res[1] = 0b10000000 | (input & 0b111111);
		res[2] = 0;
		ft_putstri(res);
	}
	else
		fill_mask2(input, nbits);
}

int				ft_putwchar(wchar_t c)
{
	size_t		len;

	if ((MB_CUR_MAX <= 1 && c <= 255 && c > 127) || c == 0)
		return (write(1, &c, 1));
	if ((MB_CUR_MAX <= 1 && c > 255) || (c >= 0xD800 && c <= 0xDFFF)
		|| c > 0x10FFFF || c < 0)
		return (-1);
	len = bitlen(c);
	fill_mask(c, len);
	return (get_nbytes(c));
}

int				ft_putwstr(wchar_t *str, int len)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (i < len && str[i])
	{
		if ((str[i] >= 0xD800 && str[i] <= 0xDFFF) || str[i] > 0x10FFFF ||
			str[i] < 0 || (MB_CUR_MAX <= 1 && str[i] > 255))
			return (-1);
		i++;
	}
	i = 0;
	while (str[i] && ((ret + get_nbytes(str[i])) <= (unsigned long)len))
	{
		ret += ft_putwchar(str[i]);
		i++;
	}
	return (ret);
}
