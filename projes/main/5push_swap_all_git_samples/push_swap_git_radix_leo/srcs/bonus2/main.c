/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 21:43:43 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:45:19 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <fcntl.h>

static void	sub(t_deque *stack[2], int *arr[3], int arr_size, int ct[2])
{
	stack[0] = deque_init();
	stack[1] = deque_init();
	if (!stack[0] || !stack[1])
		error_exit();
	init_stack(stack[0], arr[0], arr_size);
	arr[1] = ft_malloc(arr_size, sizeof(int));
	if (!arr[1])
		error_exit();
	ct[0] = -1;
	while (++ct[0] < arr_size)
		arr[1][ct[0]] = arr[0][ct[0]];
	arr[2] = ft_malloc(arr_size, sizeof(int));
	if (!arr[2])
		error_exit();
	ct[0] = -1;
	while (++ct[0] < arr_size)
		arr[2][ct[0]] = arr[0][ct[0]];
	ft_sort(arr[1], arr[1] + arr_size, ft_ascending);
	descretize_stack(stack[0], arr[1], arr_size);
}

int	main(int argc, char **argv)
{
	int				*arr[3];
	int				arr_size;
	t_deque			*stack[2];
	int				ct[2];
	t_deque			*instructions;

	arr_size = get_nbr_in_line(arr, argc, argv);
	if (arr_size < 2)
		normal_exit();
	sub(stack, arr, arr_size, ct);
	instructions = push_swap(stack);
	ct[1] = open("instructions", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ct[1] < 0)
		error_exit();
	display_instructions(instructions, arr[2], arr_size, ct[1]);
	close(ct[1]);
	normal_exit();
}
