/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:47:09 by gsever            #+#    #+#             */
/*   Updated: 2022/09/08 19:55:17 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_bonus.c
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
 * @brief Philosopher's main function.
 * 
 * @return void
 * 
 * @param argc Arguman count from shell.
 * @param argv Arguman veriable from shell.
 * @param base Base structure from library.
 * 
 * @fn init_args_b()			: Argumanlari kontrol ediyoruz.
 * @fn init_philo_b()			: Philosopher's values entering.
 * @fn init_semaphore_b()		: Burada sem_open()'la semaphore olusturuyoruz.
 * @fn init_philo_process_b()	: Her philosopher icin olusturdugumuz sem'leri
 * 	burada lifecycle() yonlendirerek processlerle lifecycle dongumuzu
 * 	baslatmis oluyoruz.
 * @fn sem_wait()				: Lifecycle dongumuz tamamen bittikten sonra
 * 	sem_post(base->sem_done) ile bitirme semaphore'nin bittigini soyluyoruz,
 * 	sonrasinda program buradan calismaya devam ediyor ve destory_all_b()
 * 	islemlerini yapiyoruz ve programimiz tamamen sonlaniyor. Bunu yapmazsak;
 * 	MAIN process kendi islemini bitirdikten sonra destory asamasina gelip,
 * 	program daha calismasini bitirmeden sonlaniyor.
 * 
 * @bug Clear
 * @note Leaks yiyior.
 */
void	philo_bonus(int argc, char **argv, t_base *base)
{
	printf(B_CYAN"MAIN PID = %d\n"X, getpid());
	base->start_time = 0;
	init_args_b(argc, argv, base);
	init_philo_b(base);
	init_semaphore_b(base);
	init_philo_process_b(base);
	pthread_create(&base->checker, NULL, &control_philos_b, base);
	pthread_detach(base->checker);
	sem_wait(base->sem_done);
	destroy_all_b(base);
}
