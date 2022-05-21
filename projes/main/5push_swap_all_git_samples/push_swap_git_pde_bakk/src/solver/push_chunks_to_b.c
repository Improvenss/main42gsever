/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:56:17 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:56:19 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "chunk.h"

#define LOWER 0
#define UPPER 1

void	init_chunks(t_chunk *lower_chunk, t_chunk *upper_chunk, \
					const int CHUNK_SIZE, const int CHUNK_AMOUNT)
{
	*lower_chunk = chunk_init(CHUNK_AMOUNT / 2 - 1, CHUNK_SIZE);
	*upper_chunk = chunk_init(CHUNK_AMOUNT / 2, CHUNK_SIZE);
}

void	fill(size_t *fillings, const int CHUNK_SIZE, t_chunk *chunk, int id)
{
	++(*fillings);
	if (*fillings % CHUNK_SIZE == 0)
	{
		if (id == LOWER)
			chunk_decrease(chunk);
		else
			chunk_increase(chunk);
	}
}

void	push_chunks_to_b(t_collection *stacks, t_vector *operations, \
const int CHUNK_SIZE, const int CHUNK_AMOUNT)
{
	t_chunk	chunks[2];
	size_t	fillings[2];

	init_chunks(&chunks[LOWER], &chunks[UPPER], CHUNK_SIZE, CHUNK_AMOUNT);
	fillings[LOWER] = 0;
	fillings[UPPER] = 0;
	while (!stack_is_empty(stacks->a))
	{
		if (is_within_chunk((int)stacks->a->top->sorted_pos, &chunks[UPPER]))
		{
			add_operation(PB, stacks, operations);
			fill(&fillings[UPPER], CHUNK_SIZE, &chunks[UPPER], UPPER);
		}
		else if (is_within_chunk((int)stacks->a->top->sorted_pos, \
			&chunks[LOWER]))
		{
			add_operation(PB, stacks, operations);
			if (fillings[UPPER] > 0 || chunks[LOWER].nb != CHUNK_AMOUNT / 2 - 1)
				add_operation(RB, stacks, operations);
			fill(&fillings[LOWER], CHUNK_SIZE, &chunks[LOWER], LOWER);
		}
		else
			add_operation(RA, stacks, operations);
	}
}
