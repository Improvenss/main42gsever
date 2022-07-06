/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:02:31 by gsever            #+#    #+#             */
/*   Updated: 2022/07/06 05:07:11 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file push_swap.h
 * @brief Libraries for 'push_swap' project.
 * @author Görkem SEVER (gsever)
 * @bug Sorting algorithms in process. Im stayed push_smalest(), i will be 
 * continue here. In sort_small.c file.
 */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//	STANDARD LIBRARY INCLUDES
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <errno.h>
# include <limits.h>
# include <sys/types.h>

# include <stdio.h>

//	MY OWN 42 LIBRARIES
# include "../libraries/libft/includes/libft.h"

//	ERROR CODES
# define NO_ARGS -1
# define INVALID_INPUT -2
# define STACK_EMPTY -3
# define STACK_ITEM_DOES_NOT_EXIST -4

/* ************************************************************************** */
/* STRUCT DEFINES AREA													  	  */
/* ************************************************************************** */

/**
 * @brief This struct for 'stack'.
 * size	: Holding stack's number count.
 * max	: Holding stack's BIGGEST number.
 * min	: Holding stack's SMALLEST number.
 * @bug No know bugs.
 */
typedef struct s_start
{
	int		size;
	int		max;
	int		min;
}			t_start;

/**
 * @brief Using this struct for sorting() algorithms.
 * score	:
 * rrb		:
 * rra		:
 * rrr		:
 * ra		:
 * rb		:
 * rr		:
 * @bug No know bugs.
 */
typedef struct score
{
	int		score;
	int		rrb;
	int		rra;
	int		rrr;
	int		ra;
	int		rb;
	int		rr;
}			t_score;

/**
 * @brief
 * start	: For the stack's numbers count.
 * current	: For sort() algorithms.
 * best		: For sort() algorithms.
 * max		: 
 * mid		: 
 * c_a		: Keeping 'a' stack's numbers count.
 * c_b		: Keeping 'b' stack's numbers count.
 * c_c		: Keeping 'c' stack's numbers count.
 * *a		: This is stack 'a'.
 * *b		: This is stack 'b'.
 * *c		: This is stack 'c', for helping.
 * @bug No know bugs.
 */
typedef struct s_base
{
	t_start	start;
	t_score	current;
	t_score	best;
	int		max;
	int		mid;
	int		c_a;
	int		c_b;
	int		c_c;
	int		*a;
	int		*b;
	int		*c;
}			t_base;

/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

//args.c
void	stack_fill(int ac, char **av, t_base *base);
void	stack_fill_double_quotation(char **av, t_base *base);
void	arg_checker(int argc, char **argv, t_base *base);

//check_error.c
void	is_sorted(t_base *base);
void	is_repeated(t_base *base);
int		ft_error(char *str);
void	check_num(int ac, char **av);
void	check_num_double_quotation(char *av, t_base *base);

//find.c
int		find_min(int size, t_base *base);
int		find_max(int size, t_base *base);

//free.c
void	ft_free(t_base *base);

//mark.c
void	remark(int size, t_base *base);
void	markup_norme(int *i, int *index, int *tmp, t_base *base);
void	markup(int size, int index, int prev, t_base *base);
void	indexer(int size, t_base *base);

//operations_push.c --> OK
void	pa(t_base *base);
void	pb(t_base *base);

//operations_r_reverse.c --> OK
void	rra(bool both, t_base *base);
void	rrb(bool both, t_base *base);
void	rrr(t_base *base);

//operations_rotate.c --> OK
void	ra(bool both, t_base *base);
void	rb(bool both, t_base *base);
void	rr(t_base *base);

//operations_swap.c --> OK
void	sa(bool both, t_base *base);
void	sb(bool both, t_base *base);
void	ss(t_base *base);

//sort_small.c
void	sort_small(t_base *base);

//sorting.c
void	sort(t_base *base);

//utils.c
size_t	calc_number_count_in_string(const char *str, char c);

#endif
