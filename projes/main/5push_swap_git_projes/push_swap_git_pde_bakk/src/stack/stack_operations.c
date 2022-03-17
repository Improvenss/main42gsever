/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:56:59 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:57:08 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "stack.h"

static t_stacknode	*new_node(int data)
{
	t_stacknode	*node;

	node = (t_stacknode *)ft_calloc(1, sizeof(t_stacknode));
	if (!node)
		fatal_error(NULL, "Error allocating memory for new stacknode");
	node->data = data;
	return (node);
}

void	stack_push(t_stack *stack, t_stacknode *node)
{
	if (stack->size == 0)
		stack->bottom = node;
	else
	{
		stack->top->next = node;
		node->prev = stack->top;
	}
	stack->top = node;
	stack->size++;
}

void	stack_push_under(t_stack *stack, int item)
{
	t_stacknode	*node;

	node = new_node(item);
	if (stack->size == 0)
		stack->top = node;
	else
	{
		stack->bottom->prev = node;
		node->next = stack->bottom;
	}
	stack->bottom = node;
	stack->size++;
}

// Function to remove an item from stack. It decreases size by 1

t_stacknode	*stack_pop(t_stack *stack)
{
	t_stacknode	*tmp;

	if (stack_is_empty(stack))
		return (NULL);
	tmp = stack->top;
	stack->top = tmp->prev;
	tmp->prev = NULL;
	if (stack->top)
		stack->top->next = NULL;
	--stack->size;
	return (tmp);
}

// Function to return the top from stack without removing it

int	stack_peek(const t_stack *stack)
{
	if (stack_is_empty(stack))
		return (INT_MIN);
	return (stack->top->data);
}
