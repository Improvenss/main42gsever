/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotation_set.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:57:03 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/13 12:29:42 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Searchs and sets the most efficient rotations for a given num
**	origin: stack_B, target: stack_A
*/
void	stack_rot_set_b_to_a(t_ps *ps, t_sort *sort, int num)
{
	stack_rot_count_from(ps->b_top, sort->rb_rrb_count, num);
	stack_rot_count_to_asc(ps->a_top, sort->ra_rra_count, num);
	stack_rot_case_set(sort, stack_rot_case_choose(sort));
	sort->rotation_sum = sort->ra_rra_count[0] + sort->ra_rra_count[1]
		+ sort->rb_rrb_count[0] + sort->rb_rrb_count[1]
		+ sort->rr_rrr_count[0] + sort->rr_rrr_count[1];
}

/*
**	Searchs and sets the most efficient rotations for a given "end" num
**	to rotate the stack_A at the end in the right position
*/
void	stack_rot_set_end(t_ps *ps, t_sort *sort, int num)
{
	sort->rb_rrb_count[0] = 0;
	sort->rb_rrb_count[1] = 0;
	stack_rot_count_to_asc(ps->a_top, sort->ra_rra_count, num);
	stack_rot_case_set(sort, stack_rot_case_choose(sort));
	sort->rotation_sum = sort->ra_rra_count[0] + sort->ra_rra_count[1]
		+ sort->rb_rrb_count[0] + sort->rb_rrb_count[1]
		+ sort->rr_rrr_count[0] + sort->rr_rrr_count[1];
}
