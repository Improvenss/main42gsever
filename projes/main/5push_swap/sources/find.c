/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:04:11 by gsever            #+#    #+#             */
/*   Updated: 2022/07/26 20:11:59 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief	Finding stack's MIN number.
 * @return	Minimum number.
 * @bug		Not know bugs.
 */
int	find_min(int size, t_base *base)
{
	int	i;
	int	min;

	i = 0;
	min = base->a[i];
	while (i < size)
	{
		if (base->a[i] < min)
		{
			min = base->a[i];
		}
		i++;
	}
	return (min);
}

/**
 * @brief	Finding stack's MAX number.
 * @return	Maximum number.
 * @bug		Not know bugs.
 */
int	find_max(int size, t_base *base)
{
	int	i;
	int	max;

	i = 0;
	max = base->a[i];
	while (i < size)
	{
		if (base->a[i] > max)
		{
			max = base->a[i];
		}
		i++;
	}
	return (max);
}
