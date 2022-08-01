/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:55:37 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:55:42 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	reverse_rotate(t_stack *stack)
{
	t_stacknode	*tmp;

	if (stack_is_empty(stack) || stack->size == 1)
		return ;
	tmp = stack->bottom->next;
	stack->top->next = stack->bottom;
	stack->bottom->prev = stack->top;
	stack->bottom->next = NULL;
	stack->top = stack->bottom;
	stack->bottom = tmp;
	tmp->prev = NULL;
}

void	rra(t_collection *collection)
{
	reverse_rotate(collection->a);
}

void	rrb(t_collection *collection)
{
	reverse_rotate(collection->b);
}

void	rrr(t_collection *collection)
{
	reverse_rotate(collection->a);
	reverse_rotate(collection->b);
}
