/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:55:46 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:55:51 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	rotate(t_stack *stack)
{
	t_stacknode	*tmp;

	if (stack_is_empty(stack) || stack->size == 1)
		return ;
	tmp = stack->top->prev;
	stack->bottom->prev = stack->top;
	stack->top->next = stack->bottom;
	stack->bottom = stack->top;
	tmp->next = NULL;
	stack->bottom->prev = NULL;
	stack->top = tmp;
}

void	ra(t_collection *coll)
{
	rotate(coll->a);
}

void	rb(t_collection *coll)
{
	rotate(coll->b);
}

void	rr(t_collection *coll)
{
	rotate(coll->a);
	rotate(coll->b);
}
