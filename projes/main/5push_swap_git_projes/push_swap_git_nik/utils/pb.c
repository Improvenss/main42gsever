/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:39:24 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/12 15:43:20 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Push B - take the first element at the top of A and put it at the top of B
*/

#include "utils.h"

void	pb(int *stack_a, int *stack_b)
{
	pa(stack_b, stack_a);
}
