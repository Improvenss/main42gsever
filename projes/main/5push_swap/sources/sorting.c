/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:23:41 by gsever            #+#    #+#             */
/*   Updated: 2022/07/17 17:56:13 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file sorting.c
 * @brief 
 * 
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
#include "../includes/push_swap.h"

/**
 * @brief Sorting steps and algorithms starting here.
 * 
 * @param sort_small If your numbers count < 7; running.
 * @param keep_me ??
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
void	sort(t_base *base)
{
	// int	i;

	// i = 0;
	if (base->c_a < 7)
	{
		printf("sayilarimiz = %d --> 6 ve daha az sayimiz oldugu icin sort_small() func giriyoruz.\n", base->c_a);
		sort_small(base);
	}
	else
	{
		keep_me(base);
	}
}