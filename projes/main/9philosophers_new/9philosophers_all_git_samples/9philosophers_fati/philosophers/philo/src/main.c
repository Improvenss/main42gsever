/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:11:36 by fcil              #+#    #+#             */
/*   Updated: 2022/06/15 12:58:11 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(int ac, char **av, t_env *env)
{
	env->number_of_philo = ft_atoi(av[1]);
	env->time_to_die = ft_atoi(av[2]);
	env->time_to_eat = ft_atoi(av[3]);
	env->time_to_sleep = ft_atoi(av[4]);
	env->must_eat = -1;
	if (ac == 6)
		env->must_eat = ft_atoi(av[5]);
	if (env->time_to_die < 60 || env->time_to_eat < 60
		|| env->time_to_sleep < 60)
	{
		printf("Arguments cannot be smaller than 60ms\n");
		exit(-1);
	}
	if (env->number_of_philo > 200)
	{
		printf("Error: Philosopher count cannot be higher than 200\n");
		exit(-1);
	}
	env->start_time = get_time_ms();
	env->is_running = true;
}

void	init_philo(t_env *env)
{
	int	i;

	env->philos = malloc(sizeof(t_philo) * env->number_of_philo);
	env->chopsticks = malloc(sizeof(pthread_mutex_t) * env->number_of_philo);
	i = -1;
	while (++i < env->number_of_philo)
	{
		env->philos[i].id = i + 1;
		env->philos[i].chopstick_l = i;
		env->philos[i].chopstick_r = (i + 1) % env->number_of_philo;
		env->philos[i].count_eat = 0;
		env->philos[i].last_eat = 0;
		env->philos[i].env = env;
		env->philos[i].done = false;
	}
}

void	init_threads(t_env *env)
{
	int			i;
	pthread_t	life_cycle_id;

	i = -1;
	while (++i < env->number_of_philo)
	{
		pthread_create(&env->philos[i].th_id, NULL,
			life_cycle, (void *)&env->philos[i]);
	}
	pthread_create(&life_cycle_id, NULL, &life_cycle_checker, env);
	pthread_join(life_cycle_id, NULL);
}

void	init_mutexes(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->number_of_philo)
	{
		pthread_mutex_init(&env->chopsticks[i], NULL);
	}
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac < 5 || ac > 6)
	{
		printf("Usage: ./philo number_of_philo ");
		printf("time_to_die time_to_eat time_to_sleep must_eat\n");
		exit(-1);
	}
	init(ac, av, &env);
	init_philo(&env);
	init_mutexes(&env);
	init_threads(&env);
	destroy_threads(&env);
	destroy_mutexes(&env);
	return (0);
}
