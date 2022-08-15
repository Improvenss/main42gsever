/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:35:12 by gsever            #+#    #+#             */
/*   Updated: 2022/08/15 19:41:13 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*lifecycle_checker(void *arg)
{
	(void)*arg;
	return (NULL);
}

/**
 * @brief 
 * 
 * @param arg 
 * @fn get_current_time()	:
 * @fn philo_think()		:
 * @fn usleep()				:
 * @fn take_forks()			:
 * @fn philo_eat()			:
 * @return void* 
 * @bug Clear.
 */
void	*lifecycle(void *arg)
{
	t_base	*base;

	base = (t_base *)arg;
	base->philos->last_eat_time = get_current_time() - base->start_time;
	if (base->philos->id % 2 == 1)
	{
		philo_think(base);
		usleep(base->time_to_eat * 0.25 * 1000);
	}
	while (!base->philos->full)
	{
		take_forks(base);
		philo_eat(base);
		take_forks(base);
		philo_think(base);
		if(base->philos->eat_count == base->must_eat)
		{
			base->philos->full = true;
			base->philos->eat_count++;
			break ;
		}
		philo_sleep(base);
	}
	return (NULL);
}
