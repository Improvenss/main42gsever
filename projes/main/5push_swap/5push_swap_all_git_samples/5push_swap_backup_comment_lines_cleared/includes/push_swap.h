/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:02:31 by gsever            #+#    #+#             */
/*   Updated: 2022/07/21 05:01:51 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file push_swap.h
 * @brief Libraries for 'push_swap' project.
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
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

//	COLORS --> 🟥 🟩 🟦
# define LB		"\033[0;36m"
# define BLUE	"\033[0;34m"
# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define RED	"\033[0;31m"
# define RESET	"\033[0m"
# define X		"\033[m"

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
 * @brief Using this struct for sorting algorithms.
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

//algorithms_push_b.c --> OK
void	keep_me(t_base *base);
int		ps_finder(int c, t_base *base);
void	push_to_norme(t_base *base);
void	push_to_b(t_base *base);

//args.c --> OK
void	stack_fill(int ac, char **av, t_base *base);
void	stack_fill_double_quotation(char **av, t_base *base);
void	arg_checker(int argc, char **argv, t_base *base);

//check_error.c --> OK
void	is_sorted(t_base *base);
void	is_repeated(t_base *base);
int		ft_error(char *str);
void	check_num(int ac, char **av);
void	check_num_double_quotation(char *av, t_base *base);

//compute.c
void	copy_the_best(t_base *base);
void	merge_rr(t_base *base);
void	count_ra(int b, t_base *base);
void	compute(int max, t_base *base);

//find.c --> OK
int		find_min(int size, t_base *base);
int		find_max(int size, t_base *base);

//free.c --> OK
void	ft_free(t_base *base);

//main.c
void	push_swap(t_base *stack, int argc, char **argv);

//mark.c --> OK
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

//perform.c
void	perform_norme(t_base *base);
void	perform(t_base *base);

//score_init.c --> OK
void	score_init(t_base *base);
void	score_init_max(t_base *base);

//sort_small.c --> OK
void	sort_small(t_base *base);

//sorting.c --> OK
void	sort(t_base *base);

//utils.c --> OK
size_t	calc_number_count_in_string(const char *str, char c);

//write_all_stack.c --> OK
void	write_all_stack(t_base *base);

#endif
