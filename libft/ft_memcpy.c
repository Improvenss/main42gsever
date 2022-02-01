/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:43:53 by gsever            #+#    #+#             */
/*   Updated: 2022/02/01 15:41:52 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Memcpy copies n memory area to another and return a pointer
 *	to the destinated area.
 */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*buff_dst;
	char	*buff_src;

	i = 0;
	buff_dst = (char *)dst;
	buff_src = (char *)src;
	if (buff_dst == 0 && buff_src == 0)
		return (NULL);
	while (i < n)
	{
		buff_dst[i] = buff_src[i];
		i++;
	}
	return (buff_dst);
}
