/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate_reverse.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:02:33 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/14 16:33:16 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Reverse Rotate of stack_A (Last element becomes first) */
int	operation_rra(t_ps *push_swap, bool print)
{
	if (push_swap->a_top)
		push_swap->a_top = push_swap->a_top->prev;
	if (print)
		write(1, "rra\n", 4);
	return (1);
}

/* Reverse Rotate of stack_B (Last element becomes first) */
int	operation_rrb(t_ps *push_swap, bool print)
{
	if (push_swap->b_top)
		push_swap->b_top = push_swap->b_top->prev;
	if (print)
		write(1, "rrb\n", 4);
	return (1);
}

/* Reverse Rotate of both stacks at the same time. Last element becomes first */
int	operation_rrr(t_ps *push_swap, bool print)
{
	if (push_swap->a_top)
		push_swap->a_top = push_swap->a_top->prev;
	if (push_swap->b_top)
		push_swap->b_top = push_swap->b_top->prev;
	if (print)
		write(1, "rrr\n", 4);
	return (1);
}
