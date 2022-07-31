/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_argument_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:30:45 by akaraca           #+#    #+#             */
/*   Updated: 2022/07/25 15:27:45 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checker_rules(t_list **list_a, t_list **list_b, char *line)
{
	if (ft_strncmp(line, "sa", 2))
		sa(list_a);
	else if (ft_strncmp(line, "sb", 2))
		sb(list_b);
	else if (ft_strncmp(line, "ss", 2))
		ss(list_a, list_b);
	else if (ft_strncmp(line, "ra", 2))
		ra(list_a);
	else if (ft_strncmp(line, "rb", 2))
		rb(list_b);
	else if (ft_strncmp(line, "rr", 2))
		rr(list_a, list_b);
	else if (ft_strncmp(line, "rra", 3))
		rra(list_a);
	else if (ft_strncmp(line, "rrb", 3))
		rrb(list_b);
	else if (ft_strncmp(line, "rrr", 3))
		rrr(list_a, list_b);
	else if (ft_strncmp(line, "pa", 2))
		pa(list_a, list_b);
	else if (ft_strncmp(line, "pb", 2))
		pb(list_a, list_b);
	else
		ft_exit(1);
}

#include <stdio.h>
void	ft_checker(t_list **list_a, t_list **list_b)
{
	int		i;
	char	*line;

	i = ft_lstsize(*list_a);
	line = get_next_line(0);
	while (line)
	{
		printf("line --> %s\n", line);
		ft_checker_rules(list_a, list_b, line);
		line = get_next_line(0);
	}
	if (ft_place_check(*list_a) && ft_lstsize(*list_a) \
			== i && ft_lstsize(*list_b) == 0)
		ft_exit(3);
	else
		ft_exit(2);
}
