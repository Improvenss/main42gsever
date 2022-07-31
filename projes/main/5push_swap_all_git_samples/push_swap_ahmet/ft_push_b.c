/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:20:16 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/25 17:20:26 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ten(t_list **list_a, t_list **list_b)
{
	int	x;
	int	size;

	x = 0;
	ft_ten_push_half(list_a, list_b);
	x = ft_ten_set_b(list_a, list_b, x);
	ft_three_reverse(list_b);
	while (x-- > 0)
		pb(list_a, list_b);
	x = ft_ten_set_a(list_a, list_b, x);
	ft_three(list_a);
	while (x-- > 0)
		pa(list_a, list_b);
	size = ft_lstsize(*list_b);
	while (size-- > 0)
		pa(list_a, list_b);
}

void	ft_three(t_list **list_a)
{
	int	min;
	int	max;
	int	i;

	min = ft_lstmin(*list_a);
	max = ft_lstmax(*list_a);
	i = ft_lstsize(*list_a);
	while (i > 1)
	{
		if ((*list_a)->data < (*list_a)->next->data && i != 2 \
				&& (*list_a)->next->next->data != max)
			rra(list_a);
		if ((*list_a)->data == max && (*list_a)->next->data == min)
			ra(list_a);
		if ((*list_a)->data == max && (*list_a)->next->data != min)
		{
			sa(list_a);
			rra(list_a);
		}
		if ((*list_a)->data > min)
			sa(list_a);
		i--;
	}
}

void	ft_push_b_fonk(t_list **list_a, t_list **list_b, \
		int pivot, int pivot_alt)
{
	int	size;

	size = ft_lstsize(*list_a);
	while (size-- > 0)
	{
		if (ft_lstmin(*list_a) <= pivot)
		{
			if ((*list_a)->data <= pivot)
			{
				if ((*list_a)->data <= pivot_alt)
				{
					pb(list_a, list_b);
					rb(list_b);
				}
				else
					pb(list_a, list_b);
			}
			else
				ra(list_a);
		}
		else
			size = 0;
	}
}

void	ft_push_b(t_list **list_a, t_list **list_b, int pivot, int pivot_alt)
{
	pivot = ft_pivot_ara(*list_a, ft_lstmin(*list_a), ft_lstmax(*list_a));
	pivot_alt = ft_pivot_ara(*list_a, ft_lstmin(*list_a), pivot);
	ft_push_b_fonk(list_a, list_b, pivot, pivot_alt);
}
