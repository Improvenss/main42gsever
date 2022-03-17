/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:56:33 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:56:34 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vector.h"
#include <unistd.h>

void	add_operation(const t_opcode op, t_collection *stacks, t_vector *ops)
{
	vector_pushback(ops, op);
	execute_operation(op, stacks);
}

t_opcode	get_rotation_direction(const t_stack *stack, const ssize_t steps)
{
	if (steps > stack->size / 2)
	{
		if (stack->id == 'a')
			return (RRA);
		return (RRB);
	}
	if (stack->id == 'a')
		return (RA);
	return (RB);
}

ssize_t	find_steps(const size_t to_find, t_stacknode *startnode)
{
	ssize_t	steps;

	steps = 0;
	while (startnode)
	{
		if (startnode->sorted_pos == to_find)
			return (steps);
		++steps;
		startnode = startnode->prev;
	}
	return (-1);
}

void	print_all_operations(const t_vector *operations)
{
	size_t	i;

	i = 0;
	while (i < operations->size)
	{
		print_operation(operations->arr[i], STDOUT_FILENO);
		++i;
	}
}
