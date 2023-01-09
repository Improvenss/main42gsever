/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:06:07 by gsever            #+#    #+#             */
/*   Updated: 2022/09/15 16:23:16 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file destroy.c
 * @author Görkem SEVER (gsever)
 * @brief Destroying, freeing and exit program.
 * @version 0.1
 * @date 2022-08-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "philosophers.h"

/**
 * @brief Destroying and freeing all used mutexes.
 * 
 * @param base 
 * @fn pthread_mutex_destroy()	:
 * @fn free()					:
 * @return void
 */
void	destroy_mutexes(t_base *base)
{
	int	i;

	i = -1;
	while (++i < base->philos_count)
		pthread_mutex_destroy(&base->fork[i]);
	free(base->fork);
}

/**
 * @brief Destroying and freeing all used threads.
 * 
 * @param base 
 * @fn pthread_detach()	:
 * @fn free()			:
 * @return void
 */
void	destory_threads(t_base *base)
{
	int	i;

	i = -1;
	while (++i < base->philos_count)
		pthread_detach(base->philos[i].th_id);
	free(base->philos);
}
