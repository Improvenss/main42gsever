/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:19:29 by gsever            #+#    #+#             */
/*   Updated: 2022/08/08 12:59:09 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_args.c
 * @author Gorkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "philosophers.h"
/**
 * @brief Checking args and initializing values for philos.
 * @return void
 * @param check_args Checking args is true and initializing when checking.
 * 
 */
void	init_args(int ac, char **av, t_base *base)
{
	check_args(ac, av);
	base->philos_count = atoi(av[1]);
	base->time_to_die = atoi(av[2]);
	base->time_to_eat = atoi(av[3]);
	base->time_to_sleep = atoi(av[4]);
	base->must_eat = 0;
	if (ac == 6)
		base->must_eat = atoi(av[5]);
	check_args_in_values(base);
}