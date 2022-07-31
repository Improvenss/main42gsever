/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:21:21 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/25 17:21:29 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **list_a)
{
	t_list	*temp;

	if (ft_lstsize(*list_a) > 1)
	{
		temp = *list_a;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *list_a;
		*list_a = (*list_a)->next;
		temp->next->next = NULL;
		temp = NULL;
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **list_b)
{
	t_list	*temp;

	if (ft_lstsize(*list_b) > 1)
	{
		temp = *list_b;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *list_b;
		*list_b = (*list_b)->next;
		temp->next->next = NULL;
		temp = NULL;
		write(1, "rb\n", 3);
	}
}

void	rra(t_list **list_a)
{
	t_list	*temp;

	if (ft_lstsize(*list_a) > 2)
	{
		temp = *list_a;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *list_a;
		*list_a = temp->next;
		temp->next = NULL;
		temp = NULL;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **list_b)
{
	t_list	*temp;

	if (ft_lstsize(*list_b) > 2)
	{
		temp = *list_b;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *list_b;
		*list_b = temp->next;
		temp->next = NULL;
		temp = NULL;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (ft_lstsize(*list_a) > 2 && ft_lstsize(*list_b) > 2)
	{
		temp = *list_a;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *list_a;
		*list_a = temp->next;
		temp->next = NULL;
		temp = NULL;
		temp = *list_b;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *list_b;
		*list_b = temp->next;
		temp->next = NULL;
		temp = NULL;
		write(1, "rrr\n", 4);
	}
}
