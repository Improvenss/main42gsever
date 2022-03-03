/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:25:26 by gsever            #+#    #+#             */
/*   Updated: 2022/03/02 22:46:34 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"
//utils
int	ft_printf(const char *format, ...);
int	ft_print_char(const int c);
int	ft_print_string(const char *str);
int	ft_print_decimal(int dec);
//int	ft_print_decimal_to_octal(int dec);
int	ft_print_pointer(unsigned long long address);
int	ft_print_udecimal(unsigned int value);
int	ft_print_hex(unsigned int value, const char format);
//int	ft_hexadecimal_len(unsigned long long number);
int	ft_print_percent(void);

#endif
