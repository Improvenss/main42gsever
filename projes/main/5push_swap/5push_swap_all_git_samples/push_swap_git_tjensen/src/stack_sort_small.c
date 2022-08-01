/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:34:34 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/19 10:34:17 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_sort_3(t_ps *ps);

/*
** Function to sort the input for small input sizes ~(smaller 7)
*/
void	stack_sort_small(t_ps *ps)
{
	t_sort	sort;
	int		num;

	if (ps->size == 2)
		operation_sa(ps, true);
	else
	{
		while (ps->a_size > 3)
			operation_pb(ps, true);
		stack_sort_3(ps);
		sort.range = 1;
		while (ps->b_size)
		{
			num = stack_rot_count_find_best_num_b(ps, &sort);
			stack_rot_set_b_to_a(ps, &sort, num);
			stack_sort_execute_rotation(ps, &sort, true);
			operation_pa(ps, true);
		}
		stack_rot_set_end(ps, &sort, 0);
		stack_sort_execute_rotation(ps, &sort, true);
	}
}

/* Function to swap a given stack if it contains 3 numbers (not sorted) */
static void	stack_sort_3(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->a_top->num;
	b = ps->a_top->next->num;
	c = ps->a_top->next->next->num;
	if (c > a && c > b && a > b)
		operation_sa(ps, true);
	else if (a > b && a > c && b > c)
		operation_sa(ps, true);
	else if (b > a && b > c && c > a)
		operation_sa(ps, true);
}
