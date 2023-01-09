/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:51:39 by gsever            #+#    #+#             */
/*   Updated: 2022/09/14 09:07:55 by gsever           ###   ########.fr       */
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
 * @brief 	
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
 * @bug Clear.
 */
void	init_philo(t_base *base)
{
	int	i;

	base->philos = malloc(sizeof(t_philos) * base->philos_count);
	base->fork = malloc(sizeof(pthread_mutex_t) * base->philos_count);
	i = -1;
	while (++i < base->philos_count)
	{
		base->philos[i].common = base;
		base->philos[i].id = i + 1;
		base->philos[i].fork_l = i;
		base->philos[i].fork_r = (i + 1) % base->philos_count;
		base->philos[i].eat_count = 0;
		base->philos[i].last_eat_time = 0;
		base->philos[i].full = false;
	}
}

/** -> * All OK *
 * @brief Checking args and initializing values for philos.
 * @param ac : For params are okay.
 * @param av** : For params values are okay.
 * @param base* : Getting main stuct.
 * @fn check_args : Checking args is true and initializing when checking.
 * @fn check_args_in_values : Checking args values.
 * @fn get_current_time()	: Simdiki zamani aliyoruz. 'ms' cinsinden.
 * @return void
 */
void	init_args(int ac, char **av, t_base *base)
{
	check_args(ac, av);
	base->philos_count = ft_atoi(av[1]);
	base->time_to_die = ft_atoi(av[2]);
	base->time_to_eat = ft_atoi(av[3]);
	base->time_to_sleep = ft_atoi(av[4]);
	base->must_eat = -1;
	base->is_running = true;
	if (ac == 6)
		base->must_eat = ft_atoi(av[5]);
	check_args_in_values(base);
	base->start_time = get_current_time(base);
}
