/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_sa_work.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:08:05 by vinograd          #+#    #+#             */
/*   Updated: 2019/09/04 17:46:45 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	is_in_right_order_two_first_nbrs(int *stack_a)
{
	return ((stack_a[A_LEN - 2] > A_SEC\
	&& A_TOP < A_SEC) && (is_in_right_order(stack_a)));
}

int			does_sa_work(int *stack_a, int *stack_b)
{
	int res;
	int max;
	int min;
	int distanse;

	max = find_max(stack_a, 1);
	min = find_min(stack_a, 1);
	distanse = MAX(min, max) - MIN(min, max);
	if ((max >= A_LEN - 1 || min >= A_LEN - 1) && (distanse == 1))
		return (0);
	commander("sa", stack_a, stack_b);
	res = is_in_right_order_two_first_nbrs(stack_a);
	commander("sa", stack_a, stack_b);
	return (res);
}
