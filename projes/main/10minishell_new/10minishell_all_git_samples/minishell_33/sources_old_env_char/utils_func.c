/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:31:10 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/21 22:24:35 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*find_max_str(char **data)
{
	char	*max;
	int		i;

	i = 0;
	max = data[0];
	while (data[i])
	{
		if (ft_strcmp_edited(max, data[i]) > 0)
		{
			max = data[i];
		}
		i++;
	}
	return (max);
}

char	*find_min_str(char **data)
{
	int		i;
	char	*min;

	i = 0;
	min = data[0];
	while (data[i])
	{
		if (ft_strcmp_edited(min, data[i]) < 0)
			min = data[i];
		i++;
	}
	return (min);
}

char	*str_add(char *tmp, char *str)
{
	char *mem_1;
	char *mem_2;

	mem_1 = ft_strjoin(str, "\n");
	if (tmp == NULL)
		return (mem_1);
	mem_2 = ft_strjoin(tmp, mem_1);
	free(mem_1);
	if (tmp != NULL)
		free(tmp);
	return (mem_2);
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

/**
 * @brief Ahmet's edited code.
 * 
 * @note Line(46) "(s1[n] == ' ' || s1[n] == '\0')" cd .. <enter> durumu,
 * 	cd.. <enter> şeklinde kullanılmasını engellemek için konuldu.
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
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
	if (n == 0 && s1[n] == '\0')//(s1[n] == ' ' || s1[n] == '\0'))
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
