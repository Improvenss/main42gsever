/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:33:22 by gsever            #+#    #+#             */
/*   Updated: 2022/09/07 16:58:03 by gsever           ###   ########.fr       */
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
// # include <semaphore.h> /* Bonus part:
// 	sem_open(),
// 	sem_close(),
// 	sem_post(),
// 	sem_wait(),
// 	sem_unlink() */

//	ACTIONS --> 🍽 💤 💭 🍴 💀
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
/* STRUCT DEFINES AREA													  	  */
/* ************************************************************************** */

typedef struct s_base	t_base;
typedef struct s_philo	t_philo;

/**
 * @brief Holding number, number is actions.
 */
typedef enum s_state
{
	EAT,
	SLEEP,
	THINK,
	TOOK_FORK,
	DEAD
}		t_state;

/**
 * @brief This struct for just one philosopher.
 * @param common*		OK:	Main event BRUH.
 * @param th_id			OK:	Philosopher's thread id.
 * @param id			OK:	Philosopher's turn id.
 * @param fork_l		OK:	Left fork.
 * @param fork_r		OK:	Right fork.
 * @param eat_count		OK:	How many times eated.
 * @param last_eat_time	OK:	Elapsed time since the philosopher last ate.
 * @param full_count		
 * @param full				Is finished one cycle(dongu)-> eat -> sleep -> think.
 */
typedef struct s_philos
{
	t_base		*common;
	pthread_t	th_id;
	int			id;
	int			fork_l;
	int			fork_r;
	int			eat_count;
	uint64_t	last_eat_time;
	bool		full;
}		t_philos;

/**
 * @brief This struct for main cycle.
 * @param philos*		OK:	Creates a Philosopher.
 * @param fork*			: Mutexs.
 * @param philos_count	OK: The amount of philosophers we have.
 * @param time_to_die	OK: The time the philosophers take to die.
 * @param time_to_eat	OK: The time the philosophers take to eat.
 * @param time_to_sleep	OK: The time the philosophers take to sleep.
 * @param must_eat		OK: Cycle count --> Must eat count.
 * @param start_time	OK: When start ./philosophers -> starting timer.
 * @param is_running	OK: If program running(philo not die/not eat count)
 */
typedef struct s_base
{
	t_philos		*philos;
	pthread_mutex_t	*fork;
	pthread_mutex_t	write;
	int				philos_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				full_count;
	int				start_time;
	bool			is_running;
}		t_base;

/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

//actions.c --> OK
void		leave_forks(t_philos *philos);
void		take_forks(t_philos *philos);
void		philo_sleep(t_philos *philos);
void		philo_eat(t_philos *philos);
void		philo_think(t_philos *philos);

//check_args.c --> OK
void		check_args_in_values(t_base *base);
void		check_args_on_shell(int ac, char **av);
void		check_args(int argc, char **argv);

//destroy.c --> OK
void		destroy_mutexes(t_base *base);
void		destory_threads(t_base *base);

//error.c --> OK
int			ft_perror(char *str);

//ft_atoi.c --> OK
int			ft_atoi(const char *nptr);

//get_time.c
uint64_t	get_current_time(void);

//init_all.c --> OK
void		init_philo_thread(t_base *base);
void		init_mutex(t_base *base);
void		init_philo(t_base *base);
void		init_args(int ac, char **av, t_base *base);

//lifecycle.c
void		*lifecycle_checker(void *arg);
void		*lifecycle(void *arg);

//philosophers.c --> OK
void		philosophers(int argc, char **argv, t_base *base);

#endif
