/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:08:53 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/31 14:34:33 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The first argument should be at the top of the stack
*/

#include "checker.h"

int		main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	int		steps;
	t_push	flags;
	int		i;

	if (argc < 2)
		usage();
	i = flag_analizer(argv, &flags);
	if (!*(argv += i))
		usage();
	stack_a = init_a(argc - i, argv, flags.e);
	stack_b = init_b(A_LEN + 1);
	if (flags.g)
		print_man();
	if (flags.v)
		print_stack(stack_a, stack_b, 0);
	steps = get_command(stack_a, stack_b, flags);
	ft_printf("%s\n", is_sorted(stack_a, stack_b) ?\
	"{green}OK{eoc}" : "{red}KO{eoc}");
	ft_printf("steps: %d\n", steps);
	free(stack_a);
	free(stack_b);
}

int		get_command(int *stack_a, int *stack_b, t_push flags)
{
	char	*cmd;
	int		steps;

	steps = 0;
	while (!is_sorted(stack_a, stack_b) && get_next_line(0, &cmd))
	{
		if (!ft_strcmp(cmd, "end"))
			break ;
		if (!ft_strcmp(cmd, "man") && flags.g)
		{
			print_man();
			continue ;
		}
		if (!ft_strcmp(cmd, "help") && flags.g)
		{
			push_help(stack_a, stack_b);
			continue ;
		}
		steps += multi_commander(cmd, stack_a, stack_b);
		if (flags.v)
			print_stack(stack_a, stack_b, steps);
		free(cmd);
	}
	return (steps);
}
