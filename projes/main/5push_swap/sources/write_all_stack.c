/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_all_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:20:32 by gsever            #+#    #+#             */
/*   Updated: 2022/07/26 20:10:45 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//printed stack's all numbers for testing.
void	write_all_stack(t_base *base)
{
	int	i;

	i = 0;
	printf("\n"GREEN"stack a --> "X);
	while (i < base->c_a)
	{
		printf(GREEN"%d "X, base->a[i]);
		i++;
	}
	i = 0;
	printf("\n"GREEN"stack b --> "X);
	while (i < base->c_b)
	{
		printf(GREEN"%d "X, base->b[i]);
		i++;
	}
	printf("\n");
}
