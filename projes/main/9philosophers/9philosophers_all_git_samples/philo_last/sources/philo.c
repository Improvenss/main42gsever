/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:39:08 by gsever            #+#    #+#             */
/*   Updated: 2022/09/02 12:39:10 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo.c
 * @author Gorkem SEVER (gsever)
 * @brief Main philosopher's function starting here.
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "philos.h"

/**
 * @brief Philosopher's main function. Every Philosopher one thread.
 * 
 * @return void
 * 
 * @param ac Arguman count from shell.
 * @param av Arguman veriable from shell.
 * @param base Base structure from library.
 * 
 * @fn init_args()			: Argumanlari kontrol ediyoruz.
 * @fn init_philos()		: Philosopher's values entering.
 * @fn init_mutexes()		: Creating mutex for thread's forks.
 * @fn init_philos_thread()	: Burada thread sonrasi lifecycle dongusu var.
 * @fn destroy_all_mutexes(): Destorying mutexes.
 * @fn destory_all_threads(): Destroying threads.
 * 
 * @bug Clear
 */
void	philosophers(int ac, char **av, t_base *base)
{
	init_args(ac, av, base);
	init_philos(base);
	init_mutexes(base);
	init_philos_thread(base);
	destroy_all_mutexes(base);
	destory_all_threads(base);
}
