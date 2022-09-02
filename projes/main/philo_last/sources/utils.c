/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:48:27 by gsever            #+#    #+#             */
/*   Updated: 2022/09/01 17:24:30 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(void)
{
	struct timeval	ct;

	gettimeofday(&ct, NULL);
	return (ct.tv_sec * (unsigned long long)1000 + ct.tv_usec / 1000);
}

// void	check_args_values(t_base *base)
// {
// 	if (base->number_of_philo > 200)
// 		ft_perror("200'den fazla philosophers olamaz kardes\n");
// 	else if (base->time_to_die < 60 || base->time_to_eat < 60
// 		|| base->time_to_sleep < 60)
// 		ft_perror("zamanlarin 60'dan kucuk olamaz\n");
// }

void	write_command(uint64_t time, t_philo *philo, t_state state)
{
	const char	*actions[5] = {STR_EAT, STR_SLEEP, STR_THINK,
		STR_TOOK_FORK, STR_DEAD};

	printf("%llu %d %s\n", time, philo->id, actions[state]);
}

/**
 * @brief Destroying and freeing all used mutexes.
 * 
 * @param base 
 * @fn pthread_mutex_destroy()	:
 * @fn free()					:
 * @return void
 */
void	destroy_all_mutexes(t_base *base)
{
	int	i;

	i = -1;
	while (++i < base->number_of_philo)
		pthread_mutex_destroy(&base->fork[i]);
	free(base->fork);
}

/**
 * @brief Destroying and freeing all used threads.
 * 
 * @param base 
 * @fn pthread_detach()	:
 * @fn free()			:
 * @return void
 */
void	destory_all_threads(t_base *base)
{
	int	i;

	i = -1;
	while (++i < base->number_of_philo)
		pthread_detach(base->philo[i].th_id);
	free(base->philo);
}
