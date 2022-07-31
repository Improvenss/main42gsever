/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:25:30 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/27 15:29:52 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		ft_string_check(argc, argv);
		while (argc--)
			list_a = ft_argv_to_list(list_a, argv[argc]);
		ft_checker(&list_a, &list_b);
		ft_free(&list_a);
	}
	ft_exit(0);
}
