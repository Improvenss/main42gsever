/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:36:25 by gsever            #+#    #+#             */
/*   Updated: 2022/08/08 15:56:26 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_philo_thread.c
 * @author Gorkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-08-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "philosophers.h"

/**
 * @brief Her philosopher'e bir thread olusturuyoruz. Boylelikle her 
 * philosopherimiz bir thread oluyor.
 * 
 * @return void
 * @param base
 * @fn @param pthread_create
 * @fn @param lifecycle
 * @fn @param lifecycle_checker
 * @fn @param pthread_join
 * @bug Clear.
 */
void	init_philo_thread(t_base *base)
{
	int			i;
	pthread_t	lifecycle_id;

	i = -1;
	while (++i < base->philos_count)
	{
		pthread_create(&base->philos[i].th_id, NULL,
			lifecycle, (void *)&base->philos[i]);
	}
	pthread_create(&lifecycle_id, NULL, &lifecycle_checker, base);
	pthread_join(lifecycle_id, NULL);
}
