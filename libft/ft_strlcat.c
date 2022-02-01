/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:19:12 by gsever            #+#    #+#             */
/*   Updated: 2022/01/31 20:44:22 by gsever           ###   ########.fr       */
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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	j = dest_len;
	if (dest_len < size - 1 && size > 0)
	{
		while (src[i] != '\0' && dest_len + i < size - 1)
		{
			dest[j] = src[i];
			j++;
			i++;
			dest[j] = '\0';
		}
	}
	if (dest_len >= size)
		dest_len = size;
	return (dest_len + src_len);
}
