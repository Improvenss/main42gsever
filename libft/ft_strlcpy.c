/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:17:03 by gsever            #+#    #+#             */
/*   Updated: 2022/01/31 17:19:01 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Strlcpy copies size memories from src to dest and returns
 * the length of source. The size passed inlcude the null terminator.
 */

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	j;

	src_len = ft_strlen(src);
	j = 0;
	if (size != 0)
	{
		while (j < size - 1 && j != src_len)
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = 0;
	}
	return (src_len);
}
