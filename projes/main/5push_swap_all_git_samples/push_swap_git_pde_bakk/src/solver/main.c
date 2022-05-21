/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:56:05 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:56:06 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include "solver.h"
#include "vector.h"

int	main(int argc, char **argv)
{
	t_collection	*coll;
	t_vector		*operations;
	int				i;

	coll = create_stacks();
	i = 1;
	if (argc == 1)
		return (cleanup(coll));
	while (i < argc)
	{
		parse_split_array(coll, argv[i]);
		++i;
	}
	set_sorted_pos(coll);
	if (coll->a->size <= 5)
		operations = smol_sort(coll);
	else
		operations = chunk_sort(coll);
	optimize_instructions(operations);
	print_all_operations(operations);
	vector_destroy(operations);
	return (cleanup(coll));
}
