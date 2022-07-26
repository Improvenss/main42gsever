/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:30:53 by gsever            #+#    #+#             */
/*   Updated: 2022/07/26 20:11:40 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file operations_push.c
 * @brief Just 'push' operations here.
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
#include "../includes/push_swap.h"

/**
 * @brief Pushing first(top) number of stack 'b' 
 * to the first(top) row of stack 'a'.
 * @return void
 * @param write Writing 'pa' on shell.
 * @bug Not know bugs.
 */
void	pa(bool both, t_base *base)
{
	int	i;

	i = base->c_a;
	while (i > 0)
	{
		base->a[i] = base->a[i - 1];
		i--;
	}
	base->a[0] = base->b[0];
	base->c_b -= 1;
	while (i < base->c_b)
	{
		base->b[i] = base->b[i + 1];
		i++;
	}
	base->c_a += 1;
	if (both == 1)
		write(1, "pa\n", 3);
}

/**
 * @brief Pushing first(top) number of stack 'a' 
 * to the first(top) row of stack 'b'.
 * @return void
 * @param write Writing 'pb' on shell.
 * @bug Not know bugs.
 */
void	pb(bool both, t_base *base)
{
	int	i;

	i = base->c_b;
	while (i > 0)
	{
		base->b[i] = base->b[i - 1];
		i--;
	}
	base->b[0] = base->a[0];
	base->c_a -= 1;
	while (i < base->c_a)
	{
		base->a[i] = base->a[i + 1];
		i++;
	}
	base->c_b += 1;
	if (both == 1)
		write(1, "pb\n", 3);
}
