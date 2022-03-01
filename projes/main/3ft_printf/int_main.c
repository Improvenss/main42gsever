/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:25:03 by gsever            #+#    #+#             */
/*   Updated: 2022/03/01 14:12:30 by gsever           ###   ########.fr       */
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
	char *str1 = "gorkem";
	char *str2 = "sever";
	char *str3 = "42";
	char *str4 = "";
	
	printf("orginal_s_times:%d\n", printf("org:%s, %s, %s, |%s|\n", str1, str2, str3, str4));
	ft_printf("ft_s_times:%d\n", ft_printf("ft_:%s, %s, %s, |%s|\n", str1, str2, str3, str4));
}
/*
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
*/
void ft_test_d(void)
{
	int i = 35;
	char c = 'a';
	char s[] = "abc";

	printf("original_d_times:%d\n\n", printf("int:%d\nchar:%d\nstring:%d\n", i, c, s[1]));
	ft_printf("function_d_times:%d\n", ft_printf("int:%d\nchar:%d\nstring:%d\n", i, c, s[1]));
}

void ft_test_i(void)
{
	int	a, b, c;
 
	ft_printf("Enter value of a in decimal format (%%d):");
	scanf("%d", &a);

	ft_printf("Enter value of b in octal format(%%i):");
	scanf("%i", &b);

	ft_printf("Enter value of c in hexadecimal format(%%x):");
	scanf("%x", &c);

	printf("original_i_times:%d\n", ft_printf("a = %i, b = %i, c = %i\n", a, b, c));
	ft_printf("function_i_times:%d\n", ft_printf("a = %i, b = %i, c = %i\n", a, b, c));
}
/*
void ft_test_u(void)
{
	int i = 35;
	char c = 'a';
	char s[] = "abc";

	printf("original_u_times:%d\n\n", printf("int:%d\nchar:%d\nstring:%d\n", i, c, s[1]));
	ft_printf("function_u_times:%d\n", ft_printf("int:%d\nchar:%d\nstring:%d\n", i, c, s[1]));
}
*/