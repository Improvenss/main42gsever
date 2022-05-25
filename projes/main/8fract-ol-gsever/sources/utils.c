/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:07:49 by gsever            #+#    #+#             */
/*   Updated: 2022/05/25 17:09:36 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		return (ft_strcmp(s1, s2) ? 0 : 1);
	return (0);
}
