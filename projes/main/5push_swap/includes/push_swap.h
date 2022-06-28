/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:02:31 by gsever            #+#    #+#             */
/*   Updated: 2022/06/28 17:21:13 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file push_swap.h
 * @brief 
 * 
 * @author Görkem SEVER (gsever)
 * @bug 
 */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//	STANDARD LIBRARY INCLUDES
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
//# include <stdbool.h>
# include <errno.h>
# include <limits.h>
# include <sys/types.h>

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
 * @brief A stack's start, max, min values.
 * size	: Size of args bytes.
 * max	:
 * min	:
 * @bug No know bugs.
 */
typedef struct s_start
{
	int		size;
	int		max;
	int		min;
}			t_start;

/**
 * @brief
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
 * start	:
 * current	:
 * best		:
 * max		:
 * mid		:
 * c_a		:
 * c_b		:
 * c_c		:
 * *a		:
 * *b		:
 * *c		:
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

// args.c
void	stack_fill(int ac, char **av, t_base *base);
void	stack_fill_double_quotation(char **av, t_base *base);
void	arg_checker(int argc, char **argv, t_base *base);
void	kill_prog(char *str, t_base *base);
//int		ft_atoi(const char *str, t_base *base);

// check_error.c
void	is_sorted(t_base *base);
void	is_repeated(t_base *base);
int		ft_error(char *str);
void	check_num(int ac, char **av);
void	check_num_double_quotation(char *av, t_base *base);

// compute.c
void	count_ra(int b, t_base *base);
void	merge_rr(t_base *base);
void	copy_to_best(t_base *base);
void	score_init_max(t_base *base);
void	compute(int max, t_base *base);

// ft_split.c
char	**ft_split(const char *s, char c);

// mark.c
int		find_min(int size, t_base *base);
int		find_max(int size, t_base *base);
void	indexer(int size, t_base *base);
void	markup(int size, int index, int prev, t_base *base);
void	remark(int size, t_base *base);

// oerform.c
void	perform(t_base *base);

// ps.c
void	pa(t_base *base);
void	pb(t_base *base);
void	sa(t_base *base);
void	sb(t_base *base);
void	ss(t_base *base);

// push_to_b.c
void	keep_me(t_base *base);
int		ps_finder(int c, t_base *base);
void	push_to_norme(t_base *base);
void	push_to_b(t_base *base);

// r.c
void	ra(int bool, t_base *base);
void	rb(int bool, t_base *base);
void	rr(t_base *base);

// rr.c
void	rra(int bool, t_base *base);
void	rrb(int bool, t_base *base);
void	rrr(t_base *base);

// sort_big.c
void	final_sort(t_base *base);
void	small_sort(t_base *base);
void	ft_free(t_base *base);
void	sort(t_base *base);

// sort_small.c
void	push_smallest(int a, t_base *base);
void	sort_blood(t_base *base);
void	six_sort(t_base *base);

size_t	arguman_length(const char *str, char c);
int		is_digit(int c);
/*
// utils.c
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// utils2.c
void	score_init(t_base *base);
void	markup_norme(int *i, int *index, int *tmp, t_base *base);
*/
#endif
