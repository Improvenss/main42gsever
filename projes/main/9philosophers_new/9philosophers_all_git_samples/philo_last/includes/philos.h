/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:28:22 by gsever            #+#    #+#             */
/*   Updated: 2022/09/02 12:33:04 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file philos.h
 * @brief Library for 'philosophers' project.
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */

#ifndef PHILOS_H
# define PHILOS_H

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
// # include <semaphore.h> /* Bonus part:
// 	sem_open(),
// 	sem_close(),
// 	sem_post(),
// 	sem_wait(),
// 	sem_unlink() */

# define STR_EAT "is eating"
# define STR_SLEEP "is sleeping"
# define STR_THINK "is thinking"
# define STR_TOOK_FORK "has taken a fork"
# define STR_DEAD "died"

//	COLORS --> 🟥 🟩 🟦
# define LB		"\033[0;36m"
# define BLUE	"\033[0;34m"
# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define RED	"\033[0;31m"
# define RESET	"\033[0m"
# define X		"\033[m"

/* ************************************************************************** */
/* 							STRUCT DEFINES AREA							  	  */
/* ************************************************************************** */

typedef struct s_base	t_base;
typedef struct s_philo	t_philo;

typedef enum s_state
{
	EAT,
	SLEEP,
	THINK,
	TOOK_FORK,
	DEAD
}		t_state;

typedef struct s_philo
{
	t_base			*base;
	pthread_t		th_id;
	int				id;
	int				fork_l;
	int				fork_r;
	int				eat_count;
	uint64_t		last_eat_time;
	bool			full;
}		t_philo;

typedef struct s_base
{
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	write;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				full_count;
	uint64_t		prog_start_time;
	bool			is_running;
}		t_base;

/* ************************************************************************** */
/* 							FUNCTION PROTOTYPES							  	  */
/* ************************************************************************** */

//actions.c --> OK
void		leave_forks(t_philo *philo);
void		take_forks(t_philo *philo);
void		action_eat(t_philo *philo, uint64_t timestamp);
void		action_sleep(t_philo *philo);
void		action_think(t_philo *philo);

//check.c
void		check_args_values(t_base *base);
void		check_args_on_shell(int ac, char **av);
void		check_args(int ac, char **av);

//error.c --> OK
void		ft_perror(char *str);
void		wrong_args_error(void);

//init_all.c --> OK
void		init_args(int ac, char **av, t_base *base);
void		init_philos(t_base *base);
void		init_mutexes(t_base *base);
void		init_philos_thread(t_base *base);

//lifecycle.c --> OK
void		*lifecycle(void *arg);
void		*lifecycle_checker(void *arg);

//philo.c --> OK
void		philosophers(int ac, char **av, t_base *base);

//utils.c
uint64_t	get_time(void);
void		check_args_values(t_base *base);
void		write_command(uint64_t time, t_philo *philo, t_state state);
void		destroy_all_mutexes(t_base *base);
void		destory_all_threads(t_base *base);

#endif