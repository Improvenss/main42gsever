/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:20:52 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/25 17:21:06 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **list_a)
{
	int	val;

	val = 0;
	if (ft_lstsize(*list_a) > 1)
	{
		val = (*list_a)->next->data;
		(*list_a)->next->data = (*list_a)->data;
		(*list_a)->data = val;
		write(1, "sa\n", 3);
	}
}

void	sb(t_list **list_b)
{
	int	val;

	val = 0;
	if (ft_lstsize(*list_b) > 1)
	{
		val = (*list_b)->next->data;
		(*list_b)->next->data = (*list_b)->data;
		(*list_b)->data = val;
		write(1, "sb\n", 3);
	}
}

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (ft_lstsize(*list_b) > 0)
	{
		temp = (*list_b);
		*list_b = (*list_b)->next;
		temp->next = *list_a;
		*list_a = temp;
		temp = NULL;
		write(1, "pa\n", 3);
	}
}

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (ft_lstsize(*list_a) > 0)
	{
		temp = (*list_a);
		*list_a = (*list_a)->next;
		temp->next = *list_b;
		*list_b = temp;
		temp = NULL;
		write(1, "pb\n", 3);
	}
}
