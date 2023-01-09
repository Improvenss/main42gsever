/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:38:42 by gsever            #+#    #+#             */
/*   Updated: 2022/09/02 12:59:59 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	init_philos_thread(t_base *base)
{
	int			i;
	pthread_t	lifecycle_id;

	i = -1;
	while (++i < base->number_of_philo)
		pthread_create(&base->philo[i].th_id, NULL,
			&lifecycle, (void *)&base->philo[i]);
	i = -1;
	while (++i < base->number_of_philo)
		pthread_join(base->philo[i].th_id, NULL);
	pthread_create(&lifecycle_id, NULL, &lifecycle_checker, NULL);
	pthread_join(lifecycle_id, NULL);
}

void	init_mutexes(t_base *base)
{
	int	i;

	i = -1;
	while (++i < base->number_of_philo)
		pthread_mutex_init(&base->fork[i], NULL);
	pthread_mutex_init(&base->write, NULL);
}

void	init_philos(t_base *base)
{
	int		i;

	base->philo = malloc(sizeof(t_philo) * base->number_of_philo);
	base->fork = malloc(sizeof(pthread_mutex_t) * base->number_of_philo);
	i = -1;
	while (++i < base->number_of_philo)
	{
		base->philo[i].base = base;
		base->philo[i].id = i + 1;
		base->philo[i].fork_l = i;
		base->philo[i].fork_r = (i + 1) % base->number_of_philo;
		base->philo[i].eat_count = 0;
		base->philo[i].last_eat_time = 0;
		base->philo[i].full = false;
	}
}

void	init_args(int ac, char **av, t_base *base)
{
	check_args(ac, av);
	base->number_of_philo = atoi(av[1]);
	base->time_to_die = atoi(av[2]);
	base->time_to_eat = atoi(av[3]);
	base->time_to_sleep = atoi(av[4]);
	base->must_eat_count = -1;
	base->is_running = true;
	if (ac == 6)
		base->must_eat_count = atoi(av[5]);
	check_args_values(base);
	base->prog_start_time = get_time();
}
