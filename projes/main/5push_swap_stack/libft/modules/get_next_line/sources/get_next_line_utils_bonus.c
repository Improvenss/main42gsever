/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:01:38 by gsever            #+#    #+#             */
/*   Updated: 2022/08/01 20:21:09 by gsever           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

char	*ft_strchr_ch(char *save, int c)
{
	int	i;

	i = 0;
	if (!save)
		return (0);
	while (save[i] != '\0')
	{
		if (save[i] == (char)c)
			return ((char *)&save[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen_ch(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
