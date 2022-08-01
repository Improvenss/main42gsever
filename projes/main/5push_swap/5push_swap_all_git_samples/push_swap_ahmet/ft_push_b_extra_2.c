/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b_extra_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:47:15 by akaraca           #+#    #+#             */
/*   Updated: 2022/06/02 11:47:17 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_a_half_fonk(t_list **list_a, t_list **list_b, \
int x, int pivot_up_up)
{
	x = 0;
	if ((*list_b)->data <= pivot_up_up)
	{
		pa(list_a, list_b);
		ra(list_a);
		x++;
	}
	else
		pa(list_a, list_b);
	return (x);
}

int	ft_push_a_half_v2_p2(t_list **list_a, t_list **list_b, \
int pivot_up, int pivot_up_up)
{
	int	size;
	int	x;
	int	i;

	i = 0;
	x = 0;
	size = ft_lstsize(*list_b);
	while (size-- > 0)
	{
		if ((*list_b)->data >= pivot_up)
		{
			x = x + ft_push_a_half_fonk(list_a, list_b, x, pivot_up_up);
			i++;
		}
		else
			rb(list_b);
	}
	ft_rrr_rra_rrb(list_a, list_b, x, 0);
	return (i);
}

int	ft_push_a_half_v1_p2(t_list **list_a, t_list **list_b, \
int f, int pivot_up)
{
	int	size;
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	size = ft_lstsize(*list_b);
	while ((*list_b)->data > f && size-- > 0)
	{
		if ((*list_b)->data >= pivot_up)
		{
			x = x + ft_push_a_half_fonk(list_a, list_b, x, \
			ft_pivot_ara(*list_b, pivot_up, ft_lstmax(*list_b)));
			i++;
		}
		else
		{
			rb(list_b);
			y++;
		}
	}
	ft_rrr_rra_rrb(list_a, list_b, x, y);
	return (i);
}
