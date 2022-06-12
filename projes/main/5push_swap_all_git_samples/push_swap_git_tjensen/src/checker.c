/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:56:32 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/19 10:10:27 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checker_execute(t_ps *ps, char *operation);
static bool	checker_is_sorted(t_ps *ps);

/*
**	After checking the users *argv[] input, the checker waits for commands
**	from the std_input. Every instruction will be executed on the stack.
**
**	Possible Outputs:
**	Error: 	 invalid input or invalid operation
**	KO:		 Stack is not sorted after executing the instructions
**	OK:		 Stack is sorted in correct order after executing the instructions
**	Nothing: Missing *argv[] arguments for the stack
*/

int	main(int argc, char *argv[])
{
	t_ps	push_swap;
	char	*command;

	push_swap.input = input_struct_get();
	input_check(push_swap.input, argc, argv, false);
	push_swap_struct_init(&push_swap);
	input_struct_destroy(&(push_swap.input));
	command = get_next_line(STDIN_FILENO);
	while (checker_execute(&push_swap, command) == 0)
	{
		ft_free((void **)&command);
		command = get_next_line(STDIN_FILENO);
	}
	if (command != NULL)
	{
		ft_free((void **)&command);
		ft_atexit(&push_swap, INVALID_INPUT);
	}
	if (checker_is_sorted(&push_swap))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_atexit(&push_swap, EXIT_SUCCESS);
}

/* Executes all instrcutions the checker reads from the std_in */
static int	checker_execute(t_ps *ps, char *operation)
{
	if (operation && !ft_strncmp(operation, "ra\n", 3))
		operation_ra(ps, false);
	else if (operation && !ft_strncmp(operation, "rb\n", 3))
		operation_rb(ps, false);
	else if (operation && !ft_strncmp(operation, "rr\n", 3))
		operation_rr(ps, false);
	else if (operation && !ft_strncmp(operation, "rra\n", 4))
		operation_rra(ps, false);
	else if (operation && !ft_strncmp(operation, "rrb\n", 4))
		operation_rrb(ps, false);
	else if (operation && !ft_strncmp(operation, "rrr\n", 4))
		operation_rrr(ps, false);
	else if (operation && !ft_strncmp(operation, "pa\n", 3))
		operation_pa(ps, false);
	else if (operation && !ft_strncmp(operation, "pb\n", 3))
		operation_pb(ps, false);
	else if (operation && !ft_strncmp(operation, "sa\n", 3))
		operation_sa(ps, false);
	else if (operation && !ft_strncmp(operation, "sb\n", 3))
		operation_sb(ps, false);
	else if (operation && !ft_strncmp(operation, "ss\n", 3))
		operation_ss(ps, false);
	else
		return (INVALID_INPUT);
	return (EXIT_SUCCESS);
}

/* Checks if the stack is well sorted from top to bootom in ascending order */
static bool	checker_is_sorted(t_ps *ps)
{
	int		i;
	t_stack	*tmp;

	if (ps->b_top != NULL || ps->b_size != 0)
		return (false);
	tmp = ps->a_top;
	i = 0;
	while (i < (ps->size - 1))
	{
		if ((tmp->num + 1) != tmp->next->num)
			return (false);
		tmp = tmp->next;
		i++;
	}
	return (true);
}
