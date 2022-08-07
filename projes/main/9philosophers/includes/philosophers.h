/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:33:22 by gsever            #+#    #+#             */
/*   Updated: 2022/08/07 23:34:37 by gsever           ###   ########.fr       */
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
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <errno.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/time.h>
# include <pthread.h>

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

typedef struct s_base t_base;

/**
 * @brief This struct for just one philosopher.
 * @param eat_count		: How many times eated.
 * @param full			: Is finished one cycle(dongu). --> eat -> sleep -> think.
 * @param last_eat_time	: Elapsed time since the philosopher last ate.
 * @param common*		: Main event BRUH.
 */
typedef	struct	s_philos
{
	t_base	*common;
	int		eat_count;
	int		full;	
	long	last_eat_time;
}		t_philos;

/**
 * @brief This struct for main cycle.
 * @param philos*		: Creates a Philosopher.
 * @param philos_count	: The amount of philosophers we have.
 * @param time_to_die	: The time the philosophers take to die.
 * @param time_to_eat	: The time the philosophers take to eat.
 * @param time_to_sleep	: The time the philosophers take to sleep.
 * @param dead_time		: The time the philosophers take to death.
 * @param must_eat		: Cycle count --> Must eat count.
 * @param total_full	:
 * 
 */
typedef	struct	s_base
{
	// t_philos	*philos;
	int			philos_count;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	// int			dead_time;
	int			must_eat;
	// int			total_full;
}		t_base;


/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

//check_args.c
void	check_args_in_values(int ac, char **av, t_base *base);
void	check_args_on_shell(int ac, char **av);
void	check_args(int argc, char **argv, t_base *base);

//error.c
int		ft_perror(char *str);

//init_args.c
void	init_args(int ac, char **av, t_base *base);

//philosophers.c
void	philosophers(int argc, char **argv, t_base *base);

#endif
