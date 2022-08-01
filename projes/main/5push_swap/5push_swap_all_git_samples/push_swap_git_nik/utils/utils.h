/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:14:43 by vinograd          #+#    #+#             */
/*   Updated: 2019/09/04 20:41:14 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	how indexes in stack works!
**	arr		 0	1 2 3 4 5 6 ... 10
**	stack	len|1 2 3 4 5 6 ... 10 <-top
**	expmpl	  7|1 2 3 4 5 6 9 (1 is the bottob of the stack, 9 is the top)
*/

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# define COMMANDS "sa sb ss pa pb ra rb rr rra rrb rrr"
# define LEN stack[0]
# define A_LEN stack_a[0]
# define B_LEN stack_b[0]
# define A_TOP stack_a[A_LEN]
# define A_SEC	stack_a[A_LEN - 1]
# define A_BOTTOM stack_a[1]
# define B_TOP stack_b[B_LEN]
# define B_BOTTOM stack_b[1]

typedef struct
{
	int	e;
	int	g;
	int	v;
	int	c;
}		t_push;
/*
**	swap two first elements
*/
void	sa(int *stack_a);
void	sb(int *stack_b);
void	ss(int *stack_a, int *stack_b);
/*
**	put elem pa(to, from)
*/
void	pa(int *stack_a, int *stack_b);
void	pb(int *stack_a, int *stack_b);
/*
**	The first element becomes the last one
*/
void	ra(int *stack_a);
void	rb(int *stack_b);
void	rr(int *stack_a, int *stack_b);
/*
**	The last element becomes the first one
*/
void	rra(int *stack_a);
void	rrb(int *stack_b);
void	rrr(int *stack_a, int *stack_b);

int		*init_a(int len, char **arr, int err_flag);
void	duplicates_check(int *stack, int err_flag);
char	*input_checker(char *s, int err_flag);
int		*init_b(int len);

void	print_stack(int *stack_a, int *stack_b, int steps);
int		*copy_stack(int *stack, int size);
int		is_sorted(int *stack_a, int *stack_b);

int		commander(char *cmd, int *stack_a, int *stack_b);
int		is_command(char *cmd);
void	ft_error(char *message);
int		flag_analizer(char **argv, t_push *flags);
/*
**	PUSH_SWAP
*/
void	stack_sort(int *stack_a, int *stack_b);
void	fill_stack_b(int *stack_a, int *stack_b);
int		get_index_of_best_nbr_to_push(int *stack_a, int *stack_b);
int		is_in_right_order(int *stack_a);
int		is_a_sorted(int *stack_a);
int		find_min(int *stack, int index);
int		find_max(int *stack, int index);
void	totle_commander(char *cmd, int *stack_a, int *stack_b);
int		does_sa_work(int *stack_a, int *stack_b);
void	rotation(int *stack_a, int *stack_b, int index);

#endif
