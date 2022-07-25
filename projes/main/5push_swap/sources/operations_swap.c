/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:31:47 by gsever            #+#    #+#             */
/*   Updated: 2022/07/25 16:01:46 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file operations_swap.c
 * @brief Just 'swap' opearations here.
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
#include "../includes/push_swap.h"

/**
 * @brief Swap 'a' stack's first 2 number.
 * @return void
 * @param write Writing 'sa' on shell.
 * @bug Not know bugs.
 */
void	sa(bool both, t_base *base)
{
	int	tmp;

	tmp = base->a[0];
	base->a[0] = base->a[1];
	base->a[1] = tmp;
	if (both == 1)
		write(1, "sa\n", 3);
}

/**
 * @brief Swap 'b' stack's first 2 number.
 * @return void
 * @param write Writing 'sb' on shell.
 * @bug Not know bugs.
 */
void	sb(bool both, t_base *base)
{
	int	tmp;

	tmp = base->b[0];
	base->b[0] = base->b[1];
	base->b[1] = tmp;
	if (both == 1)
		write(1, "sb\n", 3);
}

/**
 * @brief Swap both stack's first 2 number.
 * @return void
 * @param sa Doing same thing.
 * @param sb Doing same thing.
 * @param write Writing 'ss' on shell.
 * @bug Not know bugs.
 */
void	ss(bool both, t_base *base)
{
	sa(0, base);
	sb(0, base);
	if (both == 1)
		write(1, "ss\n", 3);
}