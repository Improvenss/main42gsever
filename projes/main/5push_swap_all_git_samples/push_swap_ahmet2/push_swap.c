/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:45:05 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/24 14:53:34 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushing_b(t_list **list_a, t_list **list_b)
{
	int	first_sup;
	int	second_sup;

	first_sup = 0;
	second_sup = 0;
	if (ft_lstsize(*list_a) > 100)
		ft_push_b_extra(list_a, list_b, first_sup, second_sup);
	while (ft_lstsize(*list_a) > 3)
		ft_push_b(list_a, list_b, first_sup, second_sup);
	ft_three(list_a);
}

void	ft_pushing_a(t_list **list_a, t_list **list_b)
{
	int	size;

	size = 0;
	while (ft_lstsize(*list_b) > 3)
		ft_push_a(list_a, list_b);
	ft_three_reverse(list_b);
	size = ft_lstsize(*list_b);
	while (size-- > 0)
		pa(list_a, list_b);
}

void	ft_big_numbers(t_list **list_a, t_list **list_b)
{
	ft_pushing_b(list_a, list_b);
	ft_pushing_a(list_a, list_b);
}

void	ft_push_swap(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) < 4)
		ft_three(list_a);
	else if (ft_lstsize(*list_a) < 11)
		ft_ten(list_a, list_b);
	else if (ft_lstsize(*list_a) <= 500)
		ft_big_numbers(list_a, list_b);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc > 1)
	{
		argc = argc - 1;
		argv++;
		argv = ft_one_line_arguments(argc, argv);
		argc = ft_one_line_argc(argc, argv);
		ft_string_check(argc, argv);
		while (argc--)
			list_a = ft_argv_to_list(list_a, argv[argc]);
		if (ft_place_check(list_a))
			ft_exit(0);
		else
			ft_push_swap(&list_a, &list_b);
		ft_free(&list_a);
	}
	ft_exit(0);
}
