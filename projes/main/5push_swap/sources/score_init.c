/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:39:44 by gsever            #+#    #+#             */
/*   Updated: 2022/07/26 20:10:54 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file score_init.c
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
void	score_init(t_base *base)
{
	base->current.ra = 0;
	base->current.rb = 0;
	base->current.rra = 0;
	base->current.rrb = 0;
	base->current.rr = 0;
	base->current.rrr = 0;
	base->current.score = 0;
}

/**
 * @brief 
 * @return void
 * @bug Not know bugs.
 */
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
