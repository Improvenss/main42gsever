/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:35:12 by gsever            #+#    #+#             */
/*   Updated: 2022/08/15 23:57:26 by gsever           ###   ########.fr       */
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
		if (base->philos->full_count == base->philos_count)
			break ;
		if (i == base->philos_count)
			i = 0;
		usleep(100);
		timestamp = get_current_time() - base->start_time;
		if (!base->philos[i].full
			&& ((int)(timestamp - base->philos[i].last_eat_time) > base->time_to_die))
		{
			printf("%llu %d %s\n", timestamp, base->philos[i].id, "died");
			//base->is_running = false;
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
	t_base	*base;
	
	base = (t_base *)arg;
	base->philos->last_eat_time = get_current_time() - base->start_time;
	if (base->philos->id % 2 == 1)
	{
		philo_think(base);
		usleep(base->time_to_eat * 0.25 * 1000);
	}
	printf("bura calisiyor mu amk\n");
	while (!base->philos->full)
	{
		printf("BURAYA GIRMITOR O ZMAAN PPU AMK\n");
		take_forks(base);
		philo_eat(base);
		leave_forks(base);
		philo_think(base);
		if (base->philos->eat_count == base->must_eat)/* 7 800 200 200 [5] buradaki 5 kac kere donecegini belirtiyor. */
		{
			base->philos->full = true;
			base->philos->full_count++;
			break ;
		}
		philo_sleep(base);
	}
	printf("anneni deleyim\n");
	return (NULL);
}
