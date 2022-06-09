/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 21:15:53 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:47:56 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	descretize_stack(t_deque *stack, int *arr, int arr_size)
{
	t_double_list	*temp;

	temp = stack->head;
	while (temp)
	{
		*((int *)temp->content) = binary_search(arr, arr_size,
				*((int *)temp->content));
		temp = temp->next;
	}
}

int	check_order(t_deque *stack[2])
{
	int				ct;
	t_double_list	*temp;

	if (stack[1]->size != 0)
		return (0);
	ct = -1;
	temp = stack[0]->tail;
	while (++ct < stack[0]->size)
	{
		if (*((int *)temp->content) != ct)
			return (0);
		temp = temp->last;
	}
	return (1);
}
