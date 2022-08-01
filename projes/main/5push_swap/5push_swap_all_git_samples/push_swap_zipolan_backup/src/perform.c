/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:47:38 by bbourcy           #+#    #+#             */
/*   Updated: 2022/04/25 18:35:32 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	perform_norme(t_base *base)
{
	while (base->best.ra)
	{
		ra(1, base);
		--base->best.ra;
	}
	while (base->best.rb)
	{
		rb(1, base);
		--base->best.rb;
	}
	while (base->best.rra)
	{
		rra(1, base);
		--base->best.rra;
	}
	while (base->best.rrb)
	{
		rrb(1, base);
		--base->best.rrb;
	}
}

void	perform(t_base *base)
{
	perform_norme(base);
	while (base->best.rr)
	{
		rr(base);
		--base->best.rr;
	}
	while (base->best.rrr)
	{
		rrr(base);
		--base->best.rrr;
	}
	pa(base);
}
