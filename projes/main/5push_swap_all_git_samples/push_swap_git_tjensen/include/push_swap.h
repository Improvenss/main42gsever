/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:15:44 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/14 17:09:06 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/* STD LIBC INCLUDES														  */
/* ************************************************************************** */
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <errno.h>
# include <sys/types.h>

/* ************************************************************************** */
/* USER INCLUDES															  */
/* ************************************************************************** */
# include "libft.h"

/* ************************************************************************** */
/* DEFINES: ERROR CODES														  */
/* ************************************************************************** */
# define NO_ARGS -1
# define INVALID_INPUT -2
# define STACK_EMPTY -3
# define STACK_ITEM_DOES_NOT_EXIST -4

/* ************************************************************************** */
/* DEFINES: ROTATION CASES													  */
/* ************************************************************************** */
# define RA_RB 1
# define RRA_RRB 2
# define RA_RRB 3
# define RRA_RB 4

/* ************************************************************************** */
/* STRUCT DEFS															  	  */
/* ************************************************************************** */

/*
**	array:		Stores the input array (for example &argv[1])
**	int_array:	Stores the input converted in integers
**	size:		Amount of input numbers
**	is_split:	Bool if the array is malloced by ft_split
*/
typedef struct s_input
{
	char	**array;
	int		*int_array;
	int		size;
	bool	is_split;
}	t_input;

/*
**	num:		"normalized" number from the input
**	is_snake:	defines if the element is part of a presorted list (snake)
**	next: 		Pointer to the next node in the stack
**	prev: 		Pointer to the previous node in the stack
*/
typedef struct s_stack
{
	int				num;
	bool			is_snake;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*
**	start: Pointer where to start searching a presorted list (snake)
**	max_start: Pointer to the start of a presorted list (snake), with max_len
**	range: How much bigger an element could be, to be part of a snake.
**	max_range: Stores the range, where we find the longest snake
**	len: Stores the len of a current snake, while searching for the longest
**	max_len: Stores the length of the longest snake.
*/
typedef struct s_snake
{
	t_stack	*start;
	t_stack	*max_start;
	int		range;
	int		max_range;
	int		len;
	int		max_len;
}	t_snake;

/*
**	range: next element for next push has to be smaller than smallest + range
**	max_range: Stores the range where we count the less operations.
**	ra_rra_count: Values for rotations on stack_a
**	rb_rrb_count: Values for rotations on stack_b
**	rr_rrr_count: Values for rotations on both stacks at the same time
**	rotation_sum: Sum of all rotations
*/
typedef struct s_sort
{
	int		range;
	int		max_range;
	int		ra_rra_count[2];
	int		rb_rrb_count[2];
	int		rr_rrr_count[2];
	int		rotation_sum;
}	t_sort;

/*
**	input: 		Struct pointer for the input_struct
**	stack_mem:	Pointer to the mem for all stack items, to free at the end
**	a_top:		Pointer to the top element of stack_A
**	b_top:		Pointer to the top element of stack_B
**	a_size:		Number of elements in stack_A
**	b_size:		Number of elements in stack_B
**	size: 		Sum of all numbers to be sorted (a_size + b_size)
*/
typedef struct s_push_swap
{
	t_input	*input;
	t_stack	*stack_mem;
	t_stack	*a_top;
	t_stack	*b_top;
	int		a_size;
	int		b_size;
	int		size;
}	t_ps;

/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

// INPUT
void	input_check(t_input *input, int argc, char *argv[], bool check_sort);

// INPUT UTILS
t_input	*input_struct_get(void);
void	input_struct_destroy(t_input **input);
int		array_count_smaller(int *array, int size, int num);
void	input_exit(t_input *input, int status);

// PUSH_SWAP UTILS
void	push_swap_struct_cpy(t_ps *dest, t_ps *src);
void	push_swap_struct_init(t_ps *push_swap);
void	ft_atexit(t_ps *push_swap, int status);

// OPERATIONS
int		operation_sa(t_ps *push_swap, bool print);
int		operation_sb(t_ps *push_swap, bool print);
int		operation_ss(t_ps *push_swap, bool print);
int		operation_pa(t_ps *push_swap, bool print);
int		operation_pb(t_ps *push_swap, bool print);
int		operation_ra(t_ps *push_swap, bool print);
int		operation_rb(t_ps *push_swap, bool print);
int		operation_rr(t_ps *push_swap, bool print);
int		operation_rra(t_ps *push_swap, bool print);
int		operation_rrb(t_ps *push_swap, bool print);
int		operation_rrr(t_ps *push_swap, bool print);

// STACK UTILS
t_stack	*stack_get_a(t_input *input);
t_stack	*stack_get_mem(t_ps *ps);
void	stacks_print(t_ps *push_swap);
void	stack_item_init(t_stack *stack, int size, int position, int count);

// STACK IS
bool	stack_is_num_inside(t_stack *stack, int num);
bool	stack_is_biggest(t_stack *stack, int num);
bool	stack_is_smallest(t_stack *stack, int num);

// STACK GET
int		stack_get_biggest(t_stack *stack);
int		stack_get_smallest(t_stack *stack);
int		stack_get_next_bigger(t_stack *stack, int num);
int		stack_get_next_smaller(t_stack *stack, int num);

// STACK ROTATION
void	stack_rot_case_set(t_sort *sort, int rotation_case);
int		stack_rot_case_choose(t_sort *sort);

int		stack_rot_count_find_best_num_b(t_ps *ps, t_sort *sort);
void	stack_rot_count_from(t_stack *stack, int *r_rr_count, int num);
void	stack_rot_count_to_asc(t_stack *stack, int *r_rr_count, int num);

void	stack_rot_set_b_to_a(t_ps *ps, t_sort *sort, int num);
void	stack_rot_set_end(t_ps *ps, t_sort *sort, int num);

// STACK SNAKE
void	stack_snake_set(t_ps *ps, t_snake *snake);

// STACK SORT EXECUTE
int		stack_sort_execute_rotation(t_ps *ps, t_sort *sort, bool print);
int		stack_sort_execute_snake(t_ps *ps, bool print);

// STACK SORT
void	stack_sort_small(t_ps *push_swap);
void	stack_sort_big(t_ps *push_swap);

#endif
