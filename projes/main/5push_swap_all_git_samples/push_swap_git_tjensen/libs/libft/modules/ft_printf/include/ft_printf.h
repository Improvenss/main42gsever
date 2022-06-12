/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 23:14:31 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/15 19:28:38 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_print
{
	va_list	args;
	bool	dash;
	bool	zero;
	bool	hashtag;
	bool	space;
	bool	plus;
	char	sign;
	char	pad_chr;
	int		width;
	int		precision;
	bool	prec_iszero;
	size_t	digits;
	int		len_total;
}	t_print;

int		ft_printf(const char *format, ...);
t_print	*ft_specs_reset(t_print *t_spec);
t_print	*ft_specs_init(t_print *t_spec);

int		ft_print_formated(t_print *t_spec, const char *format, int pos);
int		ft_conversion(t_print *t_spec, const char *format, int pos);

void	ft_print_char(t_print *t_spec, char c);
void	ft_print_string(t_print *t_spec, char *s);
void	ft_print_int(t_print *t_spec, int i);
void	ft_print_unsigned_int(t_print *t_spec, unsigned int i);
void	ft_print_fnbr(t_print *t_spec, u_long i);
void	ft_print_pointer(t_print *t_spec, u_long ul);
void	ft_print_hex(t_print *t_spec, char *base, u_int ui);
void	ft_print_fbase(t_print *t_spec, char *base, u_long ul);

void	ft_print_null(t_print *t_spec);
void	ft_print_chars(t_print *t_spec, char c, int n);
void	ft_print_signs(t_print *t_spec, char *base);
void	ft_set_prec_width(t_print *t_spec, u_long ul);

int		ft_eval_dash(t_print *t_spec, int pos);
int		ft_eval_zero(t_print *t_spec, int pos);
int		ft_eval_precision(t_print *t_spec, const char *format, int pos);
int		ft_eval_hashtag(t_print *t_spec, int pos);
int		ft_eval_space(t_print *t_spec, int pos);
int		ft_eval_plus(t_print *t_spec, int pos);
int		ft_eval_width(t_print *t_spec, const char *format, int pos);

#endif
