/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:47:05 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:47:07 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "../include_internal/utils.h"
#include <stdlib.h>

static void	vector_realloc(t_vector *vec, size_t newsize)
{
	size_t	i;
	CONTENT	*new_arr;

	new_arr = calloc_wrapper(newsize + 1, sizeof(CONTENT));
	i = 0;
	while (i < vec->size)
	{
		new_arr[i] = vec->arr[i];
		++i;
	}
	free(vec->arr);
	vec->arr = new_arr;
	vec->capacity = newsize;
}

t_vector	*vector_init(size_t init_size)
{
	t_vector	*vec;

	if (init_size == 0)
		init_size = 1;
	vec = calloc_wrapper(1, sizeof(t_vector));
	vec->capacity = init_size;
	vec->arr = calloc_wrapper(init_size + 1, sizeof(CONTENT));
	return (vec);
}

void	vector_pushback(t_vector *vec, CONTENT item)
{
	if (vec->size == vec->capacity)
	{
		vector_realloc(vec, vec->capacity * 2);
	}
	vec->arr[vec->size] = item;
	++vec->size;
}

ssize_t	vector_find_by_value(t_vector *vec, CONTENT to_find)
{
	size_t	i;

	i = 0;
	while (i < vec->size)
	{
		if (vec->arr[i] == to_find)
			return ((ssize_t)i);
		++i;
	}
	return (-1);
}
