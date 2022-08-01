/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:55:31 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/19 10:00:44 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Initialized some values in the push_swap-Struct */
void	push_swap_struct_init(t_ps *push_swap)
{
	push_swap->a_size = push_swap->input->size;
	push_swap->b_size = 0;
	push_swap->size = push_swap->a_size;
	push_swap->a_top = stack_get_a(push_swap->input);
	push_swap->stack_mem = push_swap->a_top;
	push_swap->b_top = NULL;
}

/* Copies all values from a *src to a *dest including the item memory */
void	push_swap_struct_cpy(t_ps *dest, t_ps *src)
{
	dest->a_size = src->a_size;
	dest->b_size = src->b_size;
	dest->size = src->size;
	dest->a_top = src->a_top;
	dest->b_top = src->b_top;
	ft_memcpy(dest->stack_mem, src->stack_mem, src->a_size * sizeof(t_stack));
}

/* Exits the program and frees all malloced memory */
void	ft_atexit(t_ps *push_swap, int status)
{
	if (status == INVALID_INPUT)
		ft_putendl_fd("Error", STDERR_FILENO);
	input_struct_destroy(&(push_swap->input));
	free(push_swap->stack_mem);
	push_swap->stack_mem = NULL;
	exit(status);
}
