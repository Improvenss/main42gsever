/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:02:55 by gsever            #+#    #+#             */
/*   Updated: 2022/01/31 17:02:58 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Memmove moves n memory area to another (unlike memcpy,
 * in this function the content may overwrite).
 * If dest address is further than src address, we need
 * to make sure them not overflow.
 */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*buff_dest;
	char	*buff_src;

	buff_dest = (char *)dest;
	buff_src = (char *)src;
	if (!buff_dest || !buff_src || !n)
		return (dest);
	if (buff_dest > buff_src)
	{
		while (n--)
			buff_dest[n] = buff_src[n];
	}
	else
	{
		ft_memcpy(buff_dest, buff_src, n);
	}
	return (buff_dest);
}
