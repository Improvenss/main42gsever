/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:24:30 by gsever            #+#    #+#             */
/*   Updated: 2022/08/06 13:11:01 by gsever           ###   ########.fr       */
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
#include "../includes/philosophers.h"

/**
 * @brief ARGS sayimiz dogruysa bu func() calisacak. 
 * @return void
 * @param ft_error If have error writing terminal "Error".
 * @bug Clear.
 */
void	check_args_if_true(int ac, char **av, t_base base)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		if (av[i][j] == '\0')
			ft_error("Error\n");
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
				ft_error("Error\n");
			j++;
		}
		i++;
	}
}

/**
 * @brief 
 * -> Programların alacağı argümanlar;
 * 		(1)Filozof Sayısı, (2)Ölme Süresi, (3)Yemek Yeme Süresi,
 * 		(4)Uyuma Süresi, (5)Her Filozofun Yemek Yeme Sayısı.
 * @return void
 * @bug Clear.
 */
void	check_args(int argc, char **argv, t_base base)
{
	if (argc >= 4 && argc <= 5)
		check_args_if_true(argc, argv, base);
}