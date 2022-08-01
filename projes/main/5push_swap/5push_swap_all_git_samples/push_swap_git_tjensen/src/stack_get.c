/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:42:25 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/14 16:42:35 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Searchs for the biggest num in a stack and returns it */
int	stack_get_biggest(t_stack *stack)
{
	int		biggest;
	t_stack	*tmp;

	if (stack == NULL)
		return (STACK_EMPTY);
	tmp = stack;
	biggest = stack->num;
	while (tmp->next->num != stack->num)
	{
		tmp = tmp->next;
		if (biggest < tmp->num)
			biggest = tmp->num;
	}
	return (biggest);
}

/* Searchs for the smallest num in a stack and returns it */
int	stack_get_smallest(t_stack *stack)
{
	int		smallest;
	t_stack	*tmp;

	if (stack == NULL)
		return (STACK_EMPTY);
	tmp = stack;
	smallest = stack->num;
	while (tmp->next->num != stack->num)
	{
		tmp = tmp->next;
		if (smallest > tmp->num)
			smallest = tmp->num;
	}
	return (smallest);
}

/* Searchs for the next bigger num for a given num in a stack and returns it */
int	stack_get_next_bigger(t_stack *stack, int num)
{
	int		bigger;
	t_stack	*tmp;

	if (stack == NULL)
		return (STACK_EMPTY);
	tmp = stack;
	bigger = stack_get_biggest(stack);
	if (bigger < num)
		return (stack_get_smallest(stack));
	while (tmp->next->num != stack->num)
	{
		if (num < tmp->num && bigger > tmp->num)
			bigger = tmp->num;
		tmp = tmp->next;
	}
	if (num < tmp->num && bigger > tmp->num)
		bigger = tmp->num;
	return (bigger);
}

/* Searchs for the next smaller num for a given num in a stack and returns it */
int	stack_get_next_smaller(t_stack *stack, int num)
{
	int		smaller;
	t_stack	*tmp;

	if (stack == NULL)
		return (STACK_EMPTY);
	tmp = stack;
	smaller = stack_get_smallest(stack);
	if (smaller > num)
		return (stack_get_biggest(stack));
	while (tmp->next->num != stack->num)
	{
		if (num > tmp->num && smaller < tmp->num)
			smaller = tmp->num;
		tmp = tmp->next;
	}
	if (num > tmp->num && smaller < tmp->num)
		smaller = tmp->num;
	return (smaller);
}
