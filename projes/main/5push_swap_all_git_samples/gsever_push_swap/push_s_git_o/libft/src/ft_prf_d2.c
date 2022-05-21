/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_d2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 18:24:55 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 19:10:15 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	u_res_len(uintmax_t nb)
{
	int				len;

	len = 0;
	if (!nb)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char			*ft_prf_uitoa(uintmax_t nb, int prec)
{
	char			*str;
	int				len;
	int				i;
	int				zeros;

	len = d_res_len(nb);
	zeros = prec - len;
	str = ft_prf_strnew(len + zeros);
	str[0] = '0';
	i = 0;
	while (i < (zeros + !nb))
		str[i++] = '0';
	i = prec - 1;
	while (nb != 0)
	{
		str[i] = '0' + nb % 10;
		nb /= 10;
		i--;
	}
	str[len + zeros] = 0;
	return (str);
}

void			uwriteandfree(uintmax_t nb, int prec)
{
	char	*str;

	str = ft_prf_uitoa(nb, prec);
	write(1, str, prec);
	free(str);
}

int				prf_u_type(uintmax_t nb, const t_format *opt)
{
	int		prec;
	int		printed;
	int		spaces;
	int		stop;

	stop = (opt->prec == -1 && !nb);
	prec = max(u_res_len(nb), opt->prec) * !stop;
	if (contains(opt->flags, '0') && !(opt->prec))
		prec = max(opt->width, d_res_len(nb)) -
				contains(opt->flags, ' ');
	spaces = (opt->width) - prec;
	printed = prec + spaces * (spaces > 0);
	if (!contains(opt->flags, '-'))
		putnchar(spaces, ' ');
	if (!stop)
		uwriteandfree(nb, prec);
	if (contains(opt->flags, '-'))
		putnchar(spaces, ' ');
	return (printed);
}
