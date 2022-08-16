/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:51:39 by gsever            #+#    #+#             */
/*   Updated: 2022/08/16 17:08:53 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_all.c
 * @author Gorkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "philosophers.h"

/** OK
 * @brief Her philosopher'e 'pthread_create' functionuyla bir thread
 * 	olusturuyoruz.
 * 
 * >Bu thread yani philosopher kendi lifecycle dongusunu calistiriyor.
 * >Boylelikle her philosopherimiz bir thread oluyor.
 * 
 * >Buradaki 'i' philosopher'i temsil ediyor.
 * 
 * @return void
 * @param base
 * 
 * @fn pthread_create	: Her philosopher'a yeni bir thread burada
 * 	olusturmus oluyoruz. --> Philosopher_id'sine lifecycle functionunu
 * 	calismasi gorevini veriyoruz.
 * @fn lifecycle		: Philosopherlerin yasam dongusunu gerceklestiriyor.
 * @fn lifecycle_checker: Eger olen bir philosopher var mi onu kontrol ediyor.
 * @fn pthread_join		: 
 * 
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
			&lifecycle, (void *)&base->philos[i]);
	}
	pthread_create(&lifecycle_id, NULL, &lifecycle_checker, base);
	pthread_join(lifecycle_id, NULL);
}

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
	pthread_mutex_init(&base->write, NULL);
}

/**
 * @brief Philosopher's values entering here.
 * 
 * @return void
 * @param base 
 * @fn malloc()				: Bellekte yer aciyoruz.
 * @fn get_current_time()	: Simdiki zamani aliyoruz. 'ms' cinsinden.
 * @bug Clear.
 */
void	init_philo(t_base *base)
{
	int	i;

	base->philos = malloc(sizeof(t_philos) * base->philos_count);
	base->fork = malloc(sizeof(pthread_mutex_t) * base->philos_count);
	base->start_time = get_current_time();
	i = -1;
	while (++i < base->philos_count)
	{
		base->philos[i].common = base;
		printf(GREEN"sonceki id'miz --> %d		", base->philos[i].id);
		base->philos[i].id = i + 1;
		printf("sonraki id'miz --> %d\n"X, base->philos[i].id);
		// base->philos[i].th_id = 0;
		base->philos[i].fork_l = i;
		base->philos[i].fork_r = (i + 1) % base->philos_count;
		base->philos[i].eat_count = 0;
		base->philos[i].last_eat_time = 0;
		base->philos[i].full = false;
	}
}

/**
 * @brief Checking args and initializing values for philos.
 * @return void
 * @param check_args Checking args is true and initializing when checking.
 * 
 */
void	init_args(int ac, char **av, t_base *base)
{
	check_args(ac, av);
	base->philos_count = atoi(av[1]);
	base->time_to_die = atoi(av[2]);
	base->time_to_eat = atoi(av[3]);
	base->time_to_sleep = atoi(av[4]);
	base->must_eat = -1;
	base->is_running = true;
	if (ac == 6)
		base->must_eat = atoi(av[5]);
	check_args_in_values(base);
}
