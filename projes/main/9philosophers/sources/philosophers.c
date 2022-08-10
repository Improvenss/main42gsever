/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:51:09 by gsever            #+#    #+#             */
/*   Updated: 2022/08/10 04:09:14 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philosophers.c
 * @author Gorkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "philosophers.h"

/**
 * @brief philosophers main func. Using thread.
 * @return void
 * @param check_args
 * @bug Clear.
 */
void	philosophers(int argc, char **argv, t_base *base)
{
	init_args(argc, argv, base);
	init_philo(base);
	init_mutex(base);
	init_philo_thread(base);
	//destroy
}