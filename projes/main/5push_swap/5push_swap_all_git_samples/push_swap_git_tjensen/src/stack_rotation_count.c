/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotation_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:33:41 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/16 01:41:16 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Returns a number from stack_B for which the least rotations are necessary
**	to push it to stack_A (Minimum all rotations in stack_A & stack_B)
*/
int	stack_rot_count_find_best_num_b(t_ps *ps, t_sort *sort)
{
	t_stack	*tmp;
	int		i;
	int		smallest;
	int		num;
	int		rotation_min;

	smallest = stack_get_smallest(ps->b_top);
	rotation_min = ps->size;
	tmp = ps->b_top;
	i = 0;
	while (i < ps->b_size)
	{
		if (tmp->num <= smallest + sort->range)
		{
			stack_rot_set_b_to_a(ps, sort, tmp->num);
			if (sort->rotation_sum < rotation_min)
			{
				num = tmp->num;
				rotation_min = sort->rotation_sum;
			}
		}
		tmp = tmp->next;
		i++;
	}
	return (num);
}

/* Set rotations for both directions to get a num to the top of a stack */
void	stack_rot_count_from(t_stack *stack, int *r_rr_count, int num)
{
	t_stack	*tmp;

	if (stack == NULL)
	{
		r_rr_count[0] = STACK_EMPTY;
		r_rr_count[1] = STACK_EMPTY;
		return ;
	}
	r_rr_count[0] = 0;
	tmp = stack;
	while (tmp->num != num)
	{
		tmp = tmp->next;
		r_rr_count[0]++;
	}
	r_rr_count[1] = 0;
	tmp = stack;
	while (tmp->num != num)
	{
		tmp = tmp->prev;
		r_rr_count[1]++;
	}
}

/*
**	Set rotations for both directions to place a num in a sorted target stack
**	With the target stack sorted in ascending order.
*/
void	stack_rot_count_to_asc(t_stack *stack, int *r_rr_count, int num)
{
	if (stack == NULL)
	{
		r_rr_count[0] = 0;
		r_rr_count[1] = 0;
	}
	else if (stack_is_smallest(stack, num) || stack_is_biggest(stack, num))
		stack_rot_count_from(stack, r_rr_count, stack_get_smallest(stack));
	else
		stack_rot_count_from(stack, r_rr_count,
			stack_get_next_bigger(stack, num));
}
