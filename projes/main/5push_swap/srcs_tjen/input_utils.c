/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:17:56 by gsever            #+#    #+#             */
/*   Updated: 2022/06/25 16:36:08 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

/* Function to exit and free all dependencies while input process */
void	input_exit(t_input *input, int status)
{
	if(status == INVALID_INPUT)
		ft_putendl_fd("Error", STDERR_FILENO);
	input_struct_destroy(&input);
	exit(status);
}

/* Returns an input struct, with malloced memory and init some values */
t_input *input_struct_get(void)
{
	t_input *input;

	input = malloc(sizeof(t_input));
	if(input == NULL)
		input_exit(input, ENOMEM);
	input->array = NULL;
	input->int_array = NULL;
	input->size = 0;
	input->is_split = false;
	return (input);	
}