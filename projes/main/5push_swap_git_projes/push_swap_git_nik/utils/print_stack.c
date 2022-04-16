/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:58:05 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/14 10:36:29 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_stack(int *stack_a, int *stack_b, int steps)
{
	int len;

	len = MAX(A_LEN, B_LEN);
	ft_printf("{cyan}_________{eoc}\n");
	while (len > 0)
	{
		if (len > 0 && len <= A_LEN)
			ft_printf("%d", stack_a[len]);
		if (len > 0 && len <= B_LEN)
			ft_printf("\t%d", stack_b[len]);
		ft_printf("\n");
		len--;
	}
	ft_printf("{cyan}^ BOTOM ^\n");
	ft_printf("a%4d   b{eoc}\n", steps);
}
