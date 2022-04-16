/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:18:58 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/12 17:45:05 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Push A - take the first element at the top of B and put it at the top of A
*/

#include "utils.h"

void	pa(int *stack_a, int *stack_b)
{
	if (B_LEN > 0)
		stack_a[++A_LEN] = stack_b[B_LEN--];
}
