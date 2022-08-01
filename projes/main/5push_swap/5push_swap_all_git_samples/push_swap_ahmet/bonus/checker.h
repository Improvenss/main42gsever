/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:32:51 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/27 16:35:53 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

///--->| ft_checker.c |---///
int		main(int argc, char **argv);

///--->| ft_get_next_line.c |---///
char	*get_next_line(int fd);

///--->| ft_checker_arguments.c |---///
void	ft_string_check(int argc, char **argv);
char	*ft_strjoin(char *save, char *buffer);
int		ft_rule_check(char *tmp);
t_list	*ft_argv_to_list(t_list *list_a, void *value);
int		ft_atoi_with_error(const char *str);

///--->| ft_checker_arguments_2.c |---///
void	ft_checker(t_list **list_a, t_list **list_b);
void	ft_checker_rules(t_list **list_a, t_list **list_b, char *line);

///--->| ft_checker_utils_5.c |---///
void	ft_free(t_list **list_a);

///--->| ft_checker_utils_4.c |---///
size_t	ft_strlen(const char *s);
void	ft_exit(int error);
int		ft_place_check(t_list *list_a);
int		ft_lstsize(t_list *lst);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

///--->| ft_checker_utils.c |---///
void	sa(t_list **list_a);
void	sb(t_list **list_b);
void	ss(t_list **list_a, t_list **list_b);

void	pa(t_list **list_a, t_list **list_b);
void	pb(t_list **list_a, t_list **list_b);

///--->| ft_checker_utils_2.c |---///
void	ra(t_list **list_a);
void	rb(t_list **list_b);
void	rr(t_list **list_a, t_list **list_b);

///--->| ft_checker_utils_3.c |---///
void	rra(t_list **list_a);
void	rrb(t_list **list_b);
void	rrr(t_list **list_a, t_list **list_b);

#endif
