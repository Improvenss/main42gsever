/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:21:09 by bbourcy           #+#    #+#             */
/*   Updated: 2022/06/28 12:04:16 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* ************************************************************************** */
// verif si sort > incxation > trouver val min et max 
// > baliser les min et max > pb sauf min et max les pivot et les deja sort
// > si sort > compter et trouver nombres avec les plus petits de a et b
// >verif pour les RR et rrr pa jusque b vide > tout est sort > fin 
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_base	stack;

	arg_checker(argc, argv, &stack);
	stack.a = (int *)malloc(sizeof(int) * stack.start.size);
	stack.b = (int *)malloc(sizeof(int) * stack.start.size);
	stack.c = (int *)malloc(sizeof(int) * stack.start.size);
	if (argc > 2)
		stack_fill(argv, argc, &stack);
	else if (argc == 2)
		stack_fill_q(ft_split(argv[1], ' '), &stack);
	else
		ft_free(&stack);
	if (!stack.a || !stack.b || !stack.c)
		ft_error("Error\n");
	indexer(stack.start.size, &stack);
	is_sorted(&stack);
	sort(&stack);
}
