/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:08:06 by tjensen           #+#    #+#             */
/*   Updated: 2022/06/21 22:49:43 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Return "true" if a given number is inside a stack */
bool	stack_is_num_inside(t_stack *stack, int num)
{
	t_stack	*tmp;

	if (stack == NULL)
		return (false);
	tmp = stack;
	while (tmp->next->num != stack->num)
	{
		if (tmp->num == num)
			return (true);
		tmp = tmp->next;
	}
	if (tmp->num == num)
		return (true);
	return (false);
}

/* Return "true" if a given number is the biggest number in a stack */
bool	stack_is_biggest(t_stack *stack, int num)
{
	t_stack	*tmp;

	if (stack == NULL)
		return (true);
	tmp = stack;
	while (tmp->next->num != stack->num)
	{
		if (tmp->num > num)
			return (false);
		tmp = tmp->next;
	}
	if (tmp->num > num)
		return (false);
	return (true);
}

/* Return "true" if a given number is the smallest number in a stack */
bool	stack_is_smallest(t_stack *stack, int num)
{
	t_stack	*tmp;

	if (stack == NULL)
		return (true);
	tmp = stack;
	while (tmp->next->num != stack->num)
	{
		if (tmp->num < num)
			return (false);
		tmp = tmp->next;
	}
	if (tmp->num < num)
		return (false);
	return (true);
}
