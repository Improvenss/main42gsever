/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sorted_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:56:25 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:56:27 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "stack.h"
#include <sys/types.h>

t_vector	*dump_items(const t_collection *coll)
{
	t_vector	*vec;
	t_stacknode	*tmp;

	vec = vector_init(coll->a->size);
	tmp = coll->a->bottom;
	while (tmp)
	{
		vector_pushback(vec, tmp->data);
		tmp = tmp->next;
	}
	return (vec);
}

void	build_arrays_of_indices(t_vector *all_items, t_collection *coll)
{
	t_stacknode	*tmp;
	ssize_t		sorted_pos;

	tmp = coll->a->bottom;
	while (tmp)
	{
		sorted_pos = vector_find_by_value(all_items, tmp->data);
		if (sorted_pos != -1)
			tmp->sorted_pos = sorted_pos;
		tmp = tmp->next;
	}
}

void	set_sorted_pos(t_collection *coll)
{
	t_vector	*all_items;

	all_items = dump_items(coll);
	vector_sort(all_items);
	build_arrays_of_indices(all_items, coll);
	vector_destroy(all_items);
}
