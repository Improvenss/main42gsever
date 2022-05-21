/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:24:34 by vinograd          #+#    #+#             */
/*   Updated: 2019/09/04 20:56:15 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	usage(void)
{
	ft_printf("usage: checker -e -v -g 5 4 3 2 ...\n");
	ft_printf("-e  error hendling\n-v  visual mode\n-g  game mode\n");
	exit(1);
}

void	print_man(void)
{
	ft_printf("man - show the list again\n");
	ft_printf("help - ask the computer to help\n");
	ft_printf("sa/sb/ss - swap the first two numbers in the stack a/b/both\n");
	ft_printf("pa - push the first number from stack b to stack a\n");
	ft_printf("pb - push the first number from stack a to stack b\n");
	ft_printf("ra/rb/rr - put the fist number to the \
	bottom of the stack a/b/both\n");
	ft_printf("rra/rrb/rrr - put the last number to the \
	top of the stack a/b/both\n");
}
