/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:50:14 by vinograd          #+#    #+#             */
/*   Updated: 2019/09/04 20:40:02 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		is_a_sorted(int *stack_a)
{
	int i;
	int ind_min;

	i = A_LEN;
	ind_min = find_min(stack_a, 1);
	while (i > ind_min + 1)
	{
		if (stack_a[i] > stack_a[i - 1])
			return (0);
		i--;
	}
	i--;
	while (i > 1)
	{
		if (stack_a[i] > stack_a[i - 1])
			return (0);
		i--;
	}
	return (A_TOP > A_BOTTOM || ind_min == A_LEN);
}
