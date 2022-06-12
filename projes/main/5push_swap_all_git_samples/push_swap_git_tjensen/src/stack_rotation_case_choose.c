/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotation_case_choose.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:35:15 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/14 17:15:09 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Choose a rotation case with the least rotations overall for both stacks */
int	stack_rot_case_choose(t_sort *sort)
{
	int	rotation_case;
	int	min;
	int	rotation_count;

	rotation_case = RA_RB;
	min = ft_max(sort->ra_rra_count[0], sort->rb_rrb_count[0]);
	rotation_count = ft_max(sort->ra_rra_count[1], sort->rb_rrb_count[1]);
	if (rotation_count < min)
	{
		min = rotation_count;
		rotation_case = RRA_RRB;
	}
	rotation_count = sort->ra_rra_count[0] + sort->rb_rrb_count[1];
	if (rotation_count < min)
	{
		min = rotation_count;
		rotation_case = RA_RRB;
	}
	rotation_count = sort->ra_rra_count[1] + sort->rb_rrb_count[0];
	if (rotation_count < min)
		rotation_case = RRA_RB;
	return (rotation_case);
}
