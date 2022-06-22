/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:29:33 by tjensen           #+#    #+#             */
/*   Updated: 2022/06/21 22:49:30 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	stack_item_swap(t_stack *stack);

/* Swaps the first two elements on stack_A */
int	operation_sa(t_ps *push_swap, bool print)
{
	if (push_swap->a_size >= 2)
		stack_item_swap(push_swap->a_top);
	if (print)
		write(1, "sa\n", 3);
	return (1);
}

/* Swaps the first two elements on stack_B */
int	operation_sb(t_ps *push_swap, bool print)
{
	if (push_swap->b_size >= 2)
		stack_item_swap(push_swap->b_top);
	if (print)
		write(1, "sb\n", 3);
	return (1);
}

/* Swaps the first two elements on stack_A & stack_B at the same time */
int	operation_ss(t_ps *push_swap, bool print)
{
	if (push_swap->a_size >= 2)
		stack_item_swap(push_swap->a_top);
	if (push_swap->b_size >= 2)
		stack_item_swap(push_swap->b_top);
	if (print)
		write(1, "ss\n", 3);
	return (1);
}

/* General function to swap the first two items on a stack */
static void	stack_item_swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}
