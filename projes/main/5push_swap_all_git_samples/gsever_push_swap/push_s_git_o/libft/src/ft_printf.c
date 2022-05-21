/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 13:54:24 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 19:03:22 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			putnstr(const char *str, int beg, int end)
{
	write(1, str + beg, end - beg);
	return (end - beg);
}

void		init_format(t_format **format)
{
	if (*(format) && ((*format)->flags) != NULL)
		free((*format)->flags);
	if (!(*format) && !(*format = (t_format*)malloc(sizeof(t_format))))
		return ;
	(*format)->flags = NULL;
	(*format)->width = 0;
	(*format)->prec = 0;
	(*format)->type = 0;
}

void		scan_format(t_format **form, char *opt)
{
	int				i;

	init_format(form);
	i = 1;
	while (opt[i] && isflag(opt[i]))
		i++;
	(*form)->flags = isflag(opt[1]) ? ft_prf_strsub(opt, 1, i - 1) : NULL;
	(*form)->width = ft_prf_atoi(opt + i);
	while (opt[i] && isnum(opt[i]))
		i++;
	(*form)->prec = opt[i] && opt[i] == '.' ? ft_prf_atoi(opt + i + 1) : 0;
	(*form)->prec = (opt[i] == '.' && (*form)->prec == 0) ? -1 : (*form)->prec;
	i += opt[i] == '.';
	while (opt[i] && isnum(opt[i]))
		i++;
	(*form)->type = get_type(opt);
	if (((*form)->type))
		i += 1 + (((*form)->type == 'i') || ((*form)->type == 'k'));
	(*form)->tag = opt[i];
}

int			ft_printf(const char *format, ...)
{
	int			i;
	va_list		args;
	int			ret;
	t_format	*form;

	ret = 0;
	form = NULL;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		ret += putnstr(format, i, getprct((char*)format, i));
		i = getprct((char*)format, i);
		if (format[i])
		{
			scan_format(&form, (char*)format + i);
			ret += launch(args, form);
		}
		i += format_len((char*)format + i);
	}
	init_format(&form);
	free(form);
	va_end(args);
	return (ret);
}
