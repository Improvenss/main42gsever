/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 05:32:09 by gsever            #+#    #+#             */
/*   Updated: 2022/08/16 17:26:41 by gsever           ###   ########.fr       */
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

/**
 * @brief Unlocking mutex's job. We can use again this mutex.
 * 
 * @return void
 * @param base 
 * @fn pthread_mutex_unlock()	: Freeing mutex's job.
 * @bug Clear.
 */
void	leave_forks(t_base *base)
{
	pthread_mutex_unlock(&base->fork[base->philos->fork_l]);
	pthread_mutex_unlock(&base->fork[base->philos->fork_r]);
}

/**
 * @brief A philosopher taking forks.
 * 
 * @return void
 * @param base 
 * @fn pthread_mutex_lock()	: Locking mutex for this mutex on the job.
 * @fn get_current_time()	: Getting current time.
 * @fn printf()				: Writing shell -> fork taken.
 * @bug Clear.
 */
void	take_forks(t_base *base)
{
	uint64_t	real_time;

	pthread_mutex_lock(&base->fork[base->philos->fork_l]);
	real_time = get_current_time() - base->start_time;
	printf("%llu %d %s\n", real_time, base->philos->id, "has taken a left fork");
	pthread_mutex_lock(&base->fork[base->philos->fork_r]);
	real_time = get_current_time() - base->start_time;
	printf("%llu %d %s\n", real_time, base->philos->id, "has taken a right fork");
}

/**
 * @brief Philosopher's "SLEEP" function.
 * 
 * Creating unsigned long long for real time, we are printing real time,
 * philosopher's id, and it's sleeping.
 * 
 * @param base
 * @fn get_current_time()	: Getting current time.
 * @fn printf()				: Writing shell philosopher sleeping.
 * @bug Clear.
 */
void	philo_sleep(t_base *base)
{
	uint64_t	real_time;

	real_time = get_current_time();
	printf(BLUE"%llu %d %s\n"X, real_time, base->philos->id, "is sleeping");
	usleep(base->time_to_sleep * 1000);
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

	real_time = get_current_time();
	printf(GREEN"%llu %d %s\n"X, real_time, base->philos->id, "is eating");
	base->philos->last_eat_time = real_time;
	base->philos->eat_count++;
	usleep(base->time_to_eat * 1000);
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

	real_time = get_current_time();
	printf(YELLOW"%lld %d %s\n"X, real_time, base->philos->id, "is thinking");
}
