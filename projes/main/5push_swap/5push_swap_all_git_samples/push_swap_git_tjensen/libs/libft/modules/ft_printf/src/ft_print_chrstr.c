/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chrstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:45:21 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/15 19:28:12 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_char(t_print *t_spec, char c)
{
	if (t_spec->width && !t_spec->dash)
		ft_print_chars(t_spec, t_spec->pad_chr, t_spec->width - 1);
	t_spec->len_total += write(1, &c, 1);
	if (t_spec->width && t_spec->dash)
		ft_print_chars(t_spec, ' ', t_spec->width - 1);
}

void	ft_print_string(t_print *t_spec, char *s)
{
	t_spec->digits = ft_strlen(s);
	if (t_spec->precision != 0 && (size_t)t_spec->precision < t_spec->digits)
		t_spec->digits = t_spec->precision;
	else if (t_spec->prec_iszero)
		t_spec->digits = 0;
	if (s == NULL && t_spec->precision >= 6)
		t_spec->width -= 6;
	else if (s == NULL && !t_spec->precision && !t_spec->prec_iszero)
		t_spec->width -= 6;
	else if (s == NULL && t_spec->precision < 6)
		t_spec->width -= t_spec->precision;
	if (t_spec->width && (!t_spec->dash || t_spec->prec_iszero))
		ft_print_chars(t_spec, t_spec->pad_chr, t_spec->width - t_spec->digits);
	if (t_spec->prec_iszero)
		return ;
	else if (s == NULL)
		ft_print_null(t_spec);
	else
		t_spec->len_total += write(1, s, t_spec->digits);
	if (t_spec->width && t_spec->dash)
		ft_print_chars(t_spec, ' ', t_spec->width - t_spec->digits);
}
