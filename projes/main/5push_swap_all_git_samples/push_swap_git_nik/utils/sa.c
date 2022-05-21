/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:07:08 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/12 17:43:24 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	swap the first 2 elements at the top of stack A
*/

#include "utils.h"

void	sa(int *stack_a)
{
	int first;

	if (A_LEN > 1)
	{
		first = stack_a[A_LEN];
		stack_a[A_LEN] = stack_a[A_LEN - 1];
		stack_a[A_LEN - 1] = first;
	}
}
