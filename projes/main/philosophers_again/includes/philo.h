/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:16:28 by gsever            #+#    #+#             */
/*   Updated: 2022/08/28 18:50:56 by gsever           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_base	t_base;

typedef struct s_philo
{
	t_base				*base;
	pthread_t			th_id;
	int					id;
	int					fork_l;
	int					fork_r;
	int					eat_count;
	unsigned long long	last_eat_time;
	bool				full;
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
	bool			is_running;
}		t_base;

/********* FUNCTION PROTOTYPES ********/

//philo.c
void	check_args(int ac, char **av, t_base *base);
void	init_args(int ac, char **av, t_base *base);
void	init_philos(t_base *base);
void	philosophers(int ac, char **av, t_base *base);

//error.c
void	ft_perror(char *str);

#endif
