/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:02:10 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/14 16:31:55 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotate of stack_A (First element becomes last) */
int	operation_ra(t_ps *push_swap, bool print)
{
	if (push_swap->a_top)
		push_swap->a_top = push_swap->a_top->next;
	if (print)
		write(1, "ra\n", 3);
	return (1);
}

/* Rotate of stack_B (First element becomes last) */
int	operation_rb(t_ps *push_swap, bool print)
{
	if (push_swap->b_top)
		push_swap->b_top = push_swap->b_top->next;
	if (print)
		write(1, "rb\n", 3);
	return (1);
}

/* Rotate of stack_A & stack_B at the same time (First element becomes last) */
int	operation_rr(t_ps *push_swap, bool print)
{
	if (push_swap->a_top)
		push_swap->a_top = push_swap->a_top->next;
	if (push_swap->b_top)
		push_swap->b_top = push_swap->b_top->next;
	if (print)
		write(1, "rr\n", 3);
	return (1);
}
