/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:14:48 by gsever            #+#    #+#             */
/*   Updated: 2022/09/08 19:55:07 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	leave_forks_b(t_philos *philos)
{
	sem_post(philos->base->sem_forks);
	sem_post(philos->base->sem_forks);
}

void	take_forks_b(t_philos *philos)
{
	sem_wait(philos->base->sem_forks);
	write_command_b(get_current_time_b(philos->base), philos, TOOK_FORK);
	sem_wait(philos->base->sem_forks);
	write_command_b(get_current_time_b(philos->base), philos, TOOK_FORK);
}

void	philo_sleep_b(t_philos *philos)
{
	write_command_b(get_current_time_b(philos->base), philos, SLEEP);
	usleep(philos->base->time_to_sleep * 1000);
}

void	philo_eat_b(t_philos *philos)
{
	take_forks_b(philos);
	write_command_b(get_current_time_b(philos->base), philos, EAT);
	philos->last_eat_time = get_current_time_b(philos->base);
	philos->eat_count++;
	usleep(philos->base->time_to_eat * 1000);
	leave_forks_b(philos);
}

void	philo_think_b(t_philos *philos)
{
	write_command_b(get_current_time_b(philos->base), philos, THINK);
}
