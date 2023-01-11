/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:35:56 by akaraca           #+#    #+#             */
/*   Updated: 2022/03/15 13:17:20 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gn(char *save)
{
	int	i;

	i = 0;
	if (!save)
		return (0);
	while (save[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gn(char *save, int c)
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

char	*ft_strjoin_gn(char *save, char *buffer)
{
	char	*temp;
	int		i;
	int		l;

	if (!save)
	{
		save = (char *)malloc(sizeof(char) * 1);
		save[0] = '\0';
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen_gn(save) +\
				ft_strlen_gn(buffer) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (save[i] != '\0')
	{
		temp[i] = save[i];
		i++;
	}
	l = 0;
	while (buffer[l] != '\0')
		temp[i++] = buffer[l++];
	temp[i] = '\0';
	free(save);
	return (temp);
}
