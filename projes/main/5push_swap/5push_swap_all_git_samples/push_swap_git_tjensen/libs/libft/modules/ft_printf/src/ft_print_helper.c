/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:37:14 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/15 19:28:12 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_fbase(t_print *t_spec, char *base, u_long ul)
{
	if (t_spec->prec_iszero || t_spec->precision > 0)
		t_spec->zero = false;
	ft_set_prec_width(t_spec, ul);
	if (!t_spec->dash && (!t_spec->zero || t_spec->precision))
		ft_print_chars(t_spec, ' ', t_spec->width);
	ft_print_signs(t_spec, base);
	if (t_spec->zero && !t_spec->precision)
		ft_print_chars(t_spec, '0', t_spec->width);
	ft_print_chars(t_spec, '0', t_spec->precision);
	if (!(ul == 0 && t_spec->prec_iszero))
		t_spec->len_total += ft_putnbr_base_fd(ul, base, STDOUT_FILENO);
	if (t_spec->dash && (!t_spec->zero || t_spec->precision))
		ft_print_chars(t_spec, ' ', t_spec->width);
}

void	ft_print_signs(t_print *t_spec, char *base)
{
	if (t_spec->sign && ft_strlen(base) != 16)
		t_spec->len_total += write(1, &t_spec->sign, 1);
	else if (t_spec->hashtag && !ft_strncmp(base, BASE16_L, 16))
		t_spec->len_total += write(1, "0x", 2);
	else if (t_spec->hashtag && !ft_strncmp(base, BASE16_U, 16))
		t_spec->len_total += write(1, "0X", 2);
}

void	ft_set_prec_width(t_print *t_spec, u_long ul)
{
	if (t_spec->sign == '-')
		t_spec->digits--;
	t_spec->precision = t_spec->precision - t_spec->digits;
	if (t_spec->precision < 0)
		t_spec->precision = 0;
	t_spec->width -= t_spec->precision + t_spec->digits;
	t_spec->width -= (t_spec->plus || t_spec->space || t_spec->sign == '-');
	if (t_spec->width < 0)
		t_spec->width = 0;
	else if (ul == 0 && t_spec->prec_iszero)
		t_spec->width++;
}

void	ft_print_null(t_print *t_spec)
{
	int	i;

	if (t_spec->precision > 0 && t_spec->precision < 6)
		i = t_spec->precision;
	else
		i = 6;
	t_spec->len_total += write(1, "(null)", i);
}

void	ft_print_chars(t_print *t_spec, char c, int n)
{
	while (n > 0)
	{
		t_spec->len_total += write(1, &c, 1);
		n--;
	}
}
