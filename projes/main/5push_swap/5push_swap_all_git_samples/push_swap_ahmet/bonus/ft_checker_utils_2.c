/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:52:51 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/27 15:52:53 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	}
}

void	rr(t_list **list_a, t_list **list_b)
{
	ra(list_a);
	rb(list_b);
}
