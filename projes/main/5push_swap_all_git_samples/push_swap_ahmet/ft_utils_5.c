/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:22:16 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/25 17:22:23 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_place_check(t_list *list_a)
{
	t_list	*temp;

	temp = list_a;
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	ft_exit(int error)
{
	if (error != 0)
		write(1, "Error\n", 7);
	exit(error);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
