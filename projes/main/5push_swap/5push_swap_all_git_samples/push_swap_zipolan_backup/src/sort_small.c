/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:54:33 by bbourcy           #+#    #+#             */
/*   Updated: 2022/04/25 18:35:28 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	pb(base);
}

void	sort_blood(t_base *base)
{
	if (base->a[0] < base->a[1] && base->a[0]
		< base->a[2] && base->a[1] > base->a[2])
	{
		sa(base);
		ra(1, base);
	}
	else if (base->a[0] > base->a[1] && base->a[0] < base->a[2])
		sa(base);
	else if (base->a[0] < base->a[1] && base->a[0] > base->a[2])
		rra(1, base);
	else if (base->a[0] > base->a[2] && base->a[1]
		< base->a[2] && base->a[0] > base->a[1])
		ra(1, base);
	else if (base->a[0] > base->a[1] && base->a[1] > base->a[2])
	{
		sa(base);
		rra(1, base);
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
		++i;
	}
	sort_blood(base);
	i = 0;
	while (i < diff)
	{
		pa(base);
		++i;
	}
}
