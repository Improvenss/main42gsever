/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:18:40 by gsever            #+#    #+#             */
/*   Updated: 2022/07/03 18:43:07 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file sort_small.c
 * @brief 
 * 
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
#include "../includes/push_swap.h"

void	push_smallest(int a, t_base *base)
{
	int	i;
	int	smallest;

	i = i;
	smallest = base->a[0];
	while (i < a)
	{
		
	}
}

void	six_sort(t_base *base)
{
	int	diff;
	int	i;

	i = 0;
	diff = base->start.size - 3;
	while (i < diff)
	{
		push_smallest(base->start.size - i, base);
		i++;
	}
}

void	sort_small(t_base *base)
{
	if (base->c_a == 2)
		sa(base);
	six_sort(base);
}