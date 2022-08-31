/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:03:20 by gsever            #+#    #+#             */
/*   Updated: 2022/08/31 13:57:28 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	action_think(t_philo *philo)
{
	write_command(get_time(), philo, THINK);
}

void	action_sleep(t_philo *philo)
{
	write_command(get_time(), philo, SLEEP);
}

