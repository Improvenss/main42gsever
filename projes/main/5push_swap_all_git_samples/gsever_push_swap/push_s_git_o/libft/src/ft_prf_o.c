/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_o.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 13:17:24 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 18:49:08 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_prf_itoa_o(uintmax_t nb, int maj, int prec)
{
	char			*str;
	int				len;
	int				i;
	int				zeros;

	len = res_len(nb, 8);
	zeros = prec - len;
	i = 0;
	str = ft_prf_strnew(len + zeros);
	str[0] = '0';
	while (i < (zeros + !nb))
		str[i++] = '0';
	i = prec - 1;
	while (nb != 0)
	{
		str[i] = to_char(nb % 8, maj);
		nb /= 8;
		i--;
	}
	str[len + zeros] = 0;
	return (str);
}

int				subprf_o_type(uintmax_t nb, const t_format *opt, int prec,
				int spaces)
{
	int		printed;
	char	*tofree;

	tofree = NULL;
	if (!contains(opt->flags, '-'))
		putnchar(spaces, ' ');
	printed = 0;
	if (contains(opt->flags, '#') &&
	(tofree = ft_prf_itoa_o(nb, opt->tag == 'O', prec))[0] != '0')
		printed += write(1, "0", 1);
	if (tofree != NULL)
		free(tofree);
	return (printed);
}

int				prf_o_type(uintmax_t nb, const t_format *opt)
{
	int		prec;
	int		printed;
	int		spaces;
	int		stop;
	char	*tofree;

	tofree = NULL;
	stop = (opt->prec == -1 && !nb);
	prec = max(res_len(nb, 8), opt->prec) * !stop;
	if (contains(opt->flags, '0') && !contains(opt->flags, '-') && !(opt->prec))
		prec = max(opt->width, res_len(nb, 8)) - contains(opt->flags, ' ');
	spaces = (opt->width) - prec;
	if (contains(opt->flags, '#') &&
	(tofree = ft_prf_itoa_o(nb, opt->tag == 'O', prec))[0] != '0')
		spaces--;
	tofree ? free(tofree) : tofree;
	printed = prec + spaces * (spaces > 0);
	printed += subprf_o_type(nb, opt, prec, spaces);
	if (!stop)
		write(1, (tofree = ft_prf_itoa_o(nb, opt->tag == 'O', prec)), prec);
	if (contains(opt->flags, '-'))
		putnchar(spaces, ' ');
	if (!stop)
		free(tofree);
	return (printed);
}

int				prf_o(va_list args, const t_format *opt)
{
	if (opt->type == 'j')
		return (prf_o_type(va_arg(args, uintmax_t), opt));
	else if (opt->type == 'h')
		return (prf_o_type((unsigned short)va_arg(args, int), opt));
	else if (opt->type == 'i' && opt->tag == 'O')
		return (prf_o_type((unsigned short)va_arg(args, int), opt));
	else if (opt->type == 'i')
		return (prf_o_type((unsigned char)va_arg(args, int), opt));
	else if (opt->type == 'k')
		return (prf_o_type((uintmax_t)va_arg(args, long long), opt));
	else if (opt->type == 'l' || opt->tag == 'O')
		return (prf_o_type((uintmax_t)va_arg(args, long), opt));
	else if (opt->type == 'z')
		return (prf_o_type((uintmax_t)va_arg(args, unsigned long long), opt));
	else
		return (prf_o_type((uintmax_t)va_arg(args, unsigned int), opt));
}
