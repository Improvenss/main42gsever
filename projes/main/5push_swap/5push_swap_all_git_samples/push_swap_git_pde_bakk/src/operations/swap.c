/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:55:55 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:55:57 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	swap(t_stack *stack)
{
	t_stacknode	*oldtop;
	t_stacknode	*oldsecond;

	if (stack->size < 2)
		return ;
	oldtop = stack->top;
	oldsecond = stack->top->prev;
	oldtop->next = oldsecond;
	oldtop->prev = oldsecond->prev;
	if (oldtop->prev)
		oldtop->prev->next = oldtop;
	oldsecond->prev = oldtop;
	oldsecond->next = NULL;
	stack->top = oldsecond;
	if (stack->size == 2)
		stack->bottom = oldtop;
}

void	sa(t_collection *collection)
{
	swap(collection->a);
}

void	sb(t_collection *collection)
{
	swap(collection->b);
}

void	ss(t_collection *collection)
{
	sa(collection);
	sb(collection);
}
