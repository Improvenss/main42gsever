/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:39:04 by gsever            #+#    #+#             */
/*   Updated: 2022/12/02 20:40:43 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*map_split_stringfind(const char *s, char c, int max)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(sizeof(char) * (max + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c && s[i] != '\r')
	{
		temp[i] = s[i];
		i++;
	}
	while (i < max)
	{
		temp[i] = ' ';
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

size_t	map_split_wordcount(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		count++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

char	**map_split(char *line, char c, int max)
{
	char	**temp;
	int		wordc;
	int		i;

	i = 0;
	if (!line)
		return (NULL);
	wordc = map_split_wordcount(line, c);
	temp = (char **)malloc(sizeof(char *) * (wordc + 1));
	if (!temp)
		return (NULL);
	while (*line)
	{
		while (*line && *line == c)
			line++;
		if (*line)
		{
			temp[i] = map_split_stringfind(line, c, max);
			i++;
		}
		while (*line && *line != c)
		line++;
	}
	temp[i] = NULL;
	return (temp);
}
