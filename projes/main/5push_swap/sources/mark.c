/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:46:39 by gsever            #+#    #+#             */
/*   Updated: 2022/06/28 14:00:36 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	markup_norme(int *i, int *index, int *tmp, t_base *base)
{
	while (*i >= 0)
	{
		if (*tmp == 0)
		{
			if (base->a[*i] == 0)
				base->a[*i] = *index;
		}
		if (base->a[*i] == *tmp)
		{
			base->a[*i] = *index;
			break ;
		}
		(*i)++;
	}
}

void	markup(int size, int index, int prev, t_base *base)
{
	int	i;
	int	tmp;

	if (index > size + base->start.max)
		return ;
	tmp = base->start.max;
	i = 0;
	while (i < size)
	{
		if (base->a[i] > prev && base->a[i] <= tmp)
			tmp = base->a[i];
		i++;
	}
	markup_norme(&i, &index, &tmp, base);
	markup(size, ++index, tmp, base);
}

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