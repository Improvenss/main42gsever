/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:47:12 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:47:49 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

static size_t	find_desired_position(t_vector *vec, const CONTENT nb)
{
	size_t	i;

	i = 0;
	while (vec->arr[i] < nb)
	{
		++i;
	}
	return (i);
}

static void	reinsert(t_vector *vec, size_t index)
{
	const CONTENT	value = vec->arr[index];
	size_t			desired_pos;

	desired_pos = find_desired_position(vec, value);
	while (index > desired_pos)
	{
		vec->arr[index] = vec->arr[index - 1];
		--index;
	}
	vec->arr[desired_pos] = (CONTENT)value;
}

void	vector_sort(t_vector *vec)
{
	size_t	i;

	i = 1;
	while (i < vec->size)
	{
		if (vec->arr[i] < vec->arr[i - 1])
		{
			reinsert(vec, i);
		}
		++i;
	}
}
