/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:25:26 by gsever            #+#    #+#             */
/*   Updated: 2022/03/04 16:40:55 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

# define SPECIFIERS	"cspdiuxX%"

//utils
int	ft_printf(const char *format, ...);
int	ft_print_char(const int c);
int	ft_print_string(const char *str);
int	ft_print_decimal(int dec);
int	ft_print_pointer(unsigned long long address);
int	ft_print_udecimal(unsigned int value);
int	ft_print_hex(unsigned int value, const char format);
int	ft_print_percent(void);
//bonus
int	ft_check_flag(va_list arg, const char *format);
//write_flags
int	ft_write_flag_space(va_list arg, const char *format);
int	ft_write_flag_zero(long long number);
int	ft_write_flag_pos_neg(long long number);

#endif
