/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:25:40 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/15 19:28:12 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_formated(t_print *t_spec, const char *format, int pos)
{
	while (ft_strchr("-0.# +", format[pos]) || ft_isdigit(format[pos]))
	{
		if (format[pos] == '-')
			pos = ft_eval_dash(t_spec, pos);
		else if (format[pos] == '0')
			pos = ft_eval_zero(t_spec, pos);
		else if (format[pos] == '.')
			pos = ft_eval_precision(t_spec, format, pos + 1);
		else if (format[pos] == '#')
			pos = ft_eval_hashtag(t_spec, pos);
		else if (format[pos] == ' ')
			pos = ft_eval_space(t_spec, pos);
		else if (format[pos] == '+')
			pos = ft_eval_plus(t_spec, pos);
		else if (ft_isdigit(format[pos]))
			pos = ft_eval_width(t_spec, format, pos);
	}
	if (ft_strchr("csdiupxX%", format[pos]))
		pos = ft_conversion(t_spec, format, pos);
	else
		pos--;
	ft_specs_reset(t_spec);
	return (pos);
}

int	ft_conversion(t_print *t_spec, const char *format, int pos)
{
	if (format[pos] == 'c')
		ft_print_char(t_spec, va_arg(t_spec->args, int));
	else if (format[pos] == 's')
		ft_print_string(t_spec, va_arg(t_spec->args, char *));
	else if (format[pos] == 'd' || format[pos] == 'i')
		ft_print_int(t_spec, va_arg(t_spec->args, int));
	else if (format[pos] == 'u')
		ft_print_unsigned_int(t_spec, va_arg(t_spec->args, unsigned int));
	else if (format[pos] == 'p')
		ft_print_pointer(t_spec, (unsigned long)va_arg(t_spec->args, void *));
	else if (format[pos] == 'x')
		ft_print_hex(t_spec, BASE16_L, va_arg(t_spec->args, unsigned int));
	else if (format[pos] == 'X')
		ft_print_hex(t_spec, BASE16_U, va_arg(t_spec->args, unsigned int));
	else if (format[pos] == '%')
		ft_print_char(t_spec, '%');
	return (pos);
}
