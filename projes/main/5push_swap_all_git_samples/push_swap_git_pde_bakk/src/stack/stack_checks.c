/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:56:55 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:56:56 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	stack_duplicate_check(const t_stack *stack, int item)
{
	t_stacknode	*tmp;

	tmp = stack->bottom;
	while (tmp)
	{
		if (tmp->data == item)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool	stack_is_empty(const t_stack *stack)
{
	return (stack->top == NULL);
}

bool	sort_is_done(const t_collection *coll)
{
	t_stacknode	*tmp;

	if (!stack_is_empty(coll->b))
		return (false);
	tmp = coll->a->top;
	if (tmp == NULL)
		return (true);
	while (tmp->prev)
	{
		if (tmp->prev->data < tmp->data)
			return (false);
		tmp = tmp->prev;
	}
	return (true);
}

static bool	stack_is_reverse_sorted(const t_stack *stack)
{
	t_stacknode	*tmp;

	if (stack_is_empty(stack))
		return (true);
	tmp = stack->top;
	while (tmp->prev)
	{
		if (tmp->data < tmp->prev->data)
			return (false);
		tmp = tmp->prev;
	}
	return (true);
}

bool	stack_is_sorted(const t_stack *stack)
{
	t_stacknode	*tmp;

	if (stack->id == 'b')
		return (stack_is_reverse_sorted(stack));
	if (stack_is_empty(stack))
		return (true);
	tmp = stack->top;
	while (tmp->prev)
	{
		if (tmp->prev->data < tmp->data)
			return (false);
		tmp = tmp->prev;
	}
	return (true);
}
