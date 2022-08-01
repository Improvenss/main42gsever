/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:37:57 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/15 19:28:12 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_pointer(t_print *t_spec, u_long ul)
{
	t_spec->digits = ft_get_unumlen_base(ul, 16);
	t_spec->width -= t_spec->digits + 2;
	if (ul == 0 && t_spec->prec_iszero)
		t_spec->width++;
	if (t_spec->pad_chr == '0' || t_spec->dash)
		t_spec->len_total += write(1, "0x", 2);
	if (t_spec->width > 0 && (!t_spec->dash || t_spec->pad_chr == '0'))
		ft_print_chars(t_spec, t_spec->pad_chr, t_spec->width);
	if (t_spec->pad_chr == ' ' && !t_spec->dash)
		t_spec->len_total += write(1, "0x", 2);
	if (!(ul == 0 && t_spec->prec_iszero))
		t_spec->len_total += ft_putunbr_base_fd(ul, BASE16_L, STDOUT_FILENO);
	if (t_spec->width > 0 && t_spec->dash)
		ft_print_chars(t_spec, ' ', t_spec->width);
}

void	ft_print_hex(t_print *t_spec, char *base, u_int ui)
{
	if (ui == 0)
		t_spec->hashtag = 0;
	if (t_spec->hashtag)
		t_spec->width -= 2;
	t_spec->digits = ft_get_numlen_base(ui, 16);
	ft_print_fbase(t_spec, base, ui);
}
