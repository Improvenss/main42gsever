/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:41:47 by gsever            #+#    #+#             */
/*   Updated: 2022/12/02 19:42:50 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_pstr(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		free(line[i++]);
	}
	free(line);
}

char	*ft_chrjoin(char *s1, char c)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = c;
	i++;
	tmp[i] = '\0';
	return (tmp);
}

int	ft_strncmp_edited(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1 && (*s1 != '\0') && (*s1 == *s2) && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0 && s1[n] == '\0')
		return (1);
	return (0);
}

int	ft_strcmp_edited(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
