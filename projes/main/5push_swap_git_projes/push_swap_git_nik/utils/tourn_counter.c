/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tourn_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:39:21 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/29 22:01:52 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		turns_for_b_rotation(int *stack_b, int nbr_from_b)
{
	int i;

	i = 1;
	while (stack_b[i] != nbr_from_b)
		i++;
	return (i <= B_LEN / 2) ? i : B_LEN - i;
}

int		turns_for_a_rotation(int *stack_a, int nbr)
{
	int i;

	i = A_LEN;
	if (nbr > A_BOTTOM && nbr < A_TOP)
		return (0);
	while (i > 1)
	{
		if (nbr > stack_a[i] && nbr < stack_a[i - 1])
			return (i > A_LEN / 2) ? (A_LEN - (i - 1)) : i - 1;
		i--;
	}
	return (9000);
}

int		turn_counter(int *stack_a, int *stack_b)
{
	int i;
	int	*turns;
	int a;
	int b;

	if (B_LEN < 2)
		return (B_LEN);
	turns = init_b(B_LEN + 1);
	turns[0] = B_LEN;
	i = 1;
	while (i <= B_LEN)
	{
		a = turns_for_a_rotation(stack_a, stack_b[i]);
		b = turns_for_b_rotation(stack_b, stack_b[i]);
		turns[i] = a + b;
		i++;
	}
	i = find_min(turns, 1);
	free(turns);
	return (i);
}

int		get_index_of_best_nbr_to_push(int *stack_a, int *stack_b)
{
	int index;

	index = turn_counter(stack_a, stack_b);
	return (index);
}
