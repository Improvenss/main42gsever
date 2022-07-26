/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_push_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:19:43 by gsever            #+#    #+#             */
/*   Updated: 2022/07/27 02:03:16 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file algorithms_push_b.c
 * @brief Sorting algorithms for push number to stack b.
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
#include "../includes/push_swap.h"

/**
 * @brief If number count > 7 running this func.
 * @return void
 * @bug Not know bugs.
 */
void	keep_me(t_base *base)
{
	int	i;
	int	index;

	base->c_c = 2;
	base->c[0] = base->max;
	base->c[1] = 0;
	i = 0;
	index = 1;
	while (base->a[i] > 0)
		i++;
	while (base->a[i] < base->max)
	{
		if (base->a[i] == index)
		{
			base->c[base->c_c] = base->a[i];
			base->c_c++;
			index++;
		}
		if (i == base->c_a - 1)
		{
			i = 0;
			continue ;
		}
		i++;
	}
}

/**
 * @brief Disaridan gelen sayiyi stack'imizin icinde ariyor.
 * Buldugunda 1, bulamadiginda 0 donduruyor.
 * @return int
 * @bug Not know bugs.
 */
int	ps_finder(int c, t_base *base)
{
	int	i;

	i = 0;
	while (i <= base->c_c)
	{
		if (base->c[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief If number match in stack 'c', doing ra.
 * If number not match, pb.
 * @return void
 * @param ps_finder Searching number in stack.
 * @bug Not know bugs.
 */
void	push_to_norme(t_base *base)
{
	int	i;

	i = 0;
	while (i < base->c_a)
	{
		if (ps_finder(base->a[0], base) > 0)
		{
			ra(1, base);
			i++;
			continue ;
		}
		pb(1, base);
	}
}

/**
 * @brief 
 * @return void
 * @param ps_finder
 * @param ra
 * @param pb
 * @param rb
 * @param push_to_norme
 * @bug Not know bugs.
 */
void	push_to_b(t_base *base)
{
	int	i;

	i = 0;
	while (i < base->c_a)
	{
		if (ps_finder(base->a[0], base) > 0
			|| base->a[0] <= base->max / 4)
		{
			ra(1, base);
			i++;
			continue ;
		}
		pb(1, base);
		if (base->b[0] > base->mid)
			rb(1, base);
	}
	push_to_norme(base);
}
