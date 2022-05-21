/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:10:52 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/31 14:35:04 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"

int		main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	t_push	flags;
	int		i;

	if (argc < 2)
		ft_error("usage: push_swap -e 5 4 3 2 ...\n-e  error hendling");
	i = flag_analizer(argv, &flags);
	argv += i;
	stack_a = init_a(argc - i, argv, flags.e);
	stack_b = init_b(A_LEN + 1);
	fill_stack_b(stack_a, stack_b);
	stack_sort(stack_a, stack_b);
}
