/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:56:09 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:56:11 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "vector.h"
#include "operations.h"

static void	replace_instructions_with(t_opcode replacement, t_vector *ops, \
const size_t i)
{
	ops->arr[i] = replacement;
	vector_delete_bypos(ops, i + 1);
}

void	optimize_instructions(t_vector *ops)
{
	size_t	i;

	i = 0;
	if (ops->size == 0)
		return ;
	while (i < ops->size - 1)
	{
		if ((ops->arr[i] == SA && ops->arr[i + 1] == SB) || \
		(ops->arr[i] == SB && ops->arr[i + 1] == SA))
		{
			replace_instructions_with(SS, ops, i);
		}
		else if ((ops->arr[i] == RA && ops->arr[i + 1] == RB) || \
		(ops->arr[i] == RB && ops->arr[i + 1] == RA))
		{
			replace_instructions_with(RR, ops, i);
		}
		else if ((ops->arr[i] == RRA && ops->arr[i + 1] == RRB) || \
		(ops->arr[i] == RRB && ops->arr[i + 1] == RRA))
		{
			replace_instructions_with(RRR, ops, i);
		}
		++i;
	}
}
