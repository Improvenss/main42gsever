/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 04:51:46 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:50:28 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	sub(int ct[2], t_deque *stack[2], int *arr[3])
{
	if (ct[1] < 2)
		normal_exit();
	stack[0] = deque_init();
	stack[1] = deque_init();
	if (!stack[0] || !stack[1])
		error_exit();
	init_stack(stack[0], arr[0], ct[1]);
	arr[1] = ft_malloc(ct[1], sizeof(int));
	if (!arr[1])
		error_exit();
	ct[0] = -1;
}

int	main(int argc, char **argv)
{
	int				*arr[3];
	t_deque			*stack[2];
	int				ct[2];
	t_deque			*instructions;

	ct[1] = get_nbr_in_line(arr, argc, argv);
	sub(ct, stack, arr);
	while (++ct[0] < ct[1])
		arr[1][ct[0]] = arr[0][ct[0]];
	arr[2] = ft_malloc(ct[1], sizeof(int));
	if (!arr[2])
		error_exit();
	ct[0] = -1;
	while (++ct[0] < ct[1])
		arr[2][ct[0]] = arr[0][ct[0]];
	ft_sort(arr[1], arr[1] + ct[1], ft_ascending);
	descretize_stack(stack[0], arr[1], ct[1]);
	instructions = push_swap(stack);
	display_instructions(instructions, arr[2], ct[1], 1);
	normal_exit();
}
