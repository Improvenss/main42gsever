/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:58:38 by gsever            #+#    #+#             */
/*   Updated: 2022/08/15 19:30:47 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_mutex.c
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
 * @brief Initializing mutex for philosopher's threads.
 * 
 * @param base 
 * @fn pthread_mutex_init()	: Every fork for initialize ON / OFF value.
 */
void	init_mutex(t_base *base)
{
	int	i;

	i = -1;
	while (++i < base->philos_count)
		pthread_mutex_init(&base->fork[i], NULL);
}