/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:25:03 by gsever            #+#    #+#             */
/*   Updated: 2022/03/04 17:43:08 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//testing char
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
//testing string
void ft_test_s(void)
{
	char *str1 = "gorkem";
	char *str2 = "sever";
	char *str3 = "42";
	char *str4 = "";
	
	printf("orginal_s_times:%d\n", printf("org:%s, %s, %s, |%s|\n", str1, str2, str3, str4));
	ft_printf("ft_s_times:%d\n", ft_printf("ft_:%s, %s, %s, |%s|\n", str1, str2, str3, str4));
}
//testing write pointer's adress
void ft_test_p(void)
{
	int	ptr1, ptr2, ptr3;
 
	ft_printf("Enter value of a in decimal format (%%d):");
	scanf("%d", &ptr1);

	ft_printf("Enter value of b in octal format(%%i):");
	scanf("%i", &ptr2);

	ft_printf("Enter value of c in hexadecimal format(%%x):");
	scanf("%x", &ptr3);

	printf("orginal_p_times:%d\n", printf("org:%p, %p, %p\n", &ptr1, &ptr2, &ptr3));
	ft_printf("ft_p_times:%d\n", ft_printf("ft_:%p, %p, %p\n", &ptr1, &ptr2, &ptr3));
}
//testing decimal value
void ft_test_d(void)
{
	int i = 35;
	char c = 'a';
	char s[] = "abc";

	printf("original_d_times:%d\n\n", printf("int:%d\nchar:%d\nstring:%d\n", i, c, s[1]));
	ft_printf("function_d_times:%d\n", ft_printf("int:%d\nchar:%d\nstring:%d\n", i, c, s[1]));
}
//testind octal value amk pirintf'i ayni boku yapiyor
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
//testing unsigned decimal
void ft_test_u(void)
{
	unsigned int i = 35;
	char c = 'a';
	char s[] = "abc";

	printf("original_u_times:%d\n\n", printf("int:%u\nchar:%u\nstring:%u\n", i, c, s[1]));
	ft_printf("function_u_times:%d\n", ft_printf("int:%u\nchar:%u\nstring:%u\n", i, c, s[1]));
}
//testing hexadecimal 'x' test
void ft_test_x(void)
{
	int	a, b, c;
 
	ft_printf("Enter value of a in decimal format (%%d):");
	scanf("%d", &a);

	ft_printf("Enter value of b in octal format(%%i):");
	scanf("%i", &b);

	ft_printf("Enter value of c in hexadecimal format(%%x):");
	scanf("%x", &c);

	printf("orginal_p_times:%d\n", printf("org:%x, %x, %x\n", a, b, c));
	ft_printf("ft_p_times:%d\n", ft_printf("ft_:%x, %x, %x\n", a, b, c));
}
//testing hexadecimal 'X' test
void ft_test_X(void)
{
	int	a, b, c;
 
	ft_printf("Enter value of a in decimal format (%%d):");
	scanf("%d", &a);

	ft_printf("Enter value of b in octal format(%%i):");
	scanf("%i", &b);

	ft_printf("Enter value of c in hexadecimal format(%%x):");
	scanf("%x", &c);

	printf("orginal_p_times:%d\n", printf("org:%X, %X, %X\n", a, b, c));
	ft_printf("ft_p_times:%d\n", ft_printf("ft_:%X, %X, %X\n", a, b, c));
}
//	2 tane arka arkaya yuzde varsa % yaz.
void ft_test_percent(void)
{
	printf("org_print_percent test --> %%|%%|%%\n");
	ft_printf("ft_print_percent test  --> %%|%%|%%\n");
}

/*************************************************************************** */
/*
	[w]	-- Genisligini veriyoruz o genislik kadar yazdirma yapiyoruz --
Steps:
	1 - genisligimizi alalim
	2 - bu genisligimiz kadar + 1 fazlasi kadar 
mallocla alan acalim yine sonuna \0 ekleyecegiz
	3 - if(parametre) -, +, 0, 
*/
void ft_test_bonus_width(void)
{
	printf("original:|%5d|", 123);
	//ft_printf("function:|%5d|", 123);
}

/*
	[-]	(%-5d)	Eger 5'in basinda - varsa yazilarimizi sola yapistiriyor.
	ornek --> printf("|%-5d|", 123); --> |123  | oluyor.
*/
void ft_test_bonus_left(void)
{
	printf("|%-5d|", 123);
}
/*
	[+]	(%+5d)	Eger 5'in basinda + varsa sayimizin pozitif/negatif gore + -
					pozitifse = +		koyuyor.
		ornek --> printf("|%+5d|", 123); --> | +123| oluyor.
					negatifse = -		koyuyor.
		ornek --> printf("|%+5d|", -123); --> | -123| oluyor.
*/
void ft_test_bonus_plus(void)
{
	printf("|%+5d|", 123);
	printf("|%+5d|", -123);
}

/*
	[0]	(%05s)	Eger 5'in basinda 0 (SIFIR) varsa bosluklar yerine 0 koyuyor.
	ornek --> printf("|%5s|", "abc"); --> |00abc| oluyor.
*/
void ft_test_bonus_zero(void)
{
	printf("|%5s|", "abc");
}
/*
	[#]	(%#5d)	Eger 5'in basinda # varsa hexadecimal yazdirilan yani x - X
	ile ciktisi istenilen ciktinin basina 0x - 0X koyuyor. #'siz yazdigimizda 
	sadece hex hali yaziliyor. (Adres yazdirir gibi)
				-- Sadece x, X, p ile kullanilabilinir. Bunlar hex cikiyor.
									p haricmis...
		ornek --> printf("|%#5x|", 123); --> | 0x7b| oluyor.
		ornek --> printf("|%#5X|", 123); --> | 0X7B| oluyor.
*/
void ft_test_bonus_hashtag(void)
{
	printf("|%#5x|", 123);
	printf("|%#5X|", 123);
}
/*
	[ ]	(% 5s)	
*/
void ft_test_bonus_space(void)
{
	
}
/*
	[.]	(%.5f)	.'dan sonra verilen sayi kadar virgullu sayinin virgulden 
	sonrasinin kac basamak yazilacagini belirliyor. (Float)
		ornek --> printf("|%10.3f|", 123.12345); --> |   123.123| oluyor.
*/
void ft_test_bonus_dot(void)
{
	
}