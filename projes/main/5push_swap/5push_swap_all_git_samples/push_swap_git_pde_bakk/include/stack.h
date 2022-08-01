/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:45:54 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:45:56 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include "opcode.h"

typedef struct s_stacknode
{
	int					data;
	unsigned int		sorted_pos;
	struct s_stacknode	*prev;
	struct s_stacknode	*next;
}t_stacknode;

typedef struct s_stack
{
	unsigned int	size;
	t_stacknode		*top;
	t_stacknode		*bottom;
	char			id;
}t_stack;

typedef struct s_collection
{
	unsigned int	max_amount_digits;
	t_stack			*a;
	t_stack			*b;
}t_collection;

t_collection	*create_stacks(void);
t_collection	*copy_stacks(const t_collection *stack);
void			delete_stack(t_stack *stack);

bool			stack_is_sorted(const t_stack *stack);
bool			sort_is_done(const t_collection *coll);

bool			stack_duplicate_check(const t_stack *stack, int item);
bool			stack_is_empty(const t_stack *stack);
void			stack_push(t_stack *stack, t_stacknode *item);
void			stack_push_under(t_stack *stack, int item);
t_stacknode		*stack_pop(t_stack *stack);
int				stack_peek(const t_stack *stack);
void			print_stacks(const t_collection *stacks);
void			print_stacks_binary(const t_collection *stacks);

//STACK_H
#endif
