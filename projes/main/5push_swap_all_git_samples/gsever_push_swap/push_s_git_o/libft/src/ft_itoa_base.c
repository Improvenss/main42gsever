/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:50:53 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:32:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	res_len(int value, int base)
{
	int				len;
	unsigned int	nb;

	len = 0;
	if (value < 0 && base == 10)
	{
		nb = -value;
		len++;
	}
	else if (value < 0)
		nb = -value;
	else
		nb = value;
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

static char	to_char(int val)
{
	char	c;

	if (val < 10)
		c = '0' + val;
	else if (val <= 16 && val >= 10)
		c = 'A' + val - 10;
	else
		return ('\n');
	return (c);
}

char		*ft_itoa_base(int value, int base)
{
	char			*str;
	int				len;
	int				i;
	unsigned int	nb;

	nb = value;
	len = res_len(value, base);
	i = 0;
	if (value < 0)
		nb = -value;
	str = ft_strnew(len);
	str[0] = value < 0 && base == 10 ? '-' : '0';
	while (i < len - (value < 0 && base == 10))
	{
		str[len - i - 1] = to_char(nb % base);
		nb /= base;
		i++;
	}
	return (str);
}
