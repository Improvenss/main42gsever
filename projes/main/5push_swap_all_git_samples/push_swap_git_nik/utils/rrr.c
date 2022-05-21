/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:48:11 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/12 17:51:08 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	rra and rrb at the same time
*/

#include "utils.h"

void	rrr(int *stack_a, int *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
