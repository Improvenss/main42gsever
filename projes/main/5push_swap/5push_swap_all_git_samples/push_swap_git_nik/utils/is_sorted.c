/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:27:11 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/19 16:39:55 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		is_sorted(int *stack_a, int *stack_b)
{
	int i;

	i = A_LEN;
	if (B_LEN != 0)
		return (0);
	while (i > 1)
	{
		if (stack_a[i] >= stack_a[i - 1])
			return (0);
		i--;
	}
	return (1);
}
