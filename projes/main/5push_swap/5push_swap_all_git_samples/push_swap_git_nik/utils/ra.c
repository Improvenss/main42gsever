/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:03:50 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/12 17:42:00 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	rotate A - shift up all elements of stack A by 1.
**	The first element becomes the last one
*/

#include "utils.h"

void	ra(int *stack_a)
{
	int first;
	int i;

	if (A_LEN > 1)
	{
		first = stack_a[A_LEN];
		i = A_LEN - 1;
		while (i > 0)
		{
			stack_a[i + 1] = stack_a[i];
			i--;
		}
		stack_a[1] = first;
	}
}
