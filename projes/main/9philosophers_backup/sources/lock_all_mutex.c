/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_all_mutex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:13:24 by gsever            #+#    #+#             */
/*   Updated: 2022/08/17 12:43:50 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	lock_all_mutex(t_base *base)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < base->philos_count)
// 	{
// 		pthread_mutex_lock(&base->philos[i])
// 	}
// }