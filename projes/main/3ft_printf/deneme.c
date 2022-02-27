/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deneme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:25:03 by gsever            #+#    #+#             */
/*   Updated: 2022/02/27 16:45:42 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_test_c(void)
{
	char	a;
	char	b;
	char	c;

	a = 'a';
	b = 'b';
	c = 'c';
	printf("orginal_s_times:%d\n", printf("org:%c, %c, %c\n", a, b, c));
	printf("ft_s_times:%d\n", ft_printf("ft_:%c, %c, %c\n", a, b, c));
}

void ft_test_s(void)
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;

	str1 = "gorkem";
	str2 = "sever";
	str3 = "42";
	str4 = "";
	//printf("orginal_s_times:%d\n", printf("org:%s, %s, %s, |%s|\n", str1, str2, str3, str4));
	ft_printf("ft_:%s, %s, %s, |%s|\n", str1, str2, str3, str4);
}

void ft_test_p(void)
{
	char ptr1;
	char ptr2;
	char ptr3;

	ptr1 = 'g';
	ptr2 = 's';
	ptr3 = '4';
	printf("orginal_p_times:%d\n", printf("org:%p, %p, %p\n", ptr1, ptr2, ptr3));
	ft_printf("ft_p_times:%d\n", ft_printf("ft_:%p, %p, %p\n", ptr1, ptr2, ptr3));
}
