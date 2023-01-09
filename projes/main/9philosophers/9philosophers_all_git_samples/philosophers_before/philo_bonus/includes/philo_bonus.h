/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:33:22 by gsever            #+#    #+#             */
/*   Updated: 2022/09/08 19:53:57 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file philo_bonus.h
 * @brief Library for 'philosophers' project.
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

//	STANDARD LIBRARY INCLUDES
# include <unistd.h> /*
	write()		-> System call used to write data from the buffer,
	fork()		-> Create thread from process.
	usleep()	-> Waiting program to microseconds type's. */
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
# include <sys/wait.h> /*
	waitpid()	-> Wait the process termination.
		pid_t waitpid(pid_t pid, int *stat_loc, int options);
https://www.ibm.com/docs/en/i/7.4?topic=ssw_ibm_i_74/apis/waitpid.htm */
# include <sys/time.h> /*
	gettimeofday() */
# include <pthread.h> /*Mendatory part:
	pthread_create() -> Create process for one function,
	pthread_detach() -> Thread'la isimiz bittiginde bunu geri ,
	pthread_join()	 -> p_create ile gorevlendigimiz thread'i calistirmaya yariyor.
	 */
# include <semaphore.h> /* Bonus part:
	sem_open()	 -> Initialize and open a named semaphore.
		sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int value);
https://www.ibm.com/docs/en/i/7.1?topic=ssw_ibm_i_71/apis/ipcsemo.htm
	sem_close()	 -> Close a named semaphore.
		int sem_close(sem_t *sem);
https://www.ibm.com/docs/en/i/7.1?topic=ssw_ibm_i_71/apis/ipcsemcl.htm
	sem_post()	 -> Unlock a semaphore. -> V(sem)
		int sem_post(sem_t *sem);
https://www.ibm.com/docs/en/i/7.1?topic=ssw_ibm_i_71/apis/ipcsemp.htm
	sem_wait()	 -> Lock a semaphore. -> P(sem)
		int sem_wait(sem_t *sem);
https://www.ibm.com/docs/en/i/7.1?topic=ssw_ibm_i_71/apis/ipcsemw.htm
	sem_unlink() -> Remove a named semaphore.
		int sem_unlink(const char *name);
https://www.ibm.com/docs/en/i/7.1?topic=ssw_ibm_i_71/apis/ipcsemun.htm */

//	ACTIONS --> 🍽 💤 💭 🍴 💀
# define STR_EAT		"\033[0;32mis eating\033[m"
# define STR_SLEEP		"\033[0;34mis sleeping\033[m"
# define STR_THINK		"\033[0;33mis thinking\033[m"
# define STR_TOOK_FORK	"has taken a fork"
# define STR_DEAD		"\033[0;31mdied\033[m"

//	SEMAPHORE CREATED NAME
# define SEM_FORK		"/sem_forks"
# define SEM_WRITE		"/sem_write"
# define SEM_DIED		"/sem_died"
# define SEM_FINISH		"/sem_finish"

//	COLORS --> 🟥 🟩 🟦
# define CYAN		"\033[0;36m"
# define BLUE		"\033[0;34m"
# define YELLOW		"\033[0;33m"
# define GREEN		"\033[0;32m"
# define RED		"\033[0;31m"
# define RESET		"\033[0m"
# define X			"\033[m"

//	COLORS BOLD--> B🟥 B🟩 B🟦
# define B_CYAN		"\033[1;36m"
# define B_BLUE		"\033[1;34m"
# define B_YELLOW	"\033[1;33m"
# define B_GREEN	"\033[1;32m"
# define B_RED		"\033[1;31m"
# define B_RESET	"\033[1m"

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
 * @param base*		OK:	Main event BRUH.
 * @param id			OK:	Philosopher's turn id.
 * @param eat_count		OK:	How many times eated.
 * @param last_eat_time	OK:	Elapsed time since the philosopher last ate.
 */
typedef struct s_philos
{
	t_base		*base;
	int			id;
	int			eat_count;
	uint64_t	last_eat_time;
}		t_philos;

/**
 * @brief This struct for main cycle.
 * @param philos*		OK:	Creates a Philosopher.
 * @param checker			Checker's thread.
 * @param sem_forks*		The philo's count forks.
 * @param sem_write*		Write command's semaphore.
 * @param sem_done*			If finished eating or died philosopher.
 * @param philos_pid*		Holding in array philosopher's pid number.
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
	t_philos	*philos;
	pthread_t	checker;
	sem_t		*sem_forks;
	sem_t		*sem_write;
	sem_t		*sem_done;
	pid_t		*philos_pid;
	int			philos_count;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	uint64_t	start_time;
	bool		is_running;
}		t_base;

/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

//actions_bonus.c
void		leave_forks_b(t_philos *philos);
void		take_forks_b(t_philos *philos);
void		philo_sleep_b(t_philos *philos);
void		philo_eat_b(t_philos *philos);
void		philo_think_b(t_philos *philos);

//check_args_bonus.c
void		check_args_in_values_b(t_base *base);
void		check_args_on_shell_b(int ac, char **av);
void		check_args_b(int argc, char **argv);

//destroy_bonus.c
void		destroy_semaphores_b(void);
void		destroy_pids_b(t_base *base);
void		destroy_all_b(t_base *base);

//error_bonus.c
int			ft_perror_b(char *str);

//ft_atoi.c
int			ft_atoi(const char *nptr);

//get_time_bonus.c
uint64_t	get_current_time_b(t_base *base);

//init_all_bonus.c
void		init_philo_process_b(t_base *base);
void		init_semaphore_b(t_base *base);
void		init_philo_b(t_base *base);
void		init_args_b(int ac, char **av, t_base *base);

//lifecycle_bonus.c
void		*control_philos_b(void *arg);
void		*lifecycle_checker_b(void *arg);
void		lifecycle_b(t_philos *philos);

//philo_bonus.c
void		philo_bonus(int argc, char **argv, t_base *base);

//write_command_bonus.c
void		write_command_b(uint64_t time, t_philos *philos, t_state state);

#endif