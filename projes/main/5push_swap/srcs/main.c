/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:55:29 by gsever            #+#    #+#             */
/*   Updated: 2022/06/22 03:37:13 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
	PUSH_SWAP

	This program will sort random integers on a stack, with a limited set of
instructions, trying to use the least stack_ops to get a sorted stack.

	The input is given by starting the program with additional arguments.
	Possible Arguments:
	- integers (4 Bytes), positive or negative without any duplicates
	- every number seperated by a single space
	- formatted in a single string or given as multiple arguments

	Sample command to launch the program with 500 random values:
	./push_swap `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
*/
int	main(int argc, char **argv)
{
	t_ps	push_swap;

	
}