/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:31:42 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/27 16:31:44 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free(t_list **list_a)
{
	t_list	*temp;

	while (*list_a != NULL)
	{
		temp = (*list_a)->next;
		free(*list_a);
		*list_a = temp;
	}
	*list_a = NULL;
}
