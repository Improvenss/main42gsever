/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:18:40 by gsever            #+#    #+#             */
/*   Updated: 2022/07/27 01:57:56 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file sort_small.c
 * @brief If the number count smaller than 7, starting "Small Sorting" here.
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
#include "../includes/push_swap.h"

/**
 * @brief Sorting numbers count < 7
 * @return void
 * @param sa
 * @param ra
 * @param rra
 * @bug Not know bugs.
 */
void	sort_blood(t_base *base)
{
	if (base->a[0] < base->a[1] && base->a[0]
		< base->a[2] && base->a[1] > base->a[2])
	{
		sa(1, base);
		ra(1, base);
	}
	else if (base->a[0] > base->a[1] && base->a[0] < base->a[2])
		sa(1, base);
	else if (base->a[0] < base->a[1] && base->a[0] > base->a[2])
		rra(1, base);
	else if (base->a[0] > base->a[2] && base->a[1]
		< base->a[2] && base->a[0] > base->a[1])
		ra(1, base);
	else if (base->a[0] > base->a[1] && base->a[1] > base->a[2])
	{
		sa(1, base);
		rra(1, base);
	}
}

/**
 * @brief En kucuk sayiyi pushlayacagiz, onun icin butun diziyi tariyoruz,
 * en kucuk sayi gelince onu b stackine pushluyoruz.
 * @return void
 * @param rra
 * @param ra
 * @param pb
 * @bug Not know bugs.
 */
void	push_smallest(int a, t_base *base)
{
	int	i;
	int	smallest;

	i = 1;
	smallest = base->a[0];
	while (i < a)
	{
		if (base->a[i] < smallest)
			smallest = base->a[i];
		++i;
	}
	i = -1;
	while (i++ < a - 1)
	{
		if (base->a[i] == smallest)
			break ;
	}
	while (base->a[0] != smallest)
	{
		if (i > base->c_a / 2)
			rra(1, base);
		else
			ra(1, base);
	}
	pb(1, base);
}

/**
 * @brief 
 * @return void
 * @param push_smallest
 * @bug Not know bugs.
 */
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
	sort_blood(base);
	i = 0;
	while (i < diff)
	{
		pa(1, base);
		i++;
	}
}

/**
 * @brief If number count < 7 running this func.
 * @return void
 * @param sa If number count 2 starting.
 * @param six_sort If number count not 2 starting.
 * @bug Not know bugs.
 */
void	sort_small(t_base *base)
{
	if (base->c_a == 2)
		sa(1, base);
	six_sort(base);
}
