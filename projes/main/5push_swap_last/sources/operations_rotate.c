/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:34:11 by gsever            #+#    #+#             */
/*   Updated: 2022/07/25 16:01:13 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file operations_rotate.c
 * @brief Just 'rotate' operations here.
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
#include "../includes/push_swap.h"

/**
 * @brief Move UP the entire 'a' stack numbers once except the FIRST number. 
 * Because the FIRST number will be the LAST number.
 * @return void
 * @param write Writing 'ra' on shell.
 * @bug Not know bugs.
 */
void	ra(bool both, t_base *base)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = base->a[0];
	while (i < base->c_a - 1)
	{
		base->a[i] = base->a[i + 1];
		i++;
	}
	base->a[i] = tmp;
	if (both == 1)
		write(1, "ra\n", 3);
}

/**
 * @brief Move UP the entire 'b' stack numbers once except the FIRST number. 
 * Because the FIRST number will be the LAST number.
 * @return void
 * @param write Writing 'rb' on shell.
 * @bug Not know bugs.
 */
void	rb(bool both, t_base *base)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = base->b[0];
	while (i < base->c_b - 1)
	{
		base->b[i] = base->b[i + 1];
		i++;
	}
	base->b[i] = tmp;
	if (both == 1)
		write(1, "rb\n", 3);
}

/**
 * @brief Move UP the entire 'a' and 'b' stack numbers once except 
 * the FIRST numbers. Because the FIRST numbers will be the LAST numbers.
 * @return void
 * @param ra Doing same thing.
 * @param rb Doing same thing.
 * @param write Writing 'rr' on shell.
 * @bug Not know bugs.
 */
void	rr(bool both, t_base *base)
{
	ra(0, base);
	rb(0, base);
	if (both == 1)
		write(1, "rb\n", 3);
}