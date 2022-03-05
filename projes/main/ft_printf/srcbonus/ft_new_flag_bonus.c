/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:28:09 by gsever            #+#    #+#             */
/*   Updated: 2022/03/05 18:55:36 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flags	ft_newflags(void)
{
	t_flags	newflags;

	newflags.minus = 0;
	newflags.zero = 0;
	newflags.dot = 0;
	newflags.hashtag = 0;
	newflags.space = 0;
	newflags.plus = 0;
	newflags.width = 0;
	return (newflags);
}
