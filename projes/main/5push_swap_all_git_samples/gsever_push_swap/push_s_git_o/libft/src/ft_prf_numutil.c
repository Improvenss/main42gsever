/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_numutil.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 19:32:02 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 16:07:21 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				isnum(char c)
{
	return ((c >= '0' && c <= '9') || c == '-');
}

unsigned int	ft_prf_abs(int n)
{
	unsigned int	un;

	un = (unsigned int)n;
	if (n < 0)
		un = -n;
	return (un);
}

unsigned int	res_len(uintmax_t value, int base)
{
	unsigned int	len;
	uintmax_t		nb;

	len = 0;
	if (!value)
		return (1);
	nb = value;
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char			to_char(uintmax_t val, int maj)
{
	char	c;
	char	a;

	a = 'a';
	if (maj)
		a = 'A';
	if (val < 10)
		c = '0' + val;
	else if (val <= 16 && val >= 10)
		c = a + val - 10;
	else
		return ('\n');
	return (c);
}

char			*ft_prf_itoa_base(uintmax_t value, int base, int maj)
{
	char			*str;
	unsigned int	len;
	unsigned int	i;
	uintmax_t		nb;

	nb = value;
	len = res_len(value, base);
	i = 0;
	str = ft_prf_strnew(len);
	while (i < len)
	{
		str[len - i - 1] = to_char(nb % base, maj);
		nb /= base;
		i++;
	}
	return (str);
}
