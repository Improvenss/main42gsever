/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:03:04 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/14 16:28:56 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_item_push(t_stack **stack_from, t_stack **stack_to);

/* Push an element from stack_B to stack_A */
int	operation_pa(t_ps *push_swap, bool print)
{
	if (push_swap->b_size >= 1)
	{
		stack_item_push(&(push_swap->b_top), &(push_swap->a_top));
		push_swap->b_size--;
		push_swap->a_size++;
	}
	if (print)
		write(1, "pa\n", 3);
	return (1);
}

/* Push an element from stack_A to stack_B */
int	operation_pb(t_ps *push_swap, bool print)
{
	if (push_swap->a_size >= 1)
	{
		stack_item_push(&(push_swap->a_top), &(push_swap->b_top));
		push_swap->a_size--;
		push_swap->b_size++;
	}
	if (print)
		write(1, "pb\n", 3);
	return (1);
}

/* General function to push the top item from a stack to another */
static void	stack_item_push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*tmp;
	bool	last_element;

	tmp = (*stack_from)->next;
	last_element = (*stack_from == (*stack_from)->next);
	(*stack_from)->prev->next = (*stack_from)->next;
	(*stack_from)->next->prev = (*stack_from)->prev;
	if (*stack_to)
	{
		(*stack_to)->prev->next = (*stack_from);
		(*stack_from)->prev = (*stack_to)->prev;
		(*stack_to)->prev = (*stack_from);
		(*stack_from)->next = (*stack_to);
	}
	else
	{
		(*stack_from)->next = (*stack_from);
		(*stack_from)->prev = (*stack_from);
	}
	(*stack_to) = (*stack_from);
	if (last_element)
		*stack_from = NULL;
	else
		*stack_from = tmp;
}
