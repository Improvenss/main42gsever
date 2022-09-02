/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:36:06 by gsever            #+#    #+#             */
/*   Updated: 2022/09/01 16:36:49 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->base->fork[philo->fork_l]);
	pthread_mutex_unlock(&philo->base->fork[philo->fork_r]);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->base->fork[philo->fork_l]);
	write_command(get_time(), philo, TOOK_FORK);
	pthread_mutex_lock(&philo->base->fork[philo->fork_r]);
	write_command(get_time(), philo, TOOK_FORK);
}

void	action_eat(t_philo *philo)
{
	take_forks(philo);
	write_command(get_time(), philo, EAT);
	philo->last_eat_time = get_time();
	philo->eat_count++;
	leave_forks(philo);
	usleep(philo->base->time_to_eat * 1000);
}

void	action_think(t_philo *philo)
{
	write_command(get_time(), philo, THINK);
}

void	action_sleep(t_philo *philo)
{
	write_command(get_time(), philo, SLEEP);
	usleep(philo->base->time_to_sleep * 1000);
}
