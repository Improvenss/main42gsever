/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 00:35:41 by Nik               #+#    #+#             */
/*   Updated: 2019/08/29 16:29:10 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		commander(char *cmd, int *stack_a, int *stack_b)
{
	if (ft_strequ(cmd, "sa"))
		sa(stack_a);
	else if (ft_strequ(cmd, "sb"))
		sb(stack_b);
	else if (ft_strequ(cmd, "ss"))
		ss(stack_a, stack_b);
	else if (ft_strequ(cmd, "pa"))
		pa(stack_a, stack_b);
	else if (ft_strequ(cmd, "pb"))
		pb(stack_a, stack_b);
	else if (ft_strequ(cmd, "ra"))
		ra(stack_a);
	else if (ft_strequ(cmd, "rb"))
		rb(stack_b);
	else if (ft_strequ(cmd, "rr"))
		rr(stack_a, stack_b);
	else if (ft_strequ(cmd, "rra"))
		rra(stack_a);
	else if (ft_strequ(cmd, "rrb"))
		rrb(stack_b);
	else if (ft_strequ(cmd, "rrr"))
		rrr(stack_a, stack_b);
	return (1);
}
