/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:54:33 by bbourcy           #+#    #+#             */
/*   Updated: 2022/07/03 19:07:15 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_base *base)
{
	int	i;

	i = base->c_a;
	while (i > 0)
	{
		base->a[i] = base->a[i - 1];
		--i;
	}
	base->a[0] = base->b[0];
	base->c_b -= 1;
	while (i < base->c_b)
	{
		base->b[i] = base->b[i + 1];
		i++;
	}
	base->c_a += 1;
	write(1, "pa\n", 3);
}

void	pb(t_base *base)
{
	int	i;

	i = base->c_b;
	while (i > 0)
	{
		base->b[i] = base->b[i - 1];
		i--;
	}
	base->b[0] = base->a[0];
	base->c_a -= 1;
	while (i < base->c_a)
	{
		base->a[i] = base->a[i + 1];
		++i;
	}
	base->c_b += 1;
	write(1, "pb\n", 3);
}

void	sa(t_base *base)
{
	int		tmp;

	tmp = base->a[0];
	base->a[0] = base->a[1];
	base->a[1] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_base *base)
{
	int		tmp;

	tmp = base->b[0];
	base->b[0] = base->b[1];
	base->b[1] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_base *base)
{
	sa(base);
	sb(base);
	write(1, "ss\n", 3);
}
