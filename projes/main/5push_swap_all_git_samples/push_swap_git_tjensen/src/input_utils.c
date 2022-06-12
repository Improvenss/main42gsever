/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:41:12 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/15 12:39:20 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns an input struct, with malloced memory and init some values */
t_input	*input_struct_get(void)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	if (input == NULL)
		input_exit(input, ENOMEM);
	input->array = NULL;
	input->int_array = NULL;
	input->size = 0;
	input->is_split = false;
	return (input);
}

/* Frees the input struct and all dependencies and set it to NULL */
void	input_struct_destroy(t_input **input)
{
	if (*input)
	{
		free((*input)->int_array);
		if ((*input)->is_split)
			ft_free_split((*input)->array);
	}
	free(*input);
	*input = NULL;
}

/* Counts all smaller elements in an array. to get a "normalized" value */
int	array_count_smaller(int *array, int size, int num)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < size)
	{
		if (num > array[i])
			count++;
		i++;
	}
	return (count);
}

/* Function to exit and free all dependencies while input process */
void	input_exit(t_input *input, int status)
{
	if (status == INVALID_INPUT)
		ft_putendl_fd("Error", STDERR_FILENO);
	input_struct_destroy(&input);
	exit(status);
}
