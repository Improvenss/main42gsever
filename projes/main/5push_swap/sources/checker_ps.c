/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:53:35 by gsever            #+#    #+#             */
/*   Updated: 2022/07/25 02:28:17 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Sorting steps and algorithms starting here.
 * @return void
 * @param sort_small If your numbers count < 7; running.
 * @param keep_me ??
 * @param push_to_b
 * @param score_init_max
 * @param compute
 * @param perform
 * @param final_sort
 * @param ft_free
 * @bug Not know bugs.
 */
static void	sort_checker(t_base *base)
{
	int	i;

	i = 0;
	if (base->c_a < 7)
	{
		sort_small(base);
	}
	else
	{
		keep_me(base);
		push_to_b(base);
		while (i < base->mid / 2)
		{
			score_init_max(base);
			compute(base->max, base);
			perform(base);
			i++;
		}
		while (base->c_b)
		{
			score_init_max(base);
			compute(base->max, base);
			perform(base);
		}
		final_sort(base);
	}
	// ft_free(base, false);
}

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
		ft_free(stack, true);
	}
	if (!stack->a || !stack->b || !stack->c)
		ft_error("Error\n");
	is_sorted(stack);
	indexer(stack->start.size, stack);
	is_sorted(stack);
	sort_checker(stack);
	// ft_free(stack, true);
}