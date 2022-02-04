/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:19:12 by gsever            #+#    #+#             */
/*   Updated: 2022/02/02 20:10:54 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Strlcat concatenate (n bytes) from source to the end of dest.
 * The return value is the length of the final string.
 * size means the total lenght of the string, including the
 * size of dest.
 * If dest lenght was bigger than the size, the length of dest
 * should be equal to size and don't concatenate.
 */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = dst_len;
	if (dst_len < dstsize - 1 && dstsize > 0)
	{
		while (src[i] != '\0' && dst_len + i < dstsize - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
			dst[j] = '\0';
		}
	}
	if (dst_len >= dstsize)
		dst_len = dstsize;
	return (dst_len + src_len);
}
