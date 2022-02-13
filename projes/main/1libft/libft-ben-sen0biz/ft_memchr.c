/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:46:53 by gsever            #+#    #+#             */
/*   Updated: 2022/02/04 18:48:38 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//string icinde byte ariyor. "gorkem" "or" ara budun mu o'nun adresi gonder
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buff;
	unsigned char	buff_c;
	size_t			i;

	buff = (unsigned char *)s;
	buff_c = c;
	if (n != 0)
	{
		i = 0;
		while (i < n)
		{
			if (buff[i] == buff_c)
				return ((char *)&buff[i]);
			i++;
		}
	}
	return (NULL);
}
/*
void ft_memchr_test(void)
{
	char array1[] = {'A', 'B', 'C'};
	char string1[50] = "Gorkem Sever 42 Schools";
	char	*returned_original;
	char	*returned_myfunc;

	returned_original = memchr(string1, 'v', 23);
	returned_myfunc = ft_memchr(string1, 'v', 23);
	printf("ORIGINAL: |%s|\n", returned_original);
	printf("MY FUNC: |%s|\n", returned_myfunc);
	returned_original = memchr(array1, 'C', 3);
	returned_myfunc = ft_memchr(array1, 'C', 3);
	printf("ORIGINAL: |%s|\n", returned_original);
	printf("MY FUNC: |%s|\n", returned_myfunc);
}

int main()
{
	ft_memchr_test();
}
*/