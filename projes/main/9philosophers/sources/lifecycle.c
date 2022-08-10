/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:35:12 by gsever            #+#    #+#             */
/*   Updated: 2022/08/10 05:49:46 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*lifecycle_checker(void *arg)
{
	(void)*arg;
	return (NULL);
}

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
	//while dongusu eklenmesi lazim lifecycle icin
	return (NULL);
}
