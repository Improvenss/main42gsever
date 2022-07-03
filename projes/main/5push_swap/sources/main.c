/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:55:29 by gsever            #+#    #+#             */
/*   Updated: 2022/07/03 18:02:17 by gsever           ###   ########.fr       */
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
	2. - Stack a, b, c icin yer actik.
	3. - Fill stack with arguman's numbers.
	4. - 
	5. - 
	@param arg_checker
	@param malloc
	@param stack_fill
	@param stack_fill_double_quotation
	@param ft_free
	@param ft_error
	@param indexer
	@param is_sorted
	@return
 */
int	main(int argc, char **argv)
{
	t_base	stack;

	printf("\033[0;33m##########	PUSH_SWAP BASLADI	######################\033[0m\n");
	printf("arg_checker'e giriyoruz, agumanlarimizi alip kendi stack'imize eklememiz gerekiyor.\n");
	arg_checker(argc, argv, &stack);
	stack.a = malloc(sizeof(int) * stack.start.size);
	printf("stack->a icin yer acildi\n");
	stack.b = malloc(sizeof(int) * stack.start.size);
	printf("stack->b icin yer acildi\n");
	stack.c = malloc(sizeof(int) * stack.start.size);
	printf("stack->c icin yer acildi\n");
	if (argc > 2)
	{
		printf("argumanlarimiz 2'den fazla stack_fill func gidiyoruz\n");
		stack_fill(argc, argv, &stack);
		printf("stack_fill func ciktik\n");
	}
	else if (argc == 2)
	{
		printf("2 tane argumanimiz var o yuzden stack_fill_double_quotation func gidiyoruz\n");
		stack_fill_double_quotation(ft_split(argv[1], ' '), &stack);
		printf("stack_fill_double_quotation func ciktik.\n");
	}
	else
	{
		printf("argumanlarimiz yanlis o yuzden bellegimizi freeleyip programi bitireceigiz.\n");
		ft_free(&stack);
	}
	if (!stack.a || !stack.b || !stack.c)
		ft_error("Error\n");
	is_sorted(&stack);
	printf("sayilarimiz hazir simdi bunlari indexlememiz lazim giriyoruz\n");
	indexer(stack.start.size, &stack);
	is_sorted(&stack);
	sort(&stack);
}
