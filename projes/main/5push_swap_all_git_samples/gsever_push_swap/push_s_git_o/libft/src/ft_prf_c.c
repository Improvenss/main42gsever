/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_c.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 17:11:07 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 15:10:44 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		get_nbytes(wchar_t c)
{
	int		len;

	len = bitlen(c);
	if (len > 16)
		return (4);
	else if (len > 11)
		return (3);
	else if (len > 7)
		return (2);
	else
		return (1);
}

int			prf_c(va_list args, const t_format *opt)
{
	int		spaces;
	int		zero;
	int		ch;
	int		nb;

	nb = 1;
	if (opt->tag == 'C' || opt->type == 'l')
		ch = va_arg(args, wchar_t);
	else
		ch = va_arg(args, int);
	zero = contains(opt->flags, '0') ? '0' : ' ';
	spaces = ((opt->width) - (int)get_nbytes((wchar_t)ch)) *
	(((opt->width) - (int)get_nbytes(ch)) > 0);
	putnchar(spaces * !contains(opt->flags, '-'), zero);
	if (opt->tag == 'C' || opt->type == 'l')
		nb = ft_putwchar(ch);
	else
		write(1, &ch, 1);
	putnchar(spaces * contains(opt->flags, '-'), zero);
	return (nb + spaces);
}
