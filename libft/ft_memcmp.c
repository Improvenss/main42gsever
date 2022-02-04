/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:24:40 by gsever            #+#    #+#             */
/*   Updated: 2022/02/04 19:32:21 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 2 string arasinda istenilen kadar (n) sayar, esitse 0 doner
* degilse baytinin farkini alir ve onu dondurur. Cunku fonk int tanimlanmis.*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while (index < (n - 1))
	{
		if (((unsigned char *)s1)[index] != ((unsigned char *)s2)[index])
			break ;
		index++;
	}
	return (((unsigned char *)s1)[index] - (((unsigned char *)s2)[index]));
}
