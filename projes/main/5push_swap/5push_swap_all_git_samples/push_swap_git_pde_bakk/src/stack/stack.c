/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:56:51 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:56:53 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "utils.h"

t_collection	*create_stacks(void)
{
	t_collection	*out;

	out = (t_collection *)ft_calloc(1, sizeof(t_collection));
	if (out == NULL)
		fatal_error(out, "Error allocating memory for stack collection");
	out->a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (out->a == NULL)
		fatal_error(out, "Error allocating memory for stack A");
	out->a->id = 'a';
	out->b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (out->b == NULL)
		fatal_error(out, "Error allocating memory for stack B");
	out->b->id = 'b';
	return (out);
}

void	delete_stack(t_stack *stack)
{
	while (stack->size > 0)
		free(stack_pop(stack));
	free(stack);
	stack = NULL;
}

//t_collection *copy_stacks(const t_collection *stack) {
//	t_collection	*out;
//	t_stacknode		*tmp_old;
//
//	out = create_stacks();
//	tmp_old = stack->a->bottom;
//	while (tmp_old)
//	{
//		stack_push(out->a, tmp_old->data);
//		tmp_old = tmp_old->next;
//	}
//	tmp_old = stack->b->bottom;
//	while (tmp_old)
//	{
//		stack_push(out->b, tmp_old->data);
//		tmp_old = tmp_old->next;
//	}
//	return (out);
//}
