/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:52:37 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:52:42 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

int	fakemain(void)
{
	static char *const	strs[] = {
		"RA", "RB", "SA", "SB", "SSA", "SSB"
	};
	t_vector			*vec;
	int					i;

	i = 0;
	vec = vector_init(0);
	while (i < 30)
	{
		vector_pushback(vec, strs[rand() % 6]);
		++i;
	}
	printf("Capacity is %zu\n", vec->capacity);
	vector_delete_byval(vec, "RA");
	vector_delete_bypos(vec, 4);
	i = 0;
	while ((size_t)i < vec->size)
	{
		printf("vec[%d]: {%s}\n", i, vec->arr[i]);
		++i;
	}
	vector_destroy(vec);
	return (0);
}

int	main(void)
{
	fakemain();
	return (0);
}
