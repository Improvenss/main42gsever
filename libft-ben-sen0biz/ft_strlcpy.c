/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:17:03 by gsever            #+#    #+#             */
/*   Updated: 2022/02/02 20:04:56 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Strlcpy copies size memories from src to dest and returns
 * the length of source. The size passed inlcude the null terminator.
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	j;

	src_len = ft_strlen(src);
	j = 0;
	if (dstsize != 0)
	{
		while (j < dstsize - 1 && j != src_len)
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = 0;
	}
	return (src_len);
}
