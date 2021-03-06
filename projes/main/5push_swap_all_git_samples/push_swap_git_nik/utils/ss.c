/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:17:22 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/12 15:45:21 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	sa and sb at the same time
*/

#include "utils.h"

void	ss(int *stack_a, int *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
