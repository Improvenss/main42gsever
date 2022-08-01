/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:24:40 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:42 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*
2 string arasinda istenilen kadar (n) sayar, esitse 0 doner
degilse baytinin farkini alir ve onu dondurur. Cunku fonk int tanimlanmis.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while (index < (n - 1))
	{
		if (((unsigned char *)s1)[index] != ((unsigned char *)s2)[index])
			break ;
		index++;
	}
	return (((unsigned char *)s1)[index] - (((unsigned char *)s2)[index]));
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char a[] = "gor234";
	char b[] = "gor123";
	char ft_a[] = "gor234";
	char ft_b[] = "gor123";
	printf("org:%d\n", memcmp(a, b, 4));
	printf("ft_:%d\n", ft_memcmp(ft_a, ft_b, 4));
}
*/