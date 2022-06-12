/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:20:52 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/14 17:35:39 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_sort_execute_rot_reverse(t_ps *ps, t_sort *sort, bool print);
static void	stack_sort_execute_rot_forward(t_ps *ps, t_sort *sort, bool print);

/*
**	Executes all operations to "isolate" a marked snake on stack_A
**	pushs all not marked items to stack_B
*/
int	stack_sort_execute_snake(t_ps *ps, bool print)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < ps->size)
	{
		if (ps->a_top->is_snake)
			count += operation_ra(ps, print);
		else
			count += operation_pb(ps, print);
		i++;
	}
	return (count);
}

/*
**	Executes all rotations to rotate both stacks to prepare for the next push
*/
int	stack_sort_execute_rotation(t_ps *ps, t_sort *sort, bool print)
{
	int	rotation_count;

	rotation_count = sort->rotation_sum;
	stack_sort_execute_rot_forward(ps, sort, print);
	stack_sort_execute_rot_reverse(ps, sort, print);
	sort->rotation_sum = 0;
	return (rotation_count);
}

static void	stack_sort_execute_rot_forward(t_ps *ps, t_sort *sort, bool print)
{
	while (sort->ra_rra_count[0])
	{
		operation_ra(ps, print);
		sort->ra_rra_count[0]--;
	}
	while (sort->rb_rrb_count[0])
	{
		operation_rb(ps, print);
		sort->rb_rrb_count[0]--;
	}
	while (sort->rr_rrr_count[0])
	{
		operation_rr(ps, print);
		sort->rr_rrr_count[0]--;
	}
}

static void	stack_sort_execute_rot_reverse(t_ps *ps, t_sort *sort, bool print)
{
	while (sort->ra_rra_count[1])
	{
		operation_rra(ps, print);
		sort->ra_rra_count[1]--;
	}
	while (sort->rb_rrb_count[1])
	{
		operation_rrb(ps, print);
		sort->rb_rrb_count[1]--;
	}
	while (sort->rr_rrr_count[1])
	{
		operation_rrr(ps, print);
		sort->rr_rrr_count[1]--;
	}
}
