/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:09:35 by gsever            #+#    #+#             */
/*   Updated: 2022/08/15 19:18:12 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_philo.c
 * @author Gorkem SEVER (gsever)
 * @brief Initializing philosophers parameters here.
 * @version 0.1
 * @date 2022-08-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "philosophers.h"

/**
 * @brief Philosopher's values entering here.
 * 
 * @return void
 * @param base 
 * @fn malloc()				: Bellekte yer aciyoruz.
 * @fn get_current_time()	: Simdiki zamani aliyoruz. 'ms' cinsinden.
 * @bug Clear.
 */
void	init_philo(t_base *base)
{
	int	i;

	base->philos = malloc(sizeof(t_philos) * base->philos_count);
	base->fork = malloc(sizeof(pthread_mutex_t) * base->philos_count);
	base->start_time = get_current_time();
	i = -1;
	while (++i < base->philos_count)
	{
		base->philos[i].common = base;
		base->philos[i].id = i + 1;
		base->philos[i].fork_l = i;
		base->philos[i].fork_r = (i + 1) % base->philos_count;
		base->philos[i].eat_count = 0;
		base->philos[i].last_eat_time = 0;
	}
}