/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:23:12 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:55:36 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	assigned_operations(char *operation[11])
{
	operation[0] = ft_strdup("sa");
	operation[1] = ft_strdup("sb");
	operation[2] = ft_strdup("ss");
	operation[3] = ft_strdup("pa");
	operation[4] = ft_strdup("pb");
	operation[5] = ft_strdup("ra");
	operation[6] = ft_strdup("rb");
	operation[7] = ft_strdup("rr");
	operation[8] = ft_strdup("rra");
	operation[9] = ft_strdup("rrb");
	operation[10] = ft_strdup("rrr");
}

static int	inverse_operation(int idx)
{
	int	inverse[11];

	inverse[0] = 0;
	inverse[1] = 1;
	inverse[2] = 2;
	inverse[3] = 4;
	inverse[4] = 3;
	inverse[5] = 8;
	inverse[6] = 9;
	inverse[7] = 10;
	inverse[8] = 5;
	inverse[9] = 6;
	inverse[10] = 7;
	return (inverse[idx]);
}

static int	recursive(t_deque *stack[2],
t_deque *instructions, char *operation[11], int avoid)
{
	int	ct;

	if (check_order(stack))
		return (1);
	if (stack[0]->size + stack[1]->size == 3 && instructions->size >= 3)
		return (0);
	if (stack[0]->size + stack[1]->size == 4 && instructions->size >= 5)
		return (0);
	if (stack[0]->size + stack[1]->size == 5 && instructions->size >= 7)
		return (0);
	ct = -1;
	while (++ct < 11)
	{
		if (ct == avoid || (ct == 3 && stack[1]->size == 0)
			|| (ct == 4 && stack[0]->size == 0))
			continue ;
		generate_instructions(stack, operation[ct], instructions);
		if (recursive(stack, instructions, operation, inverse_operation(ct)))
			return (1);
		deque_pop_back(instructions, NULL);
		assigned_operation(operation[inverse_operation(ct)], stack);
	}
	return (0);
}

static int	exception(t_deque *stack[2], t_deque *instructions)
{
	t_double_list	*temp;

	if (stack[0]->size != 5)
		return (0);
	temp = stack[0]->head;
	if (*((int *)temp->content) != 4)
		return (0);
	temp = temp->next;
	if (*((int *)temp->content) != 0)
		return (0);
	temp = temp->next;
	if (*((int *)temp->content) != 1)
		return (0);
	temp = temp->next;
	if (*((int *)temp->content) != 2)
		return (0);
	generate_instructions(stack, "sa", instructions);
	generate_instructions(stack, "pb", instructions);
	generate_instructions(stack, "rra", instructions);
	generate_instructions(stack, "sa", instructions);
	generate_instructions(stack, "pa", instructions);
	generate_instructions(stack, "rra", instructions);
	generate_instructions(stack, "rra", instructions);
	generate_instructions(stack, "sa", instructions);
	return (1);
}

void	easy_solve(t_deque *stack[2], t_deque *instructions)
{
	char	*operation[11];

	assigned_operations(operation);
	if (exception(stack, instructions))
		return ;
	if (recursive(stack, instructions, operation, -1) == 0)
	{
		ft_putendl_fd("Unexpected error !!", 2);
		error_exit();
	}
}
