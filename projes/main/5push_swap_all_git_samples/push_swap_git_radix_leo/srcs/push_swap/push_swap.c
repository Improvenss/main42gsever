/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:58:28 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:48:49 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	generate_instructions(t_deque *stack[2], char *str,
t_deque *instructions)
{
	assigned_operation(str, stack);
	deque_push_back(instructions, str);
}

void	display_instructions(t_deque *instructions, int *arr,
int arr_size, int fd)
{
	t_deque			*stack[2];
	t_double_list	*iter;

	stack[0] = deque_init();
	stack[1] = deque_init();
	if (!stack[0] || !stack[1])
		error_exit();
	init_stack(stack[0], arr, arr_size);
	if (DEBUG == 1)
		display_stacks(stack, "Init a and b");
	iter = instructions->head;
	while (iter)
	{
		assigned_operation(iter->content, stack);
		if (DEBUG == 1)
			display_stacks(stack, iter->content);
		else
			ft_putendl_fd(iter->content, fd);
		iter = iter->next;
	}
}

t_deque	*push_swap(t_deque *stack[2])
{
	t_deque	*instructions;

	instructions = deque_init();
	if (check_order(stack))
		return (instructions);
	if (stack[0]->size <= 5)
		easy_solve(stack, instructions);
	else if (stack[0]->size <= 100)
		medium_solve(stack, instructions);
	else
		hard_solve(stack, instructions);
	return (instructions);
}
