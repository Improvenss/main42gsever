/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:40:21 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/15 19:28:12 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int(t_print *t_spec, int i)
{
	t_spec->digits = ft_get_numlen(i);
	if (i < 0)
		t_spec->sign = '-';
	else if (!t_spec->plus && t_spec->space)
		t_spec->len_total += write(1, " ", 1);
	ft_print_fbase(t_spec, BASE10, ft_abs(i));
}

void	ft_print_unsigned_int(t_print *t_spec, u_int ui)
{
	t_spec->digits = ft_get_unumlen(ui);
	if (!t_spec->plus && t_spec->space)
		t_spec->len_total += write(1, " ", 1);
	ft_print_fbase(t_spec, BASE10, ui);
}
