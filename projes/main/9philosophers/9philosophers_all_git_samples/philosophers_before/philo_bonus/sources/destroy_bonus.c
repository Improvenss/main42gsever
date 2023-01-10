/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:25:20 by gsever            #+#    #+#             */
/*   Updated: 2022/09/08 19:54:57 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file destroy_bonus.c
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
 * @brief Destroying created semaphores.
 * 
 * @fn sem_unlink()
 */
void	destroy_semaphores_b(void)
{
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_WRITE);
	sem_unlink(SEM_DIED);
}

/**
 * @brief Destroying fork()'ed, created PID's.
 * 
 * @param base 
 * @fn kill()
 */
void	destroy_pids_b(t_base *base)
{
	int	i;

	i = -1;
	while (++i < base->philos_count)
		kill(base->philos_pid[i], SIGKILL);
}

/**
 * @brief Destroying all PIDs, semaphores and freeing.
 * 
 * @param base 
 * @fn destroy_pids_b()
 * @fn destroy_semaphores_b()
 * @fn free()
 */
void	destroy_all_b(t_base *base)
{
	destroy_pids_b(base);
	destroy_semaphores_b();
	free(base->philos);
	free(base->philos_pid);
}
