/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:33:22 by gsever            #+#    #+#             */
/*   Updated: 2022/08/10 05:41:24 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file philosophers.h
 * @brief Library for 'philosophers' project.
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//	STANDARD LIBRARY INCLUDES
# include <unistd.h> /*
	write()		-> System call used to write data from the buffer,
	fork()		-> Create thread from process. */
# include <stdlib.h> /*
	free()		-> Deallocatig all allocated memory,
	exit()		-> Closing everything with atexit() and terminates program. */
# include <stdio.h> /*
	printf()	-> A library function to send formatted output to the screen. */
# include <signal.h> /*
	kill()		-> Close process from PID. */
# include <stdint.h> /*
	Type	 	Name		Num_Bytes	Num_Bits	Integer_Range
	int8_t	 ->	char			1			8		-128 to 127,
	int16_t	 ->	short			2			16		-32768 to 32767,
	int32_t	 ->	int				4			32		-2147483648 to 2147483647,
	int64_t	 ->	long long		8			64		-9.223372e+18 to 9.223372e+18
	uint8_t	 ->	unsigned char	1			8			0 to 255,
	uint16_t ->	unsigned short	2			16			0 to 65535,
	uint32_t ->	unsigned int	4			32			0 to 4294967295,
	uint64_t ->	unsigned l_l 	8			64		0 to 18446744073709551615 */
# include <stdbool.h>
# include <errno.h>
# include <limits.h>
# include <string.h> /*
	memset()	-> Filling memory allocated with a value we want,
	malloc()	-> Allocating memory with NULL. */
# include <sys/types.h>
# include <sys/time.h> /*
	gettimeofday() */
# include <pthread.h> /*Mendatory part:
	pthread_create() -> Create process for one function,
	pthread_detach() -> Thread'la isimiz bittiginde bunu geri ,
	pthread_join()	 -> p_create ile gorevlendigimiz thread'i calistirmaya yariyor,
	pthread_mutex_init(),
	pthread_mutex_destroy(),
	pthread_mutex_lock(),
	pthread_mutex_unlock() */
# include <semaphore.h> /* Bonus part:
	sem_open(),
	sem_close(),
	sem_post(),
	sem_wait(),
	sem_unlink() */

//	COLORS --> 🟥 🟩 🟦
# define LB		"\033[0;36m"
# define BLUE	"\033[0;34m"
# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define RED	"\033[0;31m"
# define RESET	"\033[0m"
# define X		"\033[m"

/* ************************************************************************** */
/* STRUCT DEFINES AREA													  	  */
/* ************************************************************************** */

typedef struct s_base	t_base;

/**
 * @brief This struct for just one philosopher.
 * @param common*		: Main event BRUH.
 * @param eat_count		: How many times eated.
 * @param full			: Is finished one cycle(dongu)-> eat -> sleep -> think.
 * @param last_eat_time	: Elapsed time since the philosopher last ate.
 * @param fork_l		: Left fork.
 * @param fork_r		: Right fork.
 * @param th_id
 * @param id			: Philosopher's thread id.
 */
typedef struct s_philos
{
	t_base		*common;
	int			eat_count;
	int			full;	
	long		last_eat_time;
	int			fork_l;
	int			fork_r;
	pthread_t	th_id;
	int			id;

}		t_philos;

/**
 * @brief This struct for main cycle.
 * @param philos*		: Creates a Philosopher.
 * @param fork*			: Mutexs.
 * @param philos_count	: The amount of philosophers we have.
 * @param time_to_die	: The time the philosophers take to die.
 * @param time_to_eat	: The time the philosophers take to eat.
 * @param time_to_sleep	: The time the philosophers take to sleep.
 * @param must_eat		: Cycle count --> Must eat count.
 * @param start_time	: When start ./philosophers -> starting timer.
 * @param dead_time		: The time the philosophers take to death.
 * @param total_full	:
 * 
 */
typedef struct s_base
{
	t_philos		*philos;
	pthread_mutex_t	*fork;
	int				philos_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				start_time;
	// int			dead_time;
	// int			total_full;
}		t_base;


/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

//check_args.c
void	check_args_in_values(t_base *base);
void	check_args_on_shell(int ac, char **av);
void	check_args(int argc, char **argv);

//error.c
int	ft_perror(char *str);

//get_time.c
long	get_current_time();

//init_args.c
void	init_args(int ac, char **av, t_base *base);

//init_mutex.c
void	init_mutex(t_base *base);

//init_philo_thread.c
void	init_philo_thread(t_base *base);

//init_philo.c
void	init_philo(t_base *base);

//lifecycle.c
void	*lifecycle_checker(void *arg);
void	*lifecycle(void *arg);

//actions.c
void	philo_think(t_base *base);

//philosophers.c
void	philosophers(int argc, char **argv, t_base *base);

#endif
