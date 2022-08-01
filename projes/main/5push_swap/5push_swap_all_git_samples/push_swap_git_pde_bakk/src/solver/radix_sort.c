/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:56:21 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:56:23 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "solver.h"
#include "vector.h"
#include "utils.h"

size_t	get_max_rotations(const t_stack *stack, const size_t shift_bits_amount)
{
	size_t		rots;
	t_stacknode	*node;

	node = stack->bottom;
	rots = 1;
	while (node != stack->top)
	{
		if (((node->sorted_pos >> shift_bits_amount) & 1) == 1)
			return (rots);
		++rots;
		node = node->next;
	}
	return (stack->size);
}

t_vector	*radix_sort(t_collection *coll)
{
	const size_t	size = coll->a->size;
	const size_t	max_bits = get_max_bits(size - 1);
	t_vector		*ops;
	size_t			i;
	size_t			j;

	i = 0;
	ops = vector_init(size);
	while (i < max_bits && !sort_is_done(coll))
	{
		j = 0;
		while (j < size)
		{
			if (((coll->a->top->sorted_pos >> i) & 1) == 1)
				add_operation(RA, coll, ops);
			else
				add_operation(PB, coll, ops);
			++j;
		}
		while (!stack_is_empty(coll->b))
			add_operation(PA, coll, ops);
		++i;
	}
	return (ops);
}
