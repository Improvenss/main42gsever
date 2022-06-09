/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:23:15 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:56:29 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	find_target_from_tail(int target, t_deque *stack)
{
	t_double_list	*temp;
	int				cnt;

	temp = stack->tail;
	cnt = 0;
	while (temp)
	{
		if (*((int *)temp->content) == target)
			return (cnt);
		cnt++;
		temp = temp->last;
	}
	return (-1);
}

static void	sub(int end, t_deque *stack[2], t_deque *instructions)
{
	int	rotate_b;

	while (stack[1]->size > 0)
	{
		rotate_b = find_target_from_tail(--end, stack[1]);
		if (rotate_b <= stack[1]->size - rotate_b)
			while (rotate_b-- > 0)
				generate_instructions(stack, "rb", instructions);
		else
			while (stack[1]->size - rotate_b++ > 0)
				generate_instructions(stack, "rrb", instructions);
		generate_instructions(stack, "pa", instructions);
	}
}

static void	solve(int begin, int end,
t_deque *stack[2], t_deque *instructions)
{
	int	rotate_a;

	while (stack[1]->size < end - begin)
	{
		if (*((int *)stack[0]->tail->content) >= begin
			&& *((int *)stack[0]->tail->content) < end)
			generate_instructions(stack, "pb", instructions);
		else
			generate_instructions(stack, "ra", instructions);
	}
	if (end < stack[0]->size + stack[1]->size)
	{
		rotate_a = find_target_from_tail(end, stack[0]);
		if (rotate_a <= stack[0]->size - rotate_a)
			while (rotate_a-- > 0)
				generate_instructions(stack, "ra", instructions);
		else
			while (stack[0]->size - rotate_a++ > 0)
				generate_instructions(stack, "rra", instructions);
	}
	sub(end, stack, instructions);
}

void	medium_solve(t_deque *stack[2], t_deque *instructions)
{
	int	group_size;
	int	idx;
	int	size;

	size = stack[0]->size;
	group_size = ft_sqrt(8 * size);
	idx = size;
	while (idx > 0)
	{
		solve(ft_max(0, idx - group_size), idx, stack, instructions);
		idx = ft_max(0, idx - group_size);
	}
}
