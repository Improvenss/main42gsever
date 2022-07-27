/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:54:33 by bbourcy           #+#    #+#             */
/*   Updated: 2022/07/27 03:19:00 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	final_sort(t_base *base)
{
	int		i;

	i = 1;
	while (base->a[i] != 0)
		++i;
	while (base->a[0] != 0)
	{
		if (i > base->c_a / 2)
			rra(1, base);
		else
			ra(1, base);
	}
}

void	small_sort(t_base *base)
{
	if (base->c_a == 2)
		sa(base);
	six_sort(base);
}

void	ft_free(t_base *base)
{
	free(base->a);
	free(base->b);
	free(base->c);
	exit(0);
}

void	sort(t_base *base)
{
	int		i;

	i = 0;
	if (base->c_a < 7)
		small_sort(base);
	else
	{
		keep_me(base);
		push_to_b(base);
		while (i < base->mid / 2)
		{
			score_init_max(base);
			compute(base->mid, base);
			perform(base);
			++i;
		}
		// while (base->c_b)
		// {
		// 	score_init_max(base);
		// 	compute(base->max, base);
		// 	perform(base);
		// }
		// final_sort(base);
	}
	ft_free(base);
}
