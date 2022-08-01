/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:36:13 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/19 10:29:30 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	PUSH_SWAP
**
**	This program will sort random integers on a stack, with a limited set of
**	instructions, trying to use the least stack_ops to get a sorted stack.
**
**	The input is given by starting the program with additional arguments.
**	Possible Arguments:
**	- integers (4 Bytes), positive or negative without any duplicates
**	- every number seperated by a single space
**	- formatted in a single string or given as multiple arguments
**
**	Sample command to launch the program with 500 random values:
**	./push_swap `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
*/

int	main(int argc, char *argv[])
{
	t_ps	push_swap;

	push_swap.input = input_struct_get();
	input_check(push_swap.input, argc, argv, true);
	push_swap_struct_init(&push_swap);
	input_struct_destroy(&(push_swap.input));
	if (push_swap.a_size < 7)
		stack_sort_small(&push_swap);
	else
		stack_sort_big(&push_swap);
	ft_atexit(&push_swap, EXIT_SUCCESS);
}
