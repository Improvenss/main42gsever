/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 03:04:37 by gsever            #+#    #+#             */
/*   Updated: 2022/07/25 15:50:54 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file checker.c
 * @brief Push_Swap checker here.
 * 
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
#include "../includes/push_swap.h"

static void	free_one_arr(void **to_free)
{
	free(*to_free);
	*to_free = NULL;
}

static bool	checker_is_sorted(t_base *base)
{
	int	i;

	i = 0;
	while (i + 1 < base->start.size)
	{
		if (base->a[i] < base->a[i + 1])
			i++;
		else
		{
			return (false);
		}
	}
	return (true);
}

static int	checker_execute(t_base *base, char *command)
{
	if (command && !ft_strncmp(command, "ra\n", 3))
		ra(1, base);
	else if (command && !ft_strncmp(command, "rb\n", 3))
		rb(1, base);
	else if (command && !ft_strncmp(command, "rr\n", 3))
		rr(base);
	else if (command && !ft_strncmp(command, "rra\n", 4))
		rra(1, base);
	else if (command && !ft_strncmp(command, "rrb\n", 4))
		rrb(1, base);
	else if (command && !ft_strncmp(command, "rrr\n", 4))
		rrr(base);
	else if (command && !ft_strncmp(command, "pa\n", 3))
		pa(base);
	else if (command && !ft_strncmp(command, "pb\n", 3))
		pb(base);
	else if (command && !ft_strncmp(command, "sa\n", 3))
		sa(1, base);
	else if (command && !ft_strncmp(command, "sb\n", 3))
		sb(1, base);
	else if (command && !ft_strncmp(command, "ss\n", 3))
		ss(base);
	else
		return (INVALID_INPUT);
	return (EXIT_SUCCESS);
}

static void	checker_fill_stack(t_base *stack, int argc, char **argv)
{
	arg_checker(argc, argv, stack);
	stack->a = malloc(sizeof(int) * stack->start.size);
	stack->b = malloc(sizeof(int) * stack->start.size);
	stack->c = malloc(sizeof(int) * stack->start.size);
	if (argc > 2)
		stack_fill(argc, argv, stack);
	else if (argc == 1)
	{
		ft_free(stack, true);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_free(stack, true);
		ft_error("Error\n");
	}
	indexer(stack->start.size, stack);
}

/**
 * @brief
 * After checking the users *argv[] input, the checker waits for commands
 * from the std_input. Every instruction will be executed on the stack.
 * 
 * Possible Outputs:
 * Error:	invalid input or invalid operation
 * KO:		Stack is not sorted after executing the instructions
 * OK:		Stack is sorted in correct order after executing the instructions
 * Nothing:	Missing *argv[] arguments for the stack

	STDIN_FILENO --> 0
 * @param 
 * @param 
 * @bug		segmentation fault in get_next_line()
 */
int	main(int argc, char **argv)
{
	//t_base	stack;
	t_base	stack_control;
	char	*command;

	command = NULL;
	checker_fill_stack(&stack_control, argc, argv);
	command = get_next_line(0);
	printf("command --> %s\n",command);
	while (checker_execute(&stack_control, command) == 0)
	{
		free_one_arr((void **)&command);
		command = get_next_line(STDIN_FILENO);
	}
	if (command != NULL)
	{
		free_one_arr((void **)&command);
		ft_error("Error\n");
	}
	if (checker_is_sorted(&stack_control))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	// ft_free(&stack);
	ft_free(&stack_control, true);
}
