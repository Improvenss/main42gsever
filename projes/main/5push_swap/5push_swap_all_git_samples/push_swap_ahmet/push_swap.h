/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:39:54 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/25 17:26:53 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

///--->| push_swap.c |---///
int		main(int argc, char **argv);
void	ft_push_swap(t_list **list_a, t_list **list_b);
void	ft_big_numbers(t_list **list_a, t_list **list_b);
void	ft_pushing_a(t_list **list_a, t_list **list_b);
void	ft_pushing_b(t_list **list_a, t_list **list_b);

///--->| push_swap.c |---///
int		ft_one_line_argc(int argc, char **argv);
char	**ft_one_line_arguments(int argc, char **argv);
char	**ft_split(const char *s, char c);

///--->| ft_push_a.c |---///
void	ft_push_a(t_list **list_a, t_list **list_b);
int		ft_push_a_limit_vol_1(t_list **list_a, t_list **list_b, int max, int i);
int		ft_push_a_limit_vol_2(t_list **list_a, t_list **list_b, int max, int i);
void	ft_three_reverse(t_list **list_b);

///--->| ft_push_b.c |---///
void	ft_push_b(t_list **list_a, t_list **list_b, int pivot, int pivot_alt);
void	ft_push_b_fonk(t_list **list_a, t_list **list_b, \
		int pivot, int pivot_alt);
void	ft_three(t_list **list_a);
void	ft_ten(t_list **list_a, t_list **list_b);

///--->| ft_push_b_extra.c |---///
void	ft_push_b_v2(t_list **list_a, t_list **list_b, \
int pivot, int pivot_alt);
int		ft_push_a_half_v2(t_list **list_a, t_list **list_b, int pivot);
int		ft_push_a_half_v1(t_list **list_a, t_list **list_b, int f);
int		ft_push_b_half(t_list **list_a, t_list **list_b, \
int pivot, int pivot_alt);
void	ft_push_b_extra(t_list **list_a, t_list **list_b, \
int first_sup, int second_sup);

///--->| ft_push_b_extra_2.c |---///
int		ft_push_a_half_fonk(t_list **list_a, t_list **list_b, \
int x, int pivot_up_up);
int		ft_push_a_half_v2_p2(t_list **list_a, t_list **list_b, \
int pivot_up, int pivot_up_up);
int		ft_push_a_half_v1_p2(t_list **list_a, t_list **list_b, \
int f, int pivot_up);

///--->| ft_ten.c |---///
int		ft_ten_set_a(t_list **list_a, t_list **list_b, int x);
int		ft_ten_set_b(t_list **list_a, t_list **list_b, int x);
void	ft_ten_push_half(t_list **list_a, t_list **list_b);

///--->| ft_argument.c |---///
void	ft_string_check(int argc, char **argv);
char	*ft_strjoin(char *save, char *buffer);
int		ft_rule_check(char *tmp);
t_list	*ft_argv_to_list(t_list *list_a, char *value);
int		ft_atoi_with_error(const char *str);

///--->| ft_utils.c |---///
void	sa(t_list **list_a);
void	sb(t_list **list_b);

void	pa(t_list **list_a, t_list **list_b);
void	pb(t_list **list_a, t_list **list_b);
///--->| ft_utils_2.c |---///
void	ra(t_list **list_a);
void	rb(t_list **list_b);

void	rra(t_list **list_a);
void	rrb(t_list **list_b);
void	rrr(t_list **list_a, t_list **list_b);

///--->| ft_utils_3.c |---///
int		ft_lstsize(t_list *lst);
int		ft_lstmax(t_list *list_a);
int		ft_lstmin(t_list *list_a);
int		ft_place(t_list **list_a, int data);
int		ft_max_before(t_list *list_b, int max);

///--->| ft_utils_4.c |---///
int		ft_to_min_find_max(t_list **list_a, int min);
int		ft_onay_size(t_list *list_a, int min, int max);
int		ft_onay(t_list *list_a, int data, int min, int max);
int		ft_pivot_ara(t_list *list_a, int min, int max);
void	ft_rrr_rra_rrb(t_list **list_a, t_list **list_b, int x, int y);

///--->| ft_utils_5.c |---///
size_t	ft_strlen(const char *s);
void	ft_exit(int error);
int		ft_place_check(t_list *list_a);
void	ft_free(t_list **list_a);

#endif
