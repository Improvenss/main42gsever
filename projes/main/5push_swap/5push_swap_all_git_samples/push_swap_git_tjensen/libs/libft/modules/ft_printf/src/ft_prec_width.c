/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:48:51 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/15 19:28:12 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_eval_precision(t_print *t_spec, const char *format, int pos)
{
	int	i;

	if (ft_isdigit(format[pos]))
	{
		i = (int)ft_atol(&format[pos]);
		if (i == 0)
			t_spec->prec_iszero = true;
		t_spec->precision = i;
		i = 0;
		while (ft_isdigit(format[pos + i]))
			i++;
		return (pos + i);
	}
	else
	{
		t_spec->prec_iszero = true;
		return (pos);
	}
}

int	ft_eval_width(t_print *t_spec, const char *format, int pos)
{
	t_spec->width = (int)ft_atol(&format[pos]);
	return (pos + ft_get_unumlen(t_spec->width));
}
