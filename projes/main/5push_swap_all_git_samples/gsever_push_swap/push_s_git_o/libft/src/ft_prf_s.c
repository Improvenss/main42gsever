/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_s.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 17:11:07 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 08:00:32 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			prf_s(char *str, const t_format *opt)
{
	int		spaces;
	int		zero;
	int		len;

	len = str ? ft_prf_strlen(str) : 6;
	len = opt->prec < len && opt->prec ? opt->prec : len * (opt->prec != -1);
	zero = contains(opt->flags, '0') ? '0' : ' ';
	len = len < 0 ? 0 : len;
	spaces = (((opt->width) - len) * (((opt->width) - len) > 0));
	putnchar(spaces * !contains(opt->flags, '-'), zero);
	if (!str && opt->prec != -1)
		write(1, "(null)", len);
	else if (opt->prec != -1)
		write(1, str, len);
	putnchar(spaces * contains(opt->flags, '-'), zero);
	return (len + spaces);
}

int			get_wlen(wchar_t *wstr, int prec)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (wstr && wstr[i])
	{
		len += get_nbytes(wstr[i]);
		i++;
	}
	len = wstr ? len : 0;
	len = prec < len && prec ? prec : len * (prec != -1);
	return (len);
}

int			trunc_swlen(wchar_t *wstr, int len)
{
	int		tlen;
	int		i;

	i = 0;
	tlen = 0;
	if (len == -1)
		return (-1);
	while (wstr && wstr[i] &&
		(tlen + get_nbytes(wstr[i])) <= (unsigned long)len)
		tlen += get_nbytes(wstr[i++]);
	tlen = wstr ? tlen : 0;
	return (tlen);
}

int			prf_bigs(va_list args, const t_format *opt)
{
	int		spaces;
	int		zero;
	int		len;
	wchar_t	*wstr;

	wstr = va_arg(args, wchar_t*);
	len = get_wlen(wstr, opt->prec);
	zero = contains(opt->flags, '0') ? '0' : ' ';
	spaces = (((opt->width) - trunc_swlen(wstr, len)) *
			(((opt->width) - trunc_swlen(wstr, len)) > 0));
	putnchar(spaces * !contains(opt->flags, '-') - (opt->prec == -1), zero);
	if (!wstr && opt->prec != -1)
		write(1, "(null)", 6);
	else if (opt->prec != -1)
		len = ft_putwstr(wstr, len);
	putnchar(spaces * contains(opt->flags, '-'), zero);
	return (wstr ? len + spaces : 6 + spaces);
}
