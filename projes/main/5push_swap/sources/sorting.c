/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:23:41 by gsever            #+#    #+#             */
/*   Updated: 2022/07/27 03:47:44 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file sorting.c
 * @brief 
 * 
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
#include "../includes/push_swap.h"

/**
 * @brief 
 * @return void
 * @param rra
 * @param ra
 * @bug Not know bugs.
 */
void	final_sort(t_base *base)
{
	int	i;

	i = 1;
	while (base->a[i] != 0)
		i++;
	while (base->a[0] != 0)
	{
		if (i > base->c_a / 2)
			rra(1, base);
		else
			ra(1, base);
	}
}

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
 * @bug first while; score_init_max or compute or perform
 */
void	sort(t_base *base)
{
	int	i;

	i = 0;
	if (base->c_a < 7)
		sort_small(base);
	else
	{
		keep_me(base);
		push_to_b(base);
		int	count = 0;
		while (i < base->mid / 2)
		{
			score_init_max(base);
			compute(base->mid, base);
			perform(base);
			// printf("runned times --> %d\n", count);
			count++;
			i++;
		}
		count = 0;
		while (base->c_b)
		{
			score_init_max(base);//bakmana gerek yok = 0 yapiyor
			compute(base->max, base);
			perform(base);
			// printf("runned times --> %d\n", count);
			count++;
		}
		final_sort(base);//here all sorted but minimum value not top.
	}
	ft_free(base, true);
}
