/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:23:41 by gsever            #+#    #+#             */
/*   Updated: 2022/07/21 02:36:35 by gsever           ###   ########.fr       */
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
 * @bug Not know bugs.
 */
void	sort(t_base *base)
{
	int	i;

	i = 0;
	if (base->c_a < 7)
	{
		printf("sayilarimiz = %d --> 6 ve daha az sayimiz oldugu icin sort_small() func giriyoruz.\n", base->c_a);
		write_all_stack(base);
		sort_small(base);
		write_all_stack(base);
	}
	else
	{
		printf("sayilarimiz = %d --> 7 ve uzerinde oldugu icin ana sorting algoritmamiz basladi.\n", base->c_a);
		write_all_stack(base);
		keep_me(base);
		write_all_stack(base);
		push_to_b(base);
		write_all_stack(base);
		while (i < base->mid / 2)
		{
			score_init_max(base);
			compute(base->max, base);
			perform(base);
			i++;
		}
		write_all_stack(base);
		while (base->c_b)
		{
			score_init_max(base);
			compute(base->max, base);
			perform(base);
		}
		write_all_stack(base);
		final_sort(base);
		write_all_stack(base);
	}
	ft_free(base);
}