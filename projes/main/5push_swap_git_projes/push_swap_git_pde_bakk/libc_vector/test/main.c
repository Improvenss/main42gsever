/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:52:33 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:52:35 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

int	fakemain(void)
{
	t_vector	*vec;
	int			i;

	i = 0;
	vec = vector_init(0);
	while (i < 30)
	{
		vector_pushback(vec, i);
		++i;
	}
	printf("Capacity is %zu\n", vec->capacity);
	i = 0;
	vector_delete_byval(vec, 10);
	vector_delete_bypos(vec, 10);
	vector_delete_bypos(vec, 13);
	while ((size_t)i < vec->size)
	{
		printf("vec[%d]: {%d}\n", i, vec->arr[i]);
		++i;
	}
	printf("vector has item %d at index %zd\n", 20, \
		vector_find_by_value(vec, 20));
	vector_destroy(vec);
	return (0);
}

int	main(void)
{
	fakemain();
	return (0);
}
