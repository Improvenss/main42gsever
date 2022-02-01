/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:11:15 by gsever            #+#    #+#             */
/*   Updated: 2022/02/01 15:43:57 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//this function putting 0 this values. If n = 0 do nothing.
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*buff;

	i = 0;
	buff = s;
	while (i < n)
	{
		buff[i] = 0;
		i++;
	}
}
