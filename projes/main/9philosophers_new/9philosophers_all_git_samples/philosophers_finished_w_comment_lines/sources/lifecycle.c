/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:35:12 by gsever            #+#    #+#             */
/*   Updated: 2022/09/14 09:40:54 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*lifecycle_checker(void *arg)
{
	t_base		*base;
	uint64_t	timestamp;
	int			i;

	base = (t_base *)arg;
	i = 0;
	while (1)
	{
		if (base->full_count == base->philos_count)
			break ;
		if (i == base->philos_count)
			i = 0;
		usleep(10);
		timestamp = get_current_time(base);
		if (!base->philos[i].full && ((int)(timestamp
				- base->philos[i].last_eat_time) > base->time_to_die))
		{
			// printf("%llu %d %s\n", timestamp, base->philos[i].id, "died");
			write_actions(timestamp, &base->philos[i], DEAD);
			base->is_running = false;
			break ;
		}
		i++;
	}
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
 * @fn philo_sleep()		:
 * @return void* 
 * @bug Clear.
 */
void	*lifecycle(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	philos->last_eat_time = get_current_time(philos->common);
	if (philos->id % 2 == 0)
	{
		philo_think(philos);
		usleep(philos->common->time_to_eat * 0.25 * 1000);
	}
	while (philos->common->is_running)
	{
		philo_eat(philos);
		philo_think(philos);
		if (philos->eat_count == philos->common->must_eat)
		{
			philos->common->full_count++;
			philos->full = true;
			break ;
		}
		philo_sleep(philos);
	}
	return (NULL);
}
