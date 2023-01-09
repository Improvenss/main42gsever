/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:01:25 by gsever            #+#    #+#             */
/*   Updated: 2022/09/16 17:38:58 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_time_bonus.c
 * @author Görkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-09-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "philo_bonus.h"

/**
 * @brief Islem suresini hesaplamak icin kullandigimiz fonksiyon.
 * 
 * Current time --> ct
 * second: 1659960007[000]
 * micro second: [255]371
 * last time --> 1659960007255%
 * 
 * @fn gettimeofday() : Zamani milisecond cinsinden aliyoruz.
 */
uint64_t	get_current_time_b(t_base *base)
{
	struct timeval	ct;
	uint64_t		past_time;

	gettimeofday(&ct, NULL);
	past_time = (ct.tv_sec * (uint64_t)1000)
		+ (ct.tv_usec / 1000) - base->start_time;
	return (past_time);
}
