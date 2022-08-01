/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:22:13 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/12 18:23:35 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	reverse rotate A - shift down all elements of stack A by 1.
**	The last element becomes the first one.
*/

#include "utils.h"

void	rra(int *stack_a)
{
	int last;
	int i;

	if (A_LEN > 1)
	{
		last = stack_a[1];
		i = 2;
		while (i <= A_LEN)
		{
			stack_a[i - 1] = stack_a[i];
			i++;
		}
		stack_a[A_LEN] = last;
	}
}
