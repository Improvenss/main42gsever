/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:41:58 by gsever            #+#    #+#             */
/*   Updated: 2022/02/01 15:47:59 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Calloc allocates bytes and put 0s inside.
 * The return value is the pointer to the first allocated memory.
 * p iterate the string and reaches the end of the allocated bytes
 * putting 0 inside them. Than, pointer return the beggining of
 * the memory.
 */
//amount = miktar
void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	char	*pointer;
	size_t	amount;
	size_t	i;

	amount = count * size;
	p = (char *) malloc(amount);
	if (!p)
		return (NULL);
	pointer = p;
	i = 0;
	while (i < amount)
	{
		*p = 0;
		i++;
		p++;
	}
	return ((void *) pointer);
}
