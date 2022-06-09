/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:23:15 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:57:05 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	final_move(t_deque *stack[2], t_deque *instructions, int digit_move)
{
	int	cnt[2];

	cnt[0] = 0;
	cnt[1] = stack[0]->size;
	while (cnt[0]++ < cnt[1])
	{
		if ((*((int *)stack[0]->tail->content) >> digit_move) % 2 == 0)
			generate_instructions(stack, "pb", instructions);
		else
			generate_instructions(stack, "ra", instructions);
	}
	while (stack[1]->size > 0)
		generate_instructions(stack, "pa", instructions);
}

static void	sub(t_deque *stack[2], t_deque *instructions,
int digit_move, int cnt[2])
{
	cnt[1] = stack[1]->size;
	while (cnt[0]++ < cnt[1])
	{
		if ((*((int *)stack[1]->tail->content) >> digit_move) % 2)
			generate_instructions(stack, "pa", instructions);
		else
			generate_instructions(stack, "rb", instructions);
	}
	while (stack[1]->size > 0)
		generate_instructions(stack, "pa", instructions);
}

static void	normal_move(t_deque *stack[2], t_deque *instructions,
int digit_move)
{
	int	cnt[2];

	cnt[0] = 0;
	if (stack[0]->size > 0)
	{
		cnt[1] = stack[0]->size;
		while (cnt[0]++ < cnt[1])
		{
			if ((*((int *)stack[0]->tail->content) >> digit_move) % 2 == 0)
				generate_instructions(stack, "pb", instructions);
			else
				generate_instructions(stack, "ra", instructions);
		}
		while (stack[0]->size > 0)
			generate_instructions(stack, "pb", instructions);
	}
	else
		sub(stack, instructions, digit_move, cnt);
}

void	hard_solve(t_deque *stack[2], t_deque *instructions)
{
	int	move;
	int	now_move;

	move = 0;
	while ((1 << move) < stack[0]->size)
		++move;
	now_move = 0;
	while (now_move++ < move)
	{
		if (now_move == move && now_move % 2)
			final_move(stack, instructions, now_move - 1);
		else
			normal_move(stack, instructions, now_move - 1);
	}
}
