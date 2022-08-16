/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:51:09 by gsever            #+#    #+#             */
/*   Updated: 2022/08/16 14:44:03 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philosophers.c
 * @author Gorkem SEVER (gsever)
 * @brief Main philosopher's function starting here.
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "philosophers.h"

/**
 * @brief Philosopher's main function. Every Philosopher one thread.
 * 
 * @return void
 * 
 * @param argc Arguman count from shell.
 * @param argv Arguman veriable from shell.
 * @param base Base structure from library.
 * 
 * @fn init_args()			: Argumanlari kontrol ediyoruz.
 * @fn init_philo()			: Philosopher's values entering.
 * @fn init_mutex()			: Creating mutex for thread's forks.
 * @fn init_philo_thread()	: Burada thread sonrasi lifecycle dongusu var.
 * @fn destroy_mutexes()	: Destorying mutexes.
 * @fn destory_threads()	: Destroying threads.
 * 
 * @bug Clear
 */
void	philosophers(int argc, char **argv, t_base *base)
{
	init_args(argc, argv, base);
	init_philo(base);
	init_mutex(base);
	init_philo_thread(base);
	destroy_mutexes(base);
	destory_threads(base);
}