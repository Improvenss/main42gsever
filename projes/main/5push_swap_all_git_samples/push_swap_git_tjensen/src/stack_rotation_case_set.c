/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotation_case_set.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:09:30 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/14 16:58:00 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_rot_case_set_ra_rb(t_sort *sort);
static void	stack_rot_case_set_rra_rrb(t_sort *sort);
static void	stack_rot_case_set_ra_rrb(t_sort *sort);
static void	stack_rot_case_set_rra_rb(t_sort *sort);

/* Sets and resets all rotation_counts for a given rotation_case */
void	stack_rot_case_set(t_sort *sort, int rotation_case)
{
	if (rotation_case == RA_RB)
		stack_rot_case_set_ra_rb(sort);
	else if (rotation_case == RRA_RRB)
		stack_rot_case_set_rra_rrb(sort);
	else if (rotation_case == RA_RRB)
		stack_rot_case_set_ra_rrb(sort);
	else if (rotation_case == RRA_RB)
		stack_rot_case_set_rra_rb(sort);
}

static void	stack_rot_case_set_ra_rb(t_sort *sort)
{
	sort->ra_rra_count[1] = 0;
	sort->rb_rrb_count[1] = 0;
	sort->rr_rrr_count[1] = 0;
	if (sort->ra_rra_count[0] > sort->rb_rrb_count[0])
	{
		sort->rr_rrr_count[0] = sort->rb_rrb_count[0];
		sort->ra_rra_count[0] -= sort->rb_rrb_count[0];
		sort->rb_rrb_count[0] = 0;
	}
	else
	{
		sort->rr_rrr_count[0] = sort->ra_rra_count[0];
		sort->rb_rrb_count[0] -= sort->ra_rra_count[0];
		sort->ra_rra_count[0] = 0;
	}
}

static void	stack_rot_case_set_rra_rrb(t_sort *sort)
{
	sort->ra_rra_count[0] = 0;
	sort->rb_rrb_count[0] = 0;
	sort->rr_rrr_count[0] = 0;
	if (sort->ra_rra_count[1] > sort->rb_rrb_count[1])
	{
		sort->rr_rrr_count[1] = sort->rb_rrb_count[1];
		sort->ra_rra_count[1] -= sort->rb_rrb_count[1];
		sort->rb_rrb_count[1] = 0;
	}
	else
	{
		sort->rr_rrr_count[1] = sort->ra_rra_count[1];
		sort->rb_rrb_count[1] -= sort->ra_rra_count[1];
		sort->ra_rra_count[1] = 0;
	}
}

static void	stack_rot_case_set_ra_rrb(t_sort *sort)
{
	sort->ra_rra_count[1] = 0;
	sort->rb_rrb_count[0] = 0;
	sort->rr_rrr_count[0] = 0;
	sort->rr_rrr_count[1] = 0;
}

static void	stack_rot_case_set_rra_rb(t_sort *sort)
{
	sort->ra_rra_count[0] = 0;
	sort->rb_rrb_count[1] = 0;
	sort->rr_rrr_count[0] = 0;
	sort->rr_rrr_count[1] = 0;
}
