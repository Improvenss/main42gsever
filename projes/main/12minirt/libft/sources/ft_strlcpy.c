/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:37:07 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:18:26 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//copying but returning to size|source-size->destination|(boyutukadarkopyalama)
size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size > 0)
	{
		while (index < (size - 1) && src[index])
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	while (src[index])
		index++;
	return (index);
}
/*
#include <string.h>
//gorkem->1234\0 toplamda 5 oldu.
int	main ()
{
	char a[] ="gorkem";
	char b[] = "12345";
	char ft_a[] ="gorkem";
	char ft_b[] = "12345";

	printf("org:%zu\n", strlcpy(a, b, 4));
	printf("ft_:%zu\n", ft_strlcpy(ft_a, ft_b, 4));
}
*/