/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:34:32 by gsever            #+#    #+#             */
/*   Updated: 2022/07/21 02:00:18 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file compute.c
 * @brief 
 * 
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
#include "../includes/push_swap.h"

/**
 * @brief When current is the best, doing best to current.
 * @return void
 * @bug Not know bugs.
 */
void	copy_the_best(t_base *base)
{
	base->best.ra = base->current.ra;
	base->best.rb = base->current.rb;
	base->best.rra = base->current.rra;
	base->best.rrb = base->current.rrb;
	base->best.rr = base->current.rr;
	base->best.rrr = base->current.rrr;
	base->best.score = base->current.score;
}

/**
 * @brief Merging ra and rra.
 * @return void
 * @bug Not know bugs.
 */
void	merge_rr(t_base *base)
{
	while (base->current.ra && base->current.rb)
	{
		base->current.rr++;
		base->current.ra--;
		base->current.rb--;
	}
	while (base->current.rra && base->current.rrb)
	{
		base->current.rrr++;
		base->current.rra--;
		base->current.rrb--;
	}
}

/**
 * @brief Computing reverse a
 * @return void
 * @bug Not know bugs.
 */
void	count_ra(int b, t_base *base)
{
	int	i;

	i = 0;
	if (base->a[0] > b && base->a[base->c_a - 1] < b)
	{
		base->current.ra = 0;
		return ;
	}
	while (i < base->c_a)
	{
		if (b > base->a[i] && b < base->a[i + 1])
		{
			i++;
			if (i > base->c_a / 2)
				base->current.rra = base->c_a - i;
			else
				base->current.ra = i;
			return ;
		}
		i++;
	}
}

/**
 * @brief 
 * @return void
 * @bug Not know bugs.
 */
void	compute(int max, t_base *base)
{
	int	i;

	i = 0;
	while (i < base->c_b)
	{
		if (base->b[i] > max)
		{
			i++;
			continue ;
		}
		score_init(base);
		if (i > base->c_b / 2)
			base->current.rrb = base->c_b - i;
		else
			base->current.rb = i;
		count_ra(base->b[i], base);
		merge_rr(base);
		base->current.score = base->current.ra + base->current.rb
			+ base->current.rra + base->current.rrb
			+ base->current.rr + base->current.rrr;
		if (base->current.score < base->best.score)
			copy_the_best(base);
		i++;
	}
}