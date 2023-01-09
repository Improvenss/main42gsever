/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:24:00 by gsever            #+#    #+#             */
/*   Updated: 2022/09/08 19:47:51 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file write_command_bonus.c
 * @author Görkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-09-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "philo_bonus.h"

/**
 * @brief Write command with semaphore.
 * 
 * @param time real_time.
 * @param philos philos struct.
 * @param state Action's state. (EAT, SLEEP, THINK, TOOK_FORK, DEAD).
 */
void	write_command_b(uint64_t time, t_philos *philos, t_state state)
{
	const char	*actions[6] = {STR_EAT, STR_SLEEP, STR_THINK,
		STR_TOOK_FORK, STR_DEAD, NULL};

	if (!philos->base->is_running)
		return ;
	sem_wait(philos->base->sem_write);
	printf("%llu	%d	%s\n", time, philos->id, actions[state]);
	sem_post(philos->base->sem_write);
}
