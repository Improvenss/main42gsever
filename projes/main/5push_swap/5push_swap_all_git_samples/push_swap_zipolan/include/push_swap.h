/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:27:13 by bbourcy           #+#    #+#             */
/*   Updated: 2022/07/27 12:17:11 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_start
{
	int		size;
	int		max;
	int		min;
}			t_start;

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

// args.c
void	stack_fill(char **av, int ac, t_base *base);
void	stack_fill_q(char **av, t_base *base);
void	arg_checker(int argc, char **argv, t_base *base);
void	kill_prog(char *str, t_base *base);
int		ft_atoi(const char *str, t_base *base);

// check_error.c
void	is_sorted(t_base *base);
void	is_repeated(t_base *base);
int		ft_error(char *str);
void	check_num(char **av, int ac);
void	check_num_q(char *av, t_base *base);

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

// utils.c
size_t	ft_strlen(const char *s);
int		is_digit(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	length(char const *s, char c);

// utils2.c
void	score_init(t_base *base);
void	markup_norme(int *i, int *index, int *tmp, t_base *base);

//write_all_stack.c --> OK
void	write_all_stack(t_base *base);

#endif