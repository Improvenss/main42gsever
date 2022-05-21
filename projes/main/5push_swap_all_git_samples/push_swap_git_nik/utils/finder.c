/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 23:44:07 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/29 22:01:12 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		find_max(int *stack, int index)
{
	int i;
	int max;
	int max_index;

	max = stack[1];
	max_index = 1;
	i = 2;
	while (i <= LEN)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			max_index = i;
		}
		i++;
	}
	return (index) ? max_index : max;
}

int		find_min(int *stack, int index)
{
	int i;
	int min;
	int min_index;

	min = stack[1];
	min_index = 1;
	i = 2;
	while (i <= LEN)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			min_index = i;
		}
		i++;
	}
	return (index) ? min_index : min;
}
