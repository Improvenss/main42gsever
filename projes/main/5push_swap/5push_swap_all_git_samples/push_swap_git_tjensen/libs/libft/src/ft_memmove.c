/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:01:17 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/14 11:23:22 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*src_char;
	char	*dest_char;

	src_char = (char *)src;
	dest_char = (char *)dest;
	if (src > dest)
	{
		ft_memcpy(dest_char, src_char, n);
	}
	else if (src < dest)
	{
		while (n > 0)
		{
			dest_char[n - 1] = src_char[n - 1];
			n--;
		}
	}
	return (dest);
}
