/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 00:59:43 by Nik               #+#    #+#             */
/*   Updated: 2019/08/30 14:57:18 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			get_a_steps(int *stack_a, int nbr)
{
	int i;

	i = A_LEN;
	if (nbr > A_BOTTOM && nbr < A_TOP)
		return (0);
	while (i > 1)
	{
		if (nbr > stack_a[i] && nbr < stack_a[i - 1])
			break ;
		i--;
	}
	return (i - 1);
}

void		b_rotation(int *stack_a, int *stack_b, int steps)
{
	if (steps <= B_LEN / 2)
		while (steps--)
			totle_commander("rrb", stack_a, stack_b);
	else
	{
		steps = B_LEN - steps;
		while (steps--)
			totle_commander("rb", stack_a, stack_b);
	}
}

void		a_rotation(int *stack_a, int *stack_b, int steps)
{
	if (steps <= A_LEN / 2)
	{
		while (steps--)
			totle_commander("rra", stack_a, stack_b);
	}
	else
	{
		steps = A_LEN - steps;
		while (steps--)
			totle_commander("ra", stack_a, stack_b);
	}
}

void		rr_rotation(int *stack_a, int *stack_b, int a_steps, int b_steps)
{
	a_steps = A_LEN - a_steps;
	b_steps = B_LEN - b_steps;
	while (a_steps-- && b_steps--)
		totle_commander("rr", stack_a, stack_b);
	while (a_steps-- >= 0)
		totle_commander("ra", stack_a, stack_b);
	while (b_steps-- > 0)
		totle_commander("rb", stack_a, stack_b);
}

void		rotation(int *stack_a, int *stack_b, int index)
{
	int a_steps;
	int b_steps;

	a_steps = get_a_steps(stack_a, stack_b[index]);
	b_steps = index;
	if ((a_steps <= A_LEN / 2) && (index <= B_LEN / 2))
	{
		while (a_steps-- && b_steps--)
			totle_commander("rrr", stack_a, stack_b);
		while (a_steps-- >= 0)
			totle_commander("rra", stack_a, stack_b);
		while (b_steps-- > 0)
			totle_commander("rrb", stack_a, stack_b);
	}
	else if (!(a_steps <= A_LEN / 2) && !(index <= B_LEN / 2))
	{
		rr_rotation(stack_a, stack_b, a_steps, b_steps);
	}
	else
	{
		b_rotation(stack_a, stack_b, b_steps);
		a_rotation(stack_a, stack_b, a_steps);
	}
}
