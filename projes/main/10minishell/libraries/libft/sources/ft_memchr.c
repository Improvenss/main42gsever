/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:15:53 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:40 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//"abc" de 'n' kadar c yi ariyor, bulunca c'nin adresini atiyor. bulamazsa null
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;

	if (n == 0)
		return (NULL);
	index = 0;
	while (index < n && (((unsigned char *)s)[index] != (unsigned char)c))
	{
		if (index == n - 1)
			return (NULL);
		index++;
	}
	return (&((unsigned char *)s)[index]);
}
/*
//string icinde byte ariyor. "gorkem" "or" ara budun mu o'nun adresi gonderir
int	main() 
{
	char array1[] = {'A', 'B', 'C'};
	char string1[] = "Gorkem Sever 42 Schools";
	char	*returned_original;
	char	*returned_myfunc;

	returned_original = memchr(array1, 'C', 3);
	printf("ORIGINAL: |%s|\n", returned_original);
	returned_myfunc = ft_memchr(array1, 'C', 3);
	printf("MY FUNC: |%s|\n", returned_myfunc);
	returned_original = memchr(string1, 'v', 23);
	returned_myfunc = ft_memchr(string1, 'v', 23);
	printf("ORIGINAL: |%s|\n", returned_original);
	printf("MY FUNC: |%s|\n", returned_myfunc);
}
*/