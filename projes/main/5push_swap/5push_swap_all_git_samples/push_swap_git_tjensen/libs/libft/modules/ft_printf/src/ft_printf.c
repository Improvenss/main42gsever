/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 23:12:50 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/15 19:28:58 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	t_print	*t_spec;

	t_spec = malloc(sizeof(t_print));
	if (!t_spec)
		return (-1);
	ft_specs_init(t_spec);
	va_start(t_spec->args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_print_formated(t_spec, format, i + 1);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	count += t_spec->len_total;
	va_end(t_spec->args);
	free(t_spec);
	return (count);
}

t_print	*ft_specs_init(t_print *t_spec)
{
	t_spec->dash = false;
	t_spec->zero = false;
	t_spec->hashtag = false;
	t_spec->space = false;
	t_spec->plus = false;
	t_spec->sign = 0;
	t_spec->pad_chr = ' ';
	t_spec->width = 0;
	t_spec->precision = 0;
	t_spec->prec_iszero = false;
	t_spec->digits = 0;
	t_spec->len_total = 0;
	return (t_spec);
}

t_print	*ft_specs_reset(t_print *t_spec)
{
	t_spec->dash = false;
	t_spec->zero = false;
	t_spec->hashtag = false;
	t_spec->space = false;
	t_spec->plus = false;
	t_spec->sign = 0;
	t_spec->pad_chr = ' ';
	t_spec->width = 0;
	t_spec->precision = 0;
	t_spec->prec_iszero = false;
	t_spec->digits = 0;
	return (t_spec);
}
