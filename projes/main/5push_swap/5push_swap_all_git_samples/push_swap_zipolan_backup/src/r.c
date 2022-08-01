/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:54:33 by bbourcy           #+#    #+#             */
/*   Updated: 2022/04/27 10:52:58 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(int bool, t_base *base)
{
	int		i;
	int		tmp;

	tmp = base->a[0];
	i = 0;
	while (i < base->c_a - 1)
	{
		base->a[i] = base->a[i + 1];
		++i;
	}
	base->a[i] = tmp;
	if (bool == 1)
		write(1, "ra\n", 3);
}

void	rb(int bool, t_base *base)
{
	int		i;
	int		tmp;

	tmp = base->b[0];
	i = 0;
	while (i < base->c_b - 1)
	{
		base->b[i] = base->b[i + 1];
		++i;
	}
	base->b[i] = tmp;
	if (bool == 1)
		write(1, "rb\n", 3);
}

void	rr(t_base *base)
{
	ra(0, base);
	rb(0, base);
	write(1, "rr\n", 3);
}
