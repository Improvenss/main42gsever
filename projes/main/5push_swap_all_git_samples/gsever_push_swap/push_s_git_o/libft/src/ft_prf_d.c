/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_d.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 18:24:55 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 19:08:43 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	d_res_len(intmax_t value)
{
	int				len;
	uintmax_t		nb;

	len = 0;
	if (value < 0)
	{
		nb = -value;
		len++;
	}
	else
		nb = value;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	if (value == 0)
		len = 1;
	return (len);
}

char			*ft_prf_itoa(intmax_t value, int prec)
{
	char			*str;
	int				len;
	int				i;
	uintmax_t		nb;
	int				zeros;

	len = d_res_len(value);
	zeros = prec - len + (value <= 0);
	nb = value < 0 ? -value : value;
	str = ft_prf_strnew(len + zeros);
	str[0] = value < 0 ? '-' : '0';
	i = value < 0;
	while (i < (zeros + (value < 0)))
		str[i++] = '0';
	i = (value < 0) + prec - 1;
	while (nb != 0)
	{
		str[i] = '0' + nb % 10;
		nb /= 10;
		i--;
	}
	str[len + zeros] = 0;
	return (str);
}

void			writeandfree(intmax_t nb, int prec)
{
	char	*str;

	str = ft_prf_itoa(nb, prec);
	write(1, str, prec + (nb < 0));
	free(str);
}

int				prf_d_type(intmax_t nb, const t_format *opt)
{
	int		prec;
	int		printed;
	int		spaces;
	int		stop;

	stop = (opt->prec == -1 && !nb);
	prec = max(d_res_len(nb) - (nb < 0), opt->prec) * !stop;
	if (contains(opt->flags, '0') && !contains(opt->flags, '-') && !(opt->prec))
		prec = max(opt->width - (nb < 0), d_res_len(nb) - (nb < 0)) -
				contains(opt->flags, ' ');
	spaces = (opt->width) - prec - (nb < 0);
	printed = prec + spaces * (spaces > 0) + (nb < 0);
	spaces -= (contains(opt->flags, '+') && nb >= 0);
	if (contains(opt->flags, ' ') && spaces <= 0 && nb >= 0
		&& !contains(opt->flags, '+'))
		printed += putnchar(1, ' ');
	putnchar(spaces * !contains(opt->flags, '-'), ' ');
	putnchar((contains(opt->flags, '+') && nb >= 0), '+');
	if (prec == opt->width && contains(opt->flags, '+') && nb >= 0)
		prec-- && printed--;
	printed += ((contains(opt->flags, '+') && nb >= 0 && spaces <= 0));
	if (!stop)
		writeandfree(nb, prec);
	putnchar(spaces * contains(opt->flags, '-'), ' ');
	return (printed);
}

int				prf_d(va_list args, const t_format *opt)
{
	if (opt->type == 'j' && (opt->tag == 'd' || opt->tag == 'i'))
		return (prf_d_type(va_arg(args, intmax_t), opt));
	if (opt->type == 'h' && opt->tag == 'u')
		return (prf_d_type((unsigned short)va_arg(args, intmax_t), opt));
	if (opt->type == 'i' && opt->tag == 'u')
		return (prf_d_type((unsigned char)va_arg(args, intmax_t), opt));
	if (opt->type == 'h' && (opt->tag == 'd' || opt->tag == 'i'))
		return (prf_d_type((intmax_t)(short)va_arg(args, int), opt));
	if (opt->type == 'i' && (opt->tag == 'd' || opt->tag == 'i'))
		return (prf_d_type((intmax_t)(signed char)va_arg(args, int), opt));
	else if ((opt->type == 'j') && opt->tag == 'u')
		return (prf_u_type(va_arg(args, uintmax_t), opt));
	else if (opt->type == 'k' && (opt->tag == 'd' || opt->tag == 'i'))
		return (prf_d_type((intmax_t)va_arg(args, long long), opt));
	else if (opt->tag == 'D' || (opt->type == 'l' &&
			(opt->tag == 'd' || opt->tag == 'i')))
		return (prf_d_type((intmax_t)va_arg(args, long), opt));
	else if ((opt->type == 'z' && (opt->tag == 'd' || opt->tag == 'i')))
		return (prf_d_type((intmax_t)va_arg(args, size_t), opt));
	else if ((opt->type == 0 && opt->tag == 'u'))
		return (prf_u_type((uintmax_t)va_arg(args, unsigned int), opt));
	else if (opt->tag == 'U' || (((opt->type == 'l' || opt->type == 'k') ||
			opt->type == 'z') && opt->tag == 'u'))
		return (prf_u_type((uintmax_t)va_arg(args, unsigned long long), opt));
	return (prf_d_type((intmax_t)va_arg(args, int), opt));
}
