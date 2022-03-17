/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:55:22 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:57:46 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"

t_chunk	chunk_init(const int nb, const int size)
{
	const t_chunk	out = {
		.nb = (short)nb,
		.size = (short)size,
		.min = nb * size,
		.max = (nb + 1) * size - 1
	};

	return (out);
}

static void	update_min_max(t_chunk *chunk)
{
	chunk->min = chunk->nb * chunk->size;
	chunk->max = chunk->min + chunk->size - 1;
}

void	chunk_decrease(t_chunk *chunk)
{
	--chunk->nb;
	update_min_max(chunk);
}

void	chunk_increase(t_chunk *chunk)
{
	++chunk->nb;
	update_min_max(chunk);
}

bool	is_within_chunk(const int item, const t_chunk *chunk)
{
	return (chunk->min <= item && item <= chunk->max);
}
