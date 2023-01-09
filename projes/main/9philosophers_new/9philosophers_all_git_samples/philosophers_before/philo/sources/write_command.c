/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:39:07 by gsever            #+#    #+#             */
/*   Updated: 2022/09/08 19:48:11 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_actions(uint64_t time, t_philos *philos, t_state state)
{
	const char	*actions[6] = {STR_EAT, STR_SLEEP, STR_THINK,
		STR_TOOK_FORK, STR_DEAD, NULL};

	if (!philos->common->is_running)
		return ;
	pthread_mutex_lock(&philos->common->write);
	printf("%llu %d %s\n", time, philos->id, actions[state]);
	pthread_mutex_unlock(&philos->common->write);
}
