/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:56:49 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:58:52 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "ft_printf.h"
#include "utils.h"

static void	printf_wrapper(const t_stacknode *node,
							int max_digits, const char *end)
{
	if (node)
		ft_dprintf(STDERR_FILENO, "%*d%s", max_digits, node->sorted_pos, end);
	else
		ft_dprintf(STDERR_FILENO, "%*c%s", max_digits, ' ', end);
}

static void	printf_wrapper_binary(const t_stacknode *node,
									int max_digits, const char *end)
{
	if (node)
	{
		while (max_digits >= 0)
		{
			ft_dprintf(STDERR_FILENO, "%d",
				(((int)node->sorted_pos >> max_digits) & 1));
			--max_digits;
		}
		ft_dprintf(STDERR_FILENO, "%s", end);
	}
	else
		ft_dprintf(STDERR_FILENO, "%*c%s", max_digits, ' ', end);
}

void	print_stacks(const t_collection *stacks)
{
	const int	field_width = (int)stacks->max_amount_digits + 2;
	t_stacknode	*tmp_a;
	t_stacknode	*tmp_b;

	tmp_a = stacks->a->top;
	tmp_b = stacks->b->top;
	ft_dprintf(STDERR_FILENO, "\n%*c|%*c\n\n", -field_width, 'A',
		field_width, 'B');
	while (tmp_a || tmp_b)
	{
		printf_wrapper(tmp_a, -field_width, "|");
		printf_wrapper(tmp_b, field_width, "\n");
		if (tmp_a)
			tmp_a = tmp_a->prev;
		if (tmp_b)
			tmp_b = tmp_b->prev;
	}
	ft_putchar_fd('\n', STDERR_FILENO);
}

void	print_stacks_binary(const t_collection *stacks)
{
	const int	field_width = \
	(int)get_max_bits(stacks->a->size + stacks->b->size - 1) - 1;
	t_stacknode	*tmp_a;
	t_stacknode	*tmp_b;

	tmp_a = stacks->a->top;
	tmp_b = stacks->b->top;
	ft_dprintf(STDERR_FILENO, "\n%*c|%*c\n\n", -field_width, 'A',
		field_width, 'B');
	while (tmp_a || tmp_b)
	{
		printf_wrapper_binary(tmp_a, field_width, "|");
		printf_wrapper_binary(tmp_b, field_width, "\n");
		if (tmp_a)
			tmp_a = tmp_a->prev;
		if (tmp_b)
			tmp_b = tmp_b->prev;
	}
	ft_putchar_fd('\n', STDERR_FILENO);
}
