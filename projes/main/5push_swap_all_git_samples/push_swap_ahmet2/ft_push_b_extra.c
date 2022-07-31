/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:20:39 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/25 17:20:40 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b_v2(t_list **list_a, t_list **list_b, int pivot, int pivot_alt)
{
	int	pivot_alt_alt;

	pivot = ft_pivot_ara(*list_a, ft_lstmin(*list_a), ft_lstmax(*list_a));
	pivot_alt = ft_pivot_ara(*list_a, ft_lstmin(*list_a), pivot);
	pivot_alt_alt = ft_pivot_ara(*list_a, ft_lstmin(*list_a), pivot_alt);
	ft_push_b_fonk(list_a, list_b, pivot_alt, pivot_alt_alt);
}

int	ft_push_a_half_v2(t_list **list_a, t_list **list_b, int pivot)
{	
	int	pivot_up;
	int	pivot_up_up;
	int	i;

	i = 0;
	pivot = ft_pivot_ara(*list_b, ft_lstmin(*list_b), ft_lstmax(*list_b));
	pivot_up = ft_pivot_ara(*list_b, pivot, ft_lstmax(*list_b));
	pivot_up_up = ft_pivot_ara(*list_b, pivot_up, ft_lstmax(*list_b));
	i = ft_push_a_half_v2_p2(list_a, list_b, pivot_up, pivot_up_up);
	return (i);
}

int	ft_push_a_half_v1(t_list **list_a, t_list **list_b, int f)
{
	int	i;
	int	pivot;
	int	pivot_up;

	i = 0;
	pivot = ft_pivot_ara(*list_b, ft_lstmin(*list_b), ft_lstmax(*list_b));
	pivot_up = ft_pivot_ara(*list_b, pivot, ft_lstmax(*list_b));
	i = ft_push_a_half_v1_p2(list_a, list_b, f, pivot_up);
	return (i);
}

int	ft_push_b_half(t_list **list_a, t_list **list_b, int pivot, int pivot_alt)
{
	pivot = ft_pivot_ara(*list_a, ft_lstmin(*list_a), ft_lstmax(*list_a));
	pivot_alt = ft_pivot_ara(*list_a, ft_lstmin(*list_a), pivot);
	ft_push_b_fonk(list_a, list_b, pivot, pivot_alt);
	return (pivot_alt);
}

void	ft_push_b_extra(t_list **list_a, t_list **list_b, \
int first_sup, int second_sup)
{
	int	i;
	int	f;

	i = 0;
	f = ft_push_b_half(list_a, list_b, first_sup, second_sup);
	while ((ft_lstmax(*list_b)) > f)
		i = i + ft_push_a_half_v1(list_a, list_b, f);
	while (ft_lstsize(*list_b) > 0)
		i = i + ft_push_a_half_v2(list_a, list_b, first_sup);
	while (i-- > 0)
		pb(list_a, list_b);
	while (ft_lstsize(*list_a) > 100)
		ft_push_b_v2(list_a, list_b, first_sup, second_sup);
}
