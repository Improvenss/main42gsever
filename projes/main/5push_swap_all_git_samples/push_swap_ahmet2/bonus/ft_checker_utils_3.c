/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:53:02 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/27 15:53:04 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	}
}

void	rrr(t_list **list_a, t_list **list_b)
{
	rra(list_a);
	rrb(list_b);
}
