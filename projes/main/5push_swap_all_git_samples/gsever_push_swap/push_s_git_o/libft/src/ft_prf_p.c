/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_p.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 13:17:24 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 19:12:22 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				prf_p(void *ptr, const t_format *opt)
{
	int			sp;
	int			len;
	int			hlen;
	int			prec;
	char		*str;

	hlen = res_len((uintmax_t)ptr, 16);
	prec = opt->width && contains(opt->flags, '0') && (opt->prec == 0) ?
	opt->width - 2 : opt->prec;
	len = hlen < prec ? prec : hlen * (prec != -1);
	sp = (opt->width - len - 2) * ((opt->width - len - 2) > 0);
	sp = !(opt->width && contains(opt->flags, '0') && opt->prec == 0) * sp;
	if (!ptr)
		return (putnchar(sp * !contains(opt->flags, '-'), ' ') +
				putnstr("0x", 0, 2) +
				putnchar(len, '0') +
				putnchar(sp * contains(opt->flags, '-'), ' '));
		putnchar(sp * !contains(opt->flags, '-'), ' ');
	putnstr("0x", 0, 2);
	str = ft_prf_itoa_x((uintmax_t)ptr, 0, len);
	write(1, str, len);
	free(str);
	putnchar(sp * contains(opt->flags, '-'), ' ');
	return (len + 2 + sp);
}
