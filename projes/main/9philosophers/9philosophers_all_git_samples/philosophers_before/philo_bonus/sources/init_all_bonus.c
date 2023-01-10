/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:49:16 by gsever            #+#    #+#             */
/*   Updated: 2022/09/08 19:55:35 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_all_bonus.c
 * @author Gorkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-09-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "philo_bonus.h"

/**
 * @brief Creating child process(philosopher) every philosophers and
 * 	running lifecycle func().
 * 
 * NOT: fork() is creating child process from parent process.
 * 	fork()'u calistirdigimiz andan itibaren child process olusuyor
 * 	ve o child process == 0'sa lifecycle'ye girecek, sonrasinda
 * 	while devam edecek.
 * 
 * 
 * @param base Main structure for philo_pid and philos.
 * @fn malloc()
 */
void	init_philo_process_b(t_base *base)
{
	int	i;

	base->philos_pid = malloc(sizeof(int) * base->philos_count);
	i = -1;
	while (++i < base->philos_count)
	{
		base->philos_pid[i] = fork();
		if (base->philos_pid[i] == 0)
		{
			lifecycle_b(&base->philos[i]);
			return ;
		}
	}
}

/**
 * @brief 
 * 
 * chmod: dosya izinleri (yetki) değiştirme komutu
 * 	--> sem_open();
 * 	-> sem_t *sem_open(const char *name, int oflag, mode_t mode, uint value);
 * Ad, eğik çizgi ('/') karakteriyle başlamalıdır.	e.g.-> "/sem_fork"
 * Başlamıyorsa, sistem adın başına bir eğik çizgi ekler. e.g.-> "sem_fork"

	r = 4, w = 2, x = 1 değerini alıyor.
	
	rwx = okuma, yazma, çalıştırma izni oluyor.

	- 1 - - - 2 - - - 3 - - - =gibi gruplandırılıyor
		r - - = yalnız okuma izni var,
		- w - = yalnız yazma izni var,		
		- - x = yalnız çalıştırma izni var.

			sample --> chmod -v 777 sample.*

		" NOT: Baştaki (-) dosya ya da klasörün türünü gösterir "
		So each triple encodes nicely as an octal digit.

			rwx oct	  meaning --> think binary
			--- ---	  -------
			001 01	= execute
			010 02	= write
			011 03	= write & execute
			100 04	= read
			101 05	= read & execute
			110 06	= read & write
			111 07	= read & write & execute

	1. Kisim varsa sahip izinleri
	2. Kisim varsa grup izinleri
	3. Kisim varsa diğer kullanıcı izinleri

 * 
 * @link https://www.ibm.com/docs/en/i/7.1?topic=ssw_ibm_i_71/apis/ipcsemo.htm
 * @param base 
 * @fn sem_open() name, mevcut degilse olustur varsa elleme,
 * 		chmod(dosya) izinleri, semaphore adedi(qty -> quantitiy) miktari.
 * @note 
 */
void	init_semaphore_b(t_base *base)
{
	destroy_semaphores_b();
	base->sem_forks = sem_open(SEM_FORK, O_CREAT, 644, base->philos_count);
	base->sem_write = sem_open(SEM_WRITE, O_CREAT, 644, 1);
	base->sem_done = sem_open(SEM_DIED, O_CREAT, 644, 0);
	if (base->sem_forks == SEM_FAILED || base->sem_forks == SEM_FAILED
		|| base->sem_forks == SEM_FAILED)
		exit(1);
}

/**
 * @brief Philosopher's values entering here.
 * 
 * @return void
 * @param base* 
 * @fn malloc()				: Bellekte yer aciyoruz.
 * @bug Clear.
 */
void	init_philo_b(t_base *base)
{
	int	i;

	base->philos = malloc(sizeof(t_philos) * base->philos_count);
	i = -1;
	while (++i < base->philos_count)
	{
		base->philos[i].base = base;
		base->philos[i].id = i + 1;
		base->philos[i].eat_count = 0;
		base->philos[i].last_eat_time = 0;
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
void	init_args_b(int ac, char **av, t_base *base)
{
	check_args_b(ac, av);
	base->philos_count = ft_atoi(av[1]);
	base->time_to_die = ft_atoi(av[2]);
	base->time_to_eat = ft_atoi(av[3]);
	base->time_to_sleep = ft_atoi(av[4]);
	base->must_eat = -1;
	base->is_running = true;
	if (ac == 6)
		base->must_eat = ft_atoi(av[5]);
	check_args_in_values_b(base);
	base->start_time = get_current_time_b(base);
}
