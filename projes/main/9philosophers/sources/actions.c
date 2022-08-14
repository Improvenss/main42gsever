/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 05:32:09 by gsever            #+#    #+#             */
/*   Updated: 2022/08/14 17:09:20 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file actions.c
 * @author Gorkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "philosophers.h"

void	take_forks(t_base *base)
{
	uint64_t	real_time;

	pthread_mutex_lock(base->fork);
	
}

/**
 * @brief Philosopher's "SLEEP" function.
 * 
 * Creating unsigned long long for real time, we are printing real time,
 * philosopher's id, and it's sleeping.
 * 
 * @param base
 * @fn get_current_time()
 * @fn printf()
 * @bug Clear.
 */
void	philo_sleep(t_base *base)
{
	uint64_t	real_time;

	real_time = get_current_time() - base->philos->last_eat_time;
	printf("%llu %d %s\n", real_time, base->philos->id, "is sleeping");
	//usleep eklenecek.
}

/**
 * @brief Philosopher's "EAT" function.
 * 
 * Creating unsigned long long for real time, we are printing real time,
 * philosopher's id, and it's eating.
 * 
 * @param base
 * @fn get_current_time()
 * @fn printf()
 * @bug Clear.
 */
void	philo_eat(t_base *base)
{
	uint64_t	real_time;

	real_time = get_current_time() - base->philos->last_eat_time;
	printf("%llu %d %s\n", real_time, base->philos->id, "is eating");
	base->philos->last_eat_time = real_time;
	base->philos->eat_count++;
	//usleep eklenecek.
}

/**
 * @brief Philosopher's "THINKING" function.
 * 
 * Creating unsigned long long for real time, we are printing real time,
 * philosopher's id, and it's thinking.
 * 
 * @param base
 * @fn get_current_time()
 * @fn printf()
 * @bug Clear.
 */
void	philo_think(t_base *base)
{
	uint64_t	real_time;

	real_time = get_current_time() - base->philos->last_eat_time;
	printf("%lld %d %s\n", real_time, base->philos->id, "is thinking");
}