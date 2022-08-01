/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:04:51 by akaraca           #+#    #+#             */
/*   Updated: 2022/06/03 17:04:54 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ten_set_a(t_list **list_a, t_list **list_b, int x)
{
	int	min_place;
	int	place;

	x = 0;
	while (ft_lstsize(*list_a) > 3)
	{
		min_place = ft_place(list_a, ft_lstmin(*list_a));
		place = ft_lstsize(*list_a) / 2;
		if (place >= ft_place(list_a, ft_lstmin(*list_a)))
		{
			min_place = min_place - 1;
			while (min_place-- > 0)
				ra(list_a);
			pb(list_a, list_b);
		}
		else if (place < ft_place(list_a, ft_lstmin(*list_a)))
		{
			min_place = ft_lstsize(*list_a) - min_place + 1;
			while (min_place-- > 0)
				rra(list_a);
			pb(list_a, list_b);
		}
		x++;
	}
	return (x);
}

int	ft_ten_set_b(t_list **list_a, t_list **list_b, int x)
{
	int	max_place;
	int	place;

	x = 0;
	while (ft_lstsize(*list_b) > 3)
	{
		max_place = ft_place(list_b, ft_lstmax(*list_b));
		place = ft_lstsize(*list_b) / 2;
		if (place >= ft_place(list_b, ft_lstmax(*list_b)))
		{
			max_place = max_place - 1;
			while (max_place-- > 0)
				rb(list_b);
			pa(list_a, list_b);
		}
		else if (place < ft_place(list_b, ft_lstmax(*list_b)))
		{
			max_place = ft_lstsize(*list_b) - max_place + 1;
			while (max_place-- > 0)
				rrb(list_b);
			pa(list_a, list_b);
		}
		x++;
	}
	return (x);
}

void	ft_ten_push_half(t_list **list_a, t_list **list_b)
{
	int	max;
	int	min;
	int	pivot;
	int	size;

	max = ft_lstmax(*list_a);
	min = ft_lstmin(*list_a);
	pivot = ft_pivot_ara(*list_a, min, max);
	size = ft_lstsize(*list_a);
	while (size-- > 0)
	{
		if (ft_lstmin(*list_a) == pivot)
			size = 0;
		if ((*list_a)->data >= pivot)
			ra(list_a);
		else if ((*list_a)->data < pivot)
			pb(list_a, list_b);
	}
}
