/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:47:38 by bbourcy           #+#    #+#             */
/*   Updated: 2022/04/27 11:11:20 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// trouve le nombre mini
int	find_min(int size, t_base *base)
{
	int		i;
	int		min;

	i = 0;
	min = base->a[i];
	while (i < size)
	{
		if (base->a[i] < min)
			min = base->a[i];
		i++;
	}
	return (min);
}

// trouve nombre max
int	find_max(int size, t_base *base)
{
	int		i;
	int		max;

	i = 0;
	max = base->a[i];
	while (i < size)
	{
		if (base->a[i] > max)
			max = base->a[i];
		i++;
	}
	return (max);
}

// indexer les valeurs
void	indexer(int size, t_base *base)
{
	is_repeated(base);
	base->start.min = find_min(size, base);
	base->start.max = find_max(size, base);
	markup(base->start.size, base->start.max + 1, base->start.min - 1, base);
	remark(size, base);
	base->max = base->start.size - 1;
	base->c_a = base->start.size;
	base->c_b = 0;
	base->mid = (base->start.size + 1) / 2;
}

void	markup(int size, int index, int prev, t_base *base)
{
	int		i;
	int		tmp;

	if (index > size + base->start.max)
		return ;
	tmp = base->start.max;
	i = 0;
	while (i < size)
	{
		if (base->a[i] > prev && base->a[i] <= tmp)
			tmp = base->a[i];
		++i;
	}
	markup_norme(&i, &index, &tmp, base);
	markup(size, ++index, tmp, base);
}

void	remark(int size, t_base *base)
{
	int		i;

	i = 0;
	while (i < size)
	{
		base->a[i] -= (base->start.max + 1);
		++i;
	}
	return ;
}
