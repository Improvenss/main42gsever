/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:53:35 by gsever            #+#    #+#             */
/*   Updated: 2022/07/25 00:04:45 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief 
 * @return void
 * @param arg_checker
 * @param malloc
 * @param stack_fill
 * @param stack_fill_double_quotation
 * @param ft_free
 * @param ft_error
 * @param indexer
 * @param is_sorted
 */
void	push_swap_checker(t_base *stack, int argc, char **argv)
{

	arg_checker(argc, argv, stack);
	stack->a = malloc(sizeof(int) * stack->start.size);
	stack->b = malloc(sizeof(int) * stack->start.size);
	stack->c = malloc(sizeof(int) * stack->start.size);
	if (argc > 2)
	{
		stack_fill(argc, argv, stack);
	}
	else if (argc == 2)
	{
		stack_fill_double_quotation(ft_split(argv[1], ' '), stack);
	}
	else
	{
		ft_free(stack);
	}
	if (!stack->a || !stack->b || !stack->c)
		ft_error("Error\n");
	indexer(stack->start.size, stack);
	ft_free(stack);
}