/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:55:29 by gsever            #+#    #+#             */
/*   Updated: 2022/06/27 21:57:21 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file push_swap.c
 * @brief Push_Swap program starting here.
 * 
 * 
 * @author Görkem SEVER (gsever)
 * @bug 
 */
#include "../includes/push_swap.h"

/**
	@brief PUSH_SWAP

	This program will sort random integers on a stack, with a limited set of
instructions, trying to use the least stack_ops to get a sorted stack.

	The input is given by starting the program with additional arguments.
	Possible Arguments:
	- integers (4 Bytes), positive or negative without any duplicates
	- every number seperated by a single space
	- formatted in a single string or given as multiple arguments

	Sample command to launch the program with 500 random values:
	./push_swap `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`

Steps;
	1. - Check is numbers are sorted.
	2. - ?
	3. - Find max and min number.
	4. - Mark max and min number.
	5. - 
	@param
	@return
 */
int	main(int argc, char **argv)
{
	t_base	stack;

	arg_checker(argc, argv, &stack);
	stack.a = malloc(sizeof(int) * stack.start.size);
	stack.b = malloc(sizeof(int) * stack.start.size);
	stack.c = malloc(sizeof(int) * stack.start.size);

}
