/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:06:03 by gsever            #+#    #+#             */
/*   Updated: 2022/02/01 15:44:00 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//this program changing (1, 2, 3,) to (M, M, M) or (e, e, e.)
void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;
	char	*buff;

	i = 0;
	buff = s;
	while (i < len)
	{
		buff[i] = c;
		i++;
	}
	return (buff);
}
