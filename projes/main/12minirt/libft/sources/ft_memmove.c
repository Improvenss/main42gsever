/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:36:00 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:48 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*
"start" --> 3's "ststt" doing.
https://aticleworld.com/memmove-function-implementation-in-c/
*/
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, n);
	else if (dst > src)
	{
		while (n--)
			*((unsigned char *)(dst + n)) = *((unsigned char *)(src + n));
	}
	return (dst);
}
/*
#include <string.h>
int	main()
{
	char a[] = "123456";
	char b[] = "gorkem";
	char ft_a[] = "123456";
	char ft_b[] = "gorkem";
	
	printf("org:%s\n", memmove(a, b, 3));	
	printf("ft_:%s\n", ft_memmove(ft_a ,ft_b , 3));
}
*/
