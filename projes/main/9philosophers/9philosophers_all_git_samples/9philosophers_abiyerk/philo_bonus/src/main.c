/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:53:54 by aeser             #+#    #+#             */
/*   Updated: 2022/09/07 17:05:39 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_env	env;

	init_arguments(argc, argv, &env);
	init_semaphore(&env);
	init_philos(&env);
	init_philo_process(&env);
	pthread_create(&env.checker, NULL, checker_function, &env);
	pthread_detach(env.checker);
	sem_wait(env.sem_done);
	destroy(&env);
}
