/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:50:53 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/27 15:51:04 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list **list_a)
{
	int	val;

	if (ft_lstsize(*list_a) > 1)
	{
		val = (*list_a)->next->data;
		(*list_a)->next->data = (*list_a)->data;
		(*list_a)->data = val;
	}
}

void	sb(t_list **list_b)
{
	int	val;

	if (ft_lstsize(*list_b) > 1)
	{
		val = (*list_b)->next->data;
		(*list_b)->next->data = (*list_b)->data;
		(*list_b)->data = val;
	}
}

void	ss(t_list **list_a, t_list **list_b)
{
	sa(list_a);
	sb(list_b);
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
	}
}
