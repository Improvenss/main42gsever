/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:13:07 by gsever            #+#    #+#             */
/*   Updated: 2022/09/20 13:32:52 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file lifecycle_bonus.c
 * @author Gorkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-09-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "philo_bonus.h"

/**
 * @brief 
 * 
 * @param arg 
 * @fn waitpid()	fork()'la olusturdugumiz process'lerin islemlerinin
 * 	bitmesini bekliyor. Kendi olusturdugu child processleri -1 adiyla
 * 	goruyor, boylelikle child processlerin islemlerinin bitimesini bekliyor.
 * @fn sem_post()	Process'lerin islemleri bittiginde bittigini bildiriyor.
 * @return void* 
 */
void	*control_philos_b(void *arg)
{
	t_base	*base;
	int		i;

	base = arg;
	i = -1;
	while (++i < base->philos_count)
		waitpid(-1, NULL, 0);
	sem_post(base->sem_done);
	return (NULL);
}

/**
 * @brief This function is a checker thread.
 * 
 * @param arg 
 * @return void* 
 */
void	*lifecycle_checker_b(void *arg)
{
	uint64_t	timestamp;
	t_philos	*philos;

	philos = arg;
	while (true)
	{
		if (philos->base->must_eat == philos->eat_count)
			break ;
		timestamp = get_current_time_b(philos->base);
		if ((int)(timestamp - philos->last_eat_time)
			> philos->base->time_to_die)
		{
			write_command_b(timestamp, philos, DEAD);
			sem_post(philos->base->sem_done);
			break ;
		}
		usleep(10);
	}
	return (NULL);
}

/**
 * @brief 
 * 
 * @param philos 
 */
void	lifecycle_b(t_philos *philos)
{
	pthread_t	th_checker;

	if (philos->id % 2 == 0)
	{
		philo_think_b(philos);
		usleep(philos->base->time_to_die * 0.25 * 1000);
	}
	philos->last_eat_time = get_current_time_b(philos->base);
	pthread_create(&th_checker, NULL, &lifecycle_checker_b, philos);
	pthread_detach(th_checker);
	while (philos->base->is_running)
	{
		philo_eat_b(philos);
		philo_sleep_b(philos);
		philo_think_b(philos);
		if (philos->base->must_eat == philos->eat_count)
			exit(EXIT_SUCCESS);
	}
	exit(EXIT_SUCCESS);
}
