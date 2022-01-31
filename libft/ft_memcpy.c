/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:43:53 by gsever            #+#    #+#             */
/*   Updated: 2022/01/31 17:03:04 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Memcpy copies n memory area to another and return a pointer
 *	to the destinated area.
 */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*buff_dest;
	char	*buff_src;

	i = 0;
	buff_dest = (char *)dest;
	buff_src = (char *)src;
	if (buff_dest == 0 && buff_src == 0)
		return (NULL);
	while (i < n)
	{
		buff_dest[i] = buff_src[i];
		i++;
	}
	return (buff_dest);
}
