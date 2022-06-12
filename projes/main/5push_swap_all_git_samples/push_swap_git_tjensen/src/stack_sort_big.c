/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:57:37 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/19 09:59:47 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_sort_find_parameters(t_ps *ps, t_sort *sort, t_snake *snake);
static int	stack_sort_update_count(t_sort *sort, t_snake *snake,
				int count, int min_count);
static int	stack_sort(t_ps *ps, t_sort *sort, t_snake *snake, bool print);

/*
**	Call this function to sort a "large" input of numbers ~(>=7)
**	First it searchs for good params and then executes the best on the stack
*/
void	stack_sort_big(t_ps *ps)
{
	t_sort	sort;
	t_snake	snake;

	stack_sort_find_parameters(ps, &sort, &snake);
	sort.range = sort.max_range;
	snake.range = snake.max_range;
	stack_sort(ps, &sort, &snake, true);
}

/*
**	This algorithm runs the sorting algo with different parameters
**	and set the best configuration, to sort the stack with less operations
*/
static void	stack_sort_find_parameters(t_ps *ps, t_sort *sort, t_snake *snake)
{
	int		count;
	int		min_count;
	t_ps	save_ps;

	min_count = INT_MAX;
	save_ps.stack_mem = stack_get_mem(ps);
	push_swap_struct_cpy(&save_ps, ps);
	sort->range = ps->size;
	while (sort->range <= ps->size)
	{
		snake->range = 1;
		while (snake->range <= ps->size)
		{
			push_swap_struct_cpy(ps, &save_ps);
			count = stack_sort(ps, sort, snake, false);
			min_count = stack_sort_update_count(sort, snake, count, min_count);
			if (snake->range < (ps->size / 10))
				snake->range += 10;
			else
				snake->range += 100;
		}
		sort->range += ps->size;
	}
	push_swap_struct_cpy(ps, &save_ps);
	free(save_ps.stack_mem);
}

/* Sorts a stack with given parameters and returns the necessary operations */
static int	stack_sort(t_ps *ps, t_sort *sort, t_snake *snake, bool print)
{
	int		num;
	int		count;

	count = 0;
	stack_snake_set(ps, snake);
	count += stack_sort_execute_snake(ps, print);
	while (ps->b_size)
	{
		num = stack_rot_count_find_best_num_b(ps, sort);
		stack_rot_set_b_to_a(ps, sort, num);
		count += stack_sort_execute_rotation(ps, sort, print);
		count += operation_pa(ps, print);
	}
	stack_rot_set_end(ps, sort, 0);
	count += stack_sort_execute_rotation(ps, sort, print);
	return (count);
}

/* If less operations are necessary this function updates the "best values" */
static int	stack_sort_update_count(t_sort *sort, t_snake *snake,
				int count, int min_count)
{
	if (count < min_count)
	{
		min_count = count;
		sort->max_range = sort->range;
		snake->max_range = snake->range;
	}
	return (min_count);
}
