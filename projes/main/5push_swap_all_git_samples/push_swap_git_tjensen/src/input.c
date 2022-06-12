/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:35:13 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/19 10:18:58 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	input_str_check(t_input *input);
static int	input_str_array_check(t_input *input);
static void	input_int_array_check_duplicates(t_input *input);
static bool	input_is_sorted(int	*array, int size);

/*
**	Checks the user input from *argv[].
**	Exits the program if the input is not valid.
**
**	Input Checks:
**	1. Valid seperation chars (just a single space between numbers is valid)
**	2. Valid characters (just: Numbers, Minus and Space)
**	3. INT overflows
**	4. Duplicates
**	5. If bool (check_sort=true) the function checks if input is already sorted
*/
void	input_check(t_input *input, int argc, char *argv[], bool check_sort)
{
	int	i;

	input->array = &(argv[1]);
	if (argc < 2)
		input_exit(input, NO_ARGS);
	if (argc == 2)
		input->size = input_str_check(input);
	else
		input->size = input_str_array_check(input);
	input->int_array = malloc(input->size * sizeof(int));
	if (input->int_array == NULL)
		input_exit(input, ENOMEM);
	i = 0;
	while (input->array[i])
	{
		if (ft_strtoi(input->array[i], &input->int_array[i], BASE10))
			input_exit(input, INVALID_INPUT);
		i++;
	}
	input_int_array_check_duplicates(input);
	if (check_sort && input_is_sorted(input->int_array, input->size))
		input_exit(input, EXIT_SUCCESS);
}

/* Checks the input if it's in single string format (argc=2, argv[1]="0 3 2") */
static int	input_str_check(t_input *input)
{
	size_t	i;
	size_t	str_len;
	char	*str;

	str = (*input->array);
	str_len = ft_strlen(str);
	if (str[0] != '-' && str[0] != '+' && !ft_isdigit(str[0]))
		input_exit(input, INVALID_INPUT);
	else if (!ft_isdigit(str[str_len - 1]))
		input_exit(input, INVALID_INPUT);
	i = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
			input_exit(input, INVALID_INPUT);
		i++;
	}
	input->array = ft_split(*input->array, ' ');
	if (input->array == NULL)
		input_exit(input, ENOMEM);
	input->is_split = true;
	return (input_str_array_check(input));
}

/* Checks the input if it's in string array format */
static int	input_str_array_check(t_input *input)
{
	int	i;
	int	j;

	i = 0;
	while (input->array[i])
	{
		if (input->array[i][0] == '\0')
			input_exit(input, INVALID_INPUT);
		j = 0;
		if ((input->array[i][j] == '-' || input->array[i][j] == '+')
			&& input->array[i][j + 1] != '\0')
			j++;
		while (input->array[i][j])
		{
			if (!ft_isdigit(input->array[i][j]))
				input_exit(input, INVALID_INPUT);
			j++;
		}
		i++;
	}
	return (i);
}

/* Searchs for duplicates in an int array (after input conversion) */
static void	input_int_array_check_duplicates(t_input *input)
{
	int	i;
	int	j;

	i = 0;
	while (i < input->size)
	{
		j = i + 1;
		while (j < input->size)
		{
			if (input->int_array[i] == input->int_array[j])
				input_exit(input, INVALID_INPUT);
			j++;
		}
		i++;
	}
}

/* Checks if the input is already sorted (after input conversion) */
static bool	input_is_sorted(int	*array, int size)
{
	int	i;

	if (size <= 1)
		return (true);
	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (false);
		i++;
	}
	return (true);
}
