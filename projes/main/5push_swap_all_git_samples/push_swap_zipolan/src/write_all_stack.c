/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_all_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:20:32 by gsever            #+#    #+#             */
/*   Updated: 2022/07/27 12:19:57 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

//printed stack's all numbers for testing.
void	write_all_stack(t_base *base)
{
	int	i;

	i = 0;
	printf("\nstack a --> ");
	while (i < base->c_a)
	{
		printf("%d ", base->a[i]);
		i++;
	}
	i = 0;
	printf("\nstack b --> ");
	while (i < base->c_b)
	{
		printf("%d ", base->b[i]);
		i++;
	}
	printf("\n");
}
