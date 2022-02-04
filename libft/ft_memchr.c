/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:15:53 by gsever            #+#    #+#             */
/*   Updated: 2022/02/04 19:24:24 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//"abc" de c yi ariyor, bulunca c'nin adresini atiyor.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;

	if (n == 0)
		return (NULL);
	index = 0;
	while (index < n && (((unsigned char *)s)[index] != (unsigned char)c))
	{
		if (index == n - 1)
			return (NULL);
		index++;
	}
	return (&((unsigned char *)s)[index]);
}
