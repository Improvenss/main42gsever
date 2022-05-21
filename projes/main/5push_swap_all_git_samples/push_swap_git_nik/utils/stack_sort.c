/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:58:18 by vinograd          #+#    #+#             */
/*   Updated: 2019/09/04 20:40:23 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	push_best_nbr(int *stack_a, int *stack_b)
{
	int index;

	index = get_index_of_best_nbr_to_push(stack_a, stack_b);
	rotation(stack_a, stack_b, index);
	totle_commander("pa", stack_a, stack_b);
}

void	stack_sort(int *stack_a, int *stack_b)
{
	int ind_min;

	while (B_LEN > 0)
		push_best_nbr(stack_a, stack_b);
	ind_min = find_min(stack_a, 1);
	if ((ind_min <= A_LEN / 2))
		while (ind_min--)
			totle_commander("rra", stack_a, stack_b);
	else
	{
		ind_min = A_LEN - ind_min;
		while (ind_min--)
			totle_commander("ra", stack_a, stack_b);
	}
}
