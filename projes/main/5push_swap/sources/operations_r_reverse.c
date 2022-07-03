/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:35:04 by gsever            #+#    #+#             */
/*   Updated: 2022/07/03 21:30:15 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file operations_r_reverse.c
 * @brief Just 'rotation reverse' operations here.
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
#include "../includes/push_swap.h"

/**
 * @brief Move DOWN the entire 'a' stack numbers once except the LAST number. 
 * Because the LAST number will be the FIRST number.
 * @return void
 * @param write Writing 'rra' on shell.
 * @bug Not know bugs.
 */
void	rra(bool both, t_base *base)
{
	int	i;
	int	tmp;

	i = base->c_a - 1;
	tmp = base->a[i];
	while (i > 0)
	{
		base->a[i] = base->a[i - 1];
		i--;
	}
	base->a[0] = tmp;
	if (both == 1)
		write(1, "rra\n", 4);
}

/**
 * @brief Move DOWN the entire 'b' stack numbers once except the LAST number. 
 * Because the LAST number will be the FIRST number.
 * @return void
 * @param write Writing 'rrb' on shell.
 * @bug Not know bugs.
 */
void	rrb(bool both, t_base *base)
{
	int	i;
	int	tmp;

	i = base->c_b - 1;
	tmp = base->b[i];
	while (i > 0)
	{
		base->b[i] = base->b[i - 1];
		i--;
	}
	base->b[0] = tmp;
	if (both == 1)
		write(1, "rrb\n", 4);
}

/**
 * @brief Move DOWN the entire 'a' and 'b' stack numbers once except 
 * the LAST numbers. Because the LAST numbers will be the FIRST numbers.
 * @return void
 * @param rra Doing same thing.
 * @param rrb Doing same thing.
 * @param write Writing 'ra' on shell.
 * @bug Not know bugs.
 */
void	rrr(t_base *base)
{
	rra(0, base);
	rrb(0, base);
	write(1, "rrr\n", 4);
}