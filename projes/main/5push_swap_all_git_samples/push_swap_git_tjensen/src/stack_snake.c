/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_snake.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:14:55 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/19 10:33:08 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_snake_find_best(t_snake *snake, int stack_size);
static void	stack_snake_count_len(t_snake *snake, int stack_size);
static int	snake_shift(int num, int base_num, int stack_size);

/*
**	Searchs for a longest snake starting from every item in stack_A
**	After that it takes the longest and marks all included items
*/
void	stack_snake_set(t_ps *ps, t_snake *snake)
{
	int		i;
	int		shifted_n;
	int		end_n;
	t_stack	*tmp;

	snake->start = ps->a_top;
	stack_snake_find_best(snake, ps->a_size);
	tmp = snake->max_start;
	end_n = 0;
	i = 0;
	while (i < snake->max_len)
	{
		shifted_n = snake_shift(tmp->num, snake->max_start->num, ps->a_size);
		if (shifted_n >= end_n && shifted_n <= end_n + snake->range)
		{
			end_n = shifted_n;
			tmp->is_snake = true;
			i++;
		}
		tmp = tmp->next;
	}
}

/*
**	Searchs and sets the start for the longest presorted input
**	starting from every item
**	in a given stack=(snake->start)
*/
static void	stack_snake_find_best(t_snake *snake, int stack_size)
{
	int	i;

	snake->max_len = 0;
	i = 0;
	while (i < stack_size)
	{
		stack_snake_count_len(snake, stack_size);
		if (snake->len > snake->max_len)
		{
			snake->max_len = snake->len;
			snake->max_start = snake->start;
		}
		snake->start = snake->start->next;
		i++;
	}
}

/* Counts the elements of the stack that are part of the presorted input */
static void	stack_snake_count_len(t_snake *snake, int stack_size)
{
	int		i;
	int		end_n;
	int		shifted_n;
	t_stack	*tmp;

	tmp = snake->start;
	snake->len = 0;
	end_n = 0;
	i = 0;
	while (i < stack_size)
	{
		shifted_n = snake_shift(tmp->num, snake->start->num, stack_size);
		if (shifted_n >= end_n && shifted_n <= end_n + snake->range)
		{
			end_n = shifted_n;
			snake->len++;
		}
		tmp = tmp->next;
		i++;
	}
}

/* Shifts a given number relative to the base_num, that basenum is 0 */
static int	snake_shift(int num, int base_num, int stack_size)
{
	if (num < base_num)
		return (num - base_num + stack_size);
	else
		return (num - base_num);
}
