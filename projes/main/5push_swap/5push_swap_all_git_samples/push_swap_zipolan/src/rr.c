/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:54:33 by bbourcy           #+#    #+#             */
/*   Updated: 2022/04/27 11:09:49 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(int bool, t_base *base)
{
	int		i;
	int		tmp;

	i = base->c_a - 1;
	tmp = base->a[i];
	while (i > 0)
	{
		base->a[i] = base->a[i - 1];
		--i;
	}
	base->a[0] = tmp;
	if (bool == 1)
		write(1, "rra\n", 4);
}

void	rrb(int bool, t_base *base)
{
	int		i;
	int		tmp;

	i = base->c_b - 1;
	tmp = base->b[i];
	while (i > 0)
	{
		base->b[i] = base->b[i - 1];
		--i;
	}
	base->b[0] = tmp;
	if (bool == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_base *base)
{
	rra(0, base);
	rrb(0, base);
	write(1, "rrr\n", 4);
}
