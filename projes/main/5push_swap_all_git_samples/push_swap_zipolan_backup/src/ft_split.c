/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:29:46 by bbourcy           #+#    #+#             */
/*   Updated: 2022/04/25 18:30:02 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static size_t	ft_countline(const char *s, char c)
{
	size_t	i;
	size_t	nline;

	i = 0;
	nline = 0;
	if (s[0] != c)
		nline++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i] != '\0')
		{
			i++;
			nline++;
		}
		else if (s[i] != c && s[i + 1] == '\0')
		{
			nline++;
			i++;
		}
		else
			i++;
	}
	return (nline);
}

static size_t	ft_countchar(const char *s, char c, size_t i)
{
	size_t	nchar;
	size_t	n;

	n = i;
	nchar = 0;
	while (s[n] == c)
		n++;
	while (s[n] != c && s[n] != '\0')
	{
		n++;
		nchar++;
	}
	return (nchar);
}

static char	**ft_fillt(const char *s, char c, char **dst)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	line;

	i = 0;
	j = 0;
	k = 0;
	line = ft_countline(s, c);
	while (k + 1 < line)
	{
		dst[k] = (char *)malloc(ft_countchar(s, c, i) + 1);
		if (!dst[k])
			return (NULL);
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
			dst[k][j++] = s[i++];
		dst[k++][j] = '\0';
		j = 0;
		i++;
	}
	dst[k] = ((void *)0);
	return (dst);
}

char	**ft_split(const char *s, char c)
{
	char	**dst;
	size_t	line;

	if (!s)
		return (NULL);
	line = ft_countline(s, c);
	dst = (char **)malloc(line * sizeof(char *));
	if (!dst)
		return (NULL);
	dst = ft_fillt(s, c, dst);
	return (dst);
}
