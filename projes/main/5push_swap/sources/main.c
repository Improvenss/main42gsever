/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:55:29 by gsever            #+#    #+#             */
/*   Updated: 2022/06/14 16:15:37 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

/*
		PUSH_SWAP
	
	This program will sort random integers on a stack with a limited set 
of instructions, trying to use at least stack ops to get a sorted stack.

	
	./push_swap `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
	ARG=$(jot -r -s " " 100 -20000 20000); ./push_swap $ARG | ./checker $ARG -v
	ARG=$(jot -r -s " " 100 -20000 20000); ./push_swap $ARG |
			 ./checker $ARG | print $ARG
*/
int	main(int argc, char **argv)
{
	
}