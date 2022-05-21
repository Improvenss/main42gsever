/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:45:51 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:45:53 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "vector.h"
# include "stack.h"

t_vector	*radix_sort(t_collection *coll);

t_vector	*chunk_sort(t_collection *stacks);
void		push_chunks_to_b(t_collection *stacks, t_vector *operations, \
							int CHUNK_SIZE, int CHUNK_AMOUNT);
void		push_back_to_a(t_collection *stacks, t_vector *operations, \
							int CHUNK_SIZE, int CHUNK_AMOUNT);

t_vector	*smol_sort(t_collection *stacks);

void		set_sorted_pos(t_collection *coll);
t_opcode	get_rotation_direction(const t_stack *stack, ssize_t steps);

ssize_t		find_steps(size_t to_find, t_stacknode *startnode);
void		add_operation(t_opcode op, t_collection *stacks, t_vector *ops);

void		optimize_instructions(t_vector *ops);
void		print_all_operations(const t_vector *operations);

//SOLVER_H
#endif
