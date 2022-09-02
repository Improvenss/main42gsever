/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:41:18 by gsever            #+#    #+#             */
/*   Updated: 2022/09/01 17:01:28 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*lifecycle_checker(void *arg)
{
	t_base		*base;
	uint64_t	timestamp;
	int			i;

	base = (t_base *)arg;
	i = 0;
	while (1)
	{
		if (base->philo->full_count == base->number_of_philo)
			break ;
		if (i == base->number_of_philo)
			i = 0;
		usleep(1000);
		timestamp = get_time();
		if (!base->philo[i].full && ((int)(timestamp
				- base->philo[i].last_eat_time) > base->time_to_eat))
		{
			write_command(get_time(), &base->philo[i], DEAD);
			base->is_running = false;
			break ;
		}
		i++;
	}
	return (NULL);
}

void	*lifecycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat_time = get_time();
	while (philo->base->is_running)
	{
		if (philo->id % 2 == 1)
		{
			action_think(philo);
			usleep(philo->base->time_to_eat * 0.25 * 1000);
		}
		action_eat(philo);
		action_think(philo);
		if (philo->eat_count == philo->base->must_eat_count)
		{
			philo->full_count++;
			philo->full = true;
			break ;
		}
		action_sleep(philo);
	}
	return (NULL);
}
