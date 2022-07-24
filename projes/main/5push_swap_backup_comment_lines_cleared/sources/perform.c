/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:02:19 by gsever            #+#    #+#             */
/*   Updated: 2022/07/21 02:05:51 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file perform.c
 * @brief 
 * 
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
#include "../includes/push_swap.h"

/**
 * @brief 
 * @return void
 * @bug Not know bugs.
 */
void	perform_norme(t_base *base)
{
	while (base->best.ra)
	{
		ra(1, base);
		base->best.ra--;
	}
	while (base->best.rb)
	{
		rb(1, base);
		base->best.rb--;
	}
	while (base->best.rra)
	{
		rra(1, base);
		base->best.rra--;
	}
	while (base->best.rrb)
	{
		rrb(1, base);
		base->best.rrb--;
	}
}

/**
 * @brief 
 * @return void
 * @bug Not know bugs.
 */
void	perform(t_base *base)
{
	perform_norme(base);
	while (base->best.rr)
	{
		rr(base);
		base->best.rr--;
	}
	while (base->best.rrr)
	{
		rrr(base);
		base->best.rrr--;
	}
	pa(base);
}