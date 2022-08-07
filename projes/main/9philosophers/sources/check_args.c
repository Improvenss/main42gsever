/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:24:30 by gsever            #+#    #+#             */
/*   Updated: 2022/08/08 00:35:10 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file check_arg.c
 * @author Gorkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-08-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "philosophers.h"
/**
 * @brief 
 * 
 */
void	check_args_in_values(int ac, char **av, t_base *base)
{
	(void)ac;
	(void)**av;
	(void)base;
}

/** --> OK
 * @brief ARGS sayimiz dogruysa bu func() calisacak. 
 * @return void
 * @param ft_perror If have error writing terminal "Error".
 * @param ft_isdigit
 * @bug Clear.
 */
void	check_args_on_shell(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '\0')
			exit(-1);
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				exit(-1);
			j++;
		}
		i++;
	}
}

/** --> NOK
 * @brief 5 ya da 6 oldugunda calisacak yoksa error.
 * -> Programların alacağı argümanlar;
 * 		(1)Filozof Sayısı, (2)Ölme Süresi, (3)Yemek Yeme Süresi,
 * 		(4)Uyuma Süresi, (5)Her Filozofun Yemek Yeme Sayısı.
 * @return void
 * @param check_args_on_shell
 * @param check_args_in_values
 * @bug Clear.
 */
void	check_args(int argc, char **argv, t_base *base)
{
	if (argc >= 5 && argc <= 6)
	{
		check_args_on_shell(argc, argv);
		check_args_in_values(argc, argv, base);
	}
	else
	{
		printf(RED"ERROR:			-> ./philosophers ");
		printf("p_count die eat sleep [cycle count]\n"X);
		printf(RED"ERROR: Use like this	-> ./philosophers 7 800 200 200 5\n"X);
		printf(RED"Or			-> ./philosophers 7 800 200 200\n"X);
		exit(-1);
	}
}