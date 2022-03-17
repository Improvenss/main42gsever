/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:56:40 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:56:41 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "stack.h"
#include "utils.h"
#include "libft.h"

int	is_valid_arg(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return (false);
	while (s[i])
	{
		if (!(s[i] == '-' || s[i] == '+' || (s[i] >= '0' && s[i] <= '9')))
			return (false);
		++i;
	}
	return (true);
}

void	parse_array(t_collection *stacks, char **argv, int i)
{
	int				item;
	bool			error;
	unsigned int	digits_amount;

	error = false;
	while (argv[i])
	{
		if (!is_valid_arg(argv[i]))
			fatal_error(stacks, "Error");
		item = atoi_exit_on_error(argv[i], &error);
		if (error)
			fatal_error(stacks, "Error");
		digits_amount = amount_digits(item);
		if (stack_duplicate_check(stacks->a, item))
			fatal_error(stacks, "Error");
		if (digits_amount > stacks->max_amount_digits)
			stacks->max_amount_digits = digits_amount;
		stack_push_under(stacks->a, ft_atoi(argv[i]));
		++i;
	}
}

void	parse_split_array(t_collection *stacks, char *s)
{
	char	**array;
	int		i;

	array = ft_split(s, ' ');
	if (array == NULL || array[0] == NULL)
		fatal_error(stacks, "Error");
	parse_array(stacks, array, 0);
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		++i;
	}
	free(array);
	array = NULL;
}
