/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:25:26 by gsever            #+#    #+#             */
/*   Updated: 2022/03/01 13:01:25 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

int	ft_printf(const char *, ...);
int	ft_print_char(const int c);
int	ft_print_string(const char *str);
int	ft_print_decimal(const long dec);
int	ft_decimal_to_octal(long dec);

#endif