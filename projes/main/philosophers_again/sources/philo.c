/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:30:41 by gsever            #+#    #+#             */
/*   Updated: 2022/08/31 13:56:33 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(void)
{
	struct timeval	ct;

	gettimeofday(&ct, NULL);
	return (ct.tv_sec * (unsigned long long)1000 + ct.tv_usec / 1000);
}

void	check_args_values(t_base *base)
{
	if (base->number_of_philo > 200)
		ft_perror("200'den fazla philosophers olamaz kardes\n");
	else if (base->time_to_die < 60 || base->time_to_eat < 60
		|| base->time_to_sleep < 60)
		ft_perror("zamanlarin 60'dan kucuk olamaz\n");
}

void	init_args(int ac, char **av, t_base *base)
{
	if (ac == 5 || ac == 6)
	{
		base->number_of_philo = atoi(av[1]);
		base->time_to_die = atoi(av[2]);
		base->time_to_eat = atoi(av[3]);
		base->time_to_sleep = atoi(av[4]);
		base->must_eat_count = -1;
		base->is_running = true;
		if (ac == 6)
			base->must_eat_count = atoi(av[5]);
		check_args_values(base);
	}
	else
	{
		printf("argumanlarini kontrol et\n");
		ft_perror("Error\n");
	}
}

void	init_philos(t_base *base)
{
	int		i;

	base->philo = malloc(sizeof(t_philo));
	base->fork = malloc(sizeof(fork));
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
		printf("philo[%d] id -> %d -> left fork -> %d\n", i, base->philo[i].id, base->philo[i].fork_l);
		printf("philo[%d] id -> %d\n", i, base->philo[i].id);
		printf("philo[%d] id -> %d -> right fork -> %d\n\n", i, base->philo[i].id, base->philo[i].fork_r);
	}
}

void	init_mutexes(t_base *base)
{
	int	i;

	i = -1;
	while (++i < base->number_of_philo)
	{
		pthread_mutex_init(&base->fork[i], NULL);
		printf("%d. mutex(fork) init edildi.\n", i);
	}
	pthread_mutex_init(&base->write, NULL);
	printf("WRITE mutex init edildi.\n\n");
}

void	write_command(uint64_t time, t_philo *philo, t_state state)
{
	const char	*actions[5] = {STR_EAT, STR_SLEEP, STR_THINK,
		STR_TOOK_FORK, STR_DEAD};
	
	printf("%llu %d %s\n", time, philo->id, actions[state]);
}

void	*lifecycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
//	printf("%d philo is working\n", philo->id);
	action_think(philo);
	return (NULL);
}

void	init_philos_thread(t_base *base)
{
	int			i;
//	pthread_t	lifecycle_id;

	i = -1;
	while (++i < base->number_of_philo)
	{
		pthread_create(&base->philo[i].th_id, NULL, &lifecycle, (void *)&base->philo[i]);
//		pthread_join(base->philo[i].th_id, NULL);
	}
	//i = -1;
	//while (++i < base->number_of_philo)
//		pthread_join(base->philo[i].th_id, NULL);
}

void	philosophers(int ac, char **av, t_base *base)
{
	init_args(ac, av, base);
	printf("		******* init_args(ac, av, base); okay *******\n\n");
	init_philos(base);
	printf("		******* init_philos(base); okay *******\n\n");
	init_mutexes(base);
	printf("		******* init_mutexes(base); okay *******\n\n");
	init_philos_thread(base);
}
