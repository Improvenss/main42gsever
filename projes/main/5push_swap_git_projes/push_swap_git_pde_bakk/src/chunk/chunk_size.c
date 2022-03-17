/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:55:25 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:55:27 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static size_t	ft_sqrt(const size_t nb)
{
	size_t	counter;

	counter = 1;
	while (counter * counter <= nb)
	{
		++counter;
	}
	return (counter - 1);
}

int	get_chunk_size(t_stack *stack)
{
	return ((int)ft_sqrt(stack->size));
}
