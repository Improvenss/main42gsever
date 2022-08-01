/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:24:06 by bbourcy           #+#    #+#             */
/*   Updated: 2022/07/27 03:32:29 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// compteur reverse a
void	count_ra(int b, t_base *base)
{
	int		i;

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
			++i;
			if (i > base->c_a / 2)
				base->current.rra = base->c_a - i;
			else
				base->current.ra = i;
			return ;
		}
		++i;
	}
}

// fusionne pour rr et rrr
void	merge_rr(t_base *base)
{
	while (base->current.ra && base->current.rb)
	{
		++base->current.rr;
		--base->current.ra;
		--base->current.rb;
	}
	while (base->current.rra && base->current.rrb)
	{
		++base->current.rrr;
		--base->current.rra;
		--base->current.rrb;
	}
}

void	copy_to_best(t_base *base)
{
	base->best.ra = base->current.ra;
	base->best.rb = base->current.rb;
	base->best.rra = base->current.rra;
	base->best.rrb = base->current.rrb;
	base->best.rr = base->current.rr;
	base->best.rrr = base->current.rrr;
	base->best.score = base->current.score;
}

void	score_init_max(t_base *base)
{
	base->best.ra = 0;
	base->best.rb = 0;
	base->best.rra = 0;
	base->best.rrb = 0;
	base->best.rr = 0;
	base->best.rrr = 0;
	base->best.score = 10000000;
}

void	compute(int max, t_base *base)
{
	int		i;

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
			base->current.rrb = (base->c_b - i);
		else
			base->current.rb = i;
		count_ra(base->b[i], base);
		merge_rr(base);
		base->current.score = base->current.ra + base->current.rb
			+ base->current.rra + base->current.rrb
			+ base->current.rr + base->current.rrr;
		if (base->current.score < base->best.score)
			copy_to_best(base);
		++i;
	}
}
