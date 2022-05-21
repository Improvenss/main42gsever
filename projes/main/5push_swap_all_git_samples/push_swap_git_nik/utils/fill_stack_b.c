/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 21:12:01 by vinograd          #+#    #+#             */
/*   Updated: 2019/09/04 20:39:44 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		is_in_right_order(int *stack_a)
{
	int max;
	int min;

	max = find_max(stack_a, 0);
	min = find_min(stack_a, 0);
	if (A_TOP == min && A_SEC == max)
		totle_commander("sa", stack_a, NULL);
	if (A_TOP == max && A_BOTTOM == min)
	{
		totle_commander("rra", stack_a, NULL);
		totle_commander("sa", stack_a, NULL);
	}
	return (A_TOP == max || A_TOP == min ||
		(A_TOP > A_BOTTOM && A_TOP < A_SEC));
}

int		push_nbr_from_b(int *stack_a, int *stack_b)
{
	if (!B_LEN)
		return (0);
	if (B_TOP > A_BOTTOM && B_TOP < A_TOP)
		totle_commander("pa", stack_a, stack_b);
	else if (stack_b[B_LEN - 1] > A_BOTTOM &&\
	stack_b[B_LEN - 1] < A_TOP && B_LEN > 1)
	{
		totle_commander("rb", stack_a, stack_b);
		totle_commander("pa", stack_a, stack_b);
	}
	else if (B_BOTTOM > A_BOTTOM && B_BOTTOM < A_TOP)
	{
		totle_commander("rrb", stack_a, stack_b);
		totle_commander("pa", stack_a, stack_b);
	}
	else
		return (0);
	return (1);
}

void	fill_stack_b(int *stack_a, int *stack_b)
{
	while (!is_a_sorted(stack_a))
	{
		while (push_nbr_from_b(stack_a, stack_b))
			;
		if (is_in_right_order(stack_a))
			totle_commander("ra", stack_a, stack_b);
		else if (does_sa_work(stack_a, stack_b))
			totle_commander("sa", stack_a, stack_b);
		else
			totle_commander("pb", stack_a, stack_b);
	}
}
