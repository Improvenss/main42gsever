/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:55:34 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:55:35 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	push(t_stack *put, t_stack *take)
{
	if (take->size > 0)
		stack_push(put, stack_pop(take));
}

void	pa(t_collection *collection)
{
	push(collection->a, collection->b);
}

void	pb(t_collection *collection)
{
	push(collection->b, collection->a);
}
