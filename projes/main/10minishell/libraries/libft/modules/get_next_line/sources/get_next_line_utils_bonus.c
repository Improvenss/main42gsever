/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:01:38 by gsever            #+#    #+#             */
/*   Updated: 2022/07/29 00:13:16 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

// size_t	ft_strlen_gnl(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strchr_gnl(const char *s, int c)
// {
// 	int	s_len;

// 	if (!s)
// 		return (0);
// 	s_len = ft_strlen_gnl(s);
// 	while (s_len >= 0)
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		s++;
// 		s_len--;
// 	}
// 	return (NULL);
// }

// char	*ft_strjoin_gnl(char *s1, char *s2)
// {
// 	unsigned int	i;
// 	unsigned int	j;
// 	char			*s3;

// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(1 * sizeof(char));
// 		s1[0] = '\0';
// 	}
// 	if (!s1 || !s2)
// 		return (NULL);
// 	s3 = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
// 	if (!s3)
// 		return (NULL);
// 	i = -1;
// 	while (s1[++i] != 0)
// 		s3[i] = s1[i];
// 	j = -1;
// 	while (s2[++j] != 0)
// 	{
// 		s3[i + j] = s2[j];
// 	}
// 	s3[i + j] = 0;
// 	free(s1);
// 	return (s3);
// }
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
