/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_in_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:56:36 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:56:38 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static size_t	max(const size_t a, const size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	get_max_element(const t_stack *stack)
{
	t_stacknode	*temp;
	size_t		max_elem;

	max_elem = 0;
	temp = stack->top;
	while (temp)
	{
		max_elem = max(max_elem, temp->sorted_pos);
		temp = temp->prev;
	}
	return (max_elem);
}

unsigned int	get_max_bits(const unsigned int max_num)
{
	unsigned int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	return (max_bits);
}
