/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:42:19 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/15 12:30:13 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Initializes every stack_item with a given num, next & prev pointers
**	At the end the whole stack becomes a circular linked list.
*/
void	stack_item_init(t_stack *stack, int size, int position, int count)
{
	stack[position].num = count;
	stack[position].is_snake = false;
	if (position == 0 && size == 1)
	{
		stack[position].next = &stack[position];
		stack[position].prev = &stack[position];
	}
	else if (position == 0)
	{
		stack[position].next = &stack[position + 1];
		stack[position].prev = &stack[size - 1];
	}
	else if (position == size - 1)
	{
		stack[position].next = &stack[0];
		stack[position].prev = &stack[position - 1];
	}
	else
	{
		stack[position].next = &stack[position + 1];
		stack[position].prev = &stack[position - 1];
	}
}

/* Returns a pointer to the top of a stack with initialized items */
t_stack	*stack_get_a(t_input *input)
{
	int		i;
	int		count;
	int		*int_array;
	t_stack	*a_top;

	a_top = malloc(input->size * sizeof(t_stack));
	if (a_top == NULL)
		input_exit(input, ENOMEM);
	int_array = input->int_array;
	i = 0;
	while (i < input->size)
	{
		count = array_count_smaller(int_array, input->size, int_array[i]);
		stack_item_init(a_top, input->size, i, count);
		i++;
	}
	return (a_top);
}

/* Returns a pointer to a malloced memory to store all stack_items */
t_stack	*stack_get_mem(t_ps *ps)
{
	t_stack	*stack;

	stack = malloc(ps->size * sizeof(t_stack));
	if (stack == NULL)
		ft_atexit(ps, ENOMEM);
	return (stack);
}
