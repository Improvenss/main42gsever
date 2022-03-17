/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks_back_to_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:56:13 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:56:15 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "utils.h"
#include "chunk.h"

void	sync_up(t_collection *stacks, t_vector *ops)
{
	while (stacks->a->bottom->sorted_pos < stacks->a->top->sorted_pos)
		add_operation(RRA, stacks, ops);
}

void	push_logic(t_collection *stacks, t_vector *ops, \
		ssize_t steps, t_chunk *chunk)
{
	const t_opcode	rot_dir = get_rotation_direction(stacks->b, steps);

	while (stacks->b->top->sorted_pos != (unsigned int)chunk->max)
	{
		if (stacks->b->top->sorted_pos == (unsigned int)chunk->max - 1)
			add_operation(PA, stacks, ops);
		else if (stacks->b->top->sorted_pos == (unsigned int)chunk->min)
		{
			add_operation(PA, stacks, ops);
			if (stacks->a->size > 1)
				add_operation(RA, stacks, ops);
			++(chunk->min);
		}
		else
			add_operation(rot_dir, stacks, ops);
	}
	add_operation(PA, stacks, ops);
	if (stacks->a->size > 1 && \
		stacks->a->top->sorted_pos == stacks->a->top->prev->sorted_pos + 1)
		add_operation(SA, stacks, ops);
}

void	push_chunk_to_a(t_collection *stacks, t_vector *operations, \
	t_chunk current_chunk)
{
	ssize_t	steps;

	while (current_chunk.max >= current_chunk.min)
	{
		steps = find_steps(current_chunk.max, stacks->b->top);
		if (steps >= 0)
			push_logic(stacks, operations, steps, &current_chunk);
		--current_chunk.max;
	}
	sync_up(stacks, operations);
}

void	push_back_to_a(t_collection *stacks, t_vector *operations, \
	const int CHUNK_SIZE, const int CHUNK_AMOUNT)
{
	t_chunk	current_chunk;

	current_chunk = chunk_init((int)CHUNK_AMOUNT - 1, CHUNK_SIZE);
	while (current_chunk.nb >= 0)
	{
		push_chunk_to_a(stacks, operations, current_chunk);
		chunk_decrease(&current_chunk);
	}
}
