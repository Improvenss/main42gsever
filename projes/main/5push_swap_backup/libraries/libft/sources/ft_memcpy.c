/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:35:54 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:45 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//throwing source to destination e.g.:"sourceation" or "gork5" |not adres va mi
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ret;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	ret = dest;
	while (n--)
		*((unsigned char *)dest++) = *((unsigned char *)src++);
	return (ret);
}
/*
#include <string.h>
int	main()
{
	char a[] = "destination";
	char b[] = "source";
	char ft_a[] = "12345";
	char ft_b[] = "gorkem";

	printf("org:%s\n", memcpy(a, b, 6));
	printf("ft_:%s\n", ft_memcpy(ft_a, ft_b, 4));
}
*/