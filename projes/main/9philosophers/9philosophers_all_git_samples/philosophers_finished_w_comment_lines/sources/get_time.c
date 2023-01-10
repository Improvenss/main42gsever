/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:30:32 by gsever            #+#    #+#             */
/*   Updated: 2022/09/14 09:06:30 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_time.c
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
 * @brief Islem suresini hesaplamak icin kullandigimiz fonksiyon.
 * 
 * Current time --> ct
 * second: 1659960007[000]
 * micro second: [255]371
 * last time --> 1659960007255%
 * 
 * @fn gettimeofday() : Zamani milisecond cinsinden aliyoruz.
 */
unsigned long long	get_current_time(t_base *base)
{
	// struct timeval	ct;

	// gettimeofday(&ct, NULL);
	// return ((ct.tv_sec * (uint64_t)1000) + (ct.tv_usec / 1000));
	struct timeval	ct;
	uint64_t		past_time;

	gettimeofday(&ct, NULL);
	past_time = (ct.tv_sec * (uint64_t)1000)
		+ (ct.tv_usec / 1000) - base->start_time;
	return (past_time);
}
