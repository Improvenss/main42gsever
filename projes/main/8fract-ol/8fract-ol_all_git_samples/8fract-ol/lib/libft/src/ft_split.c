/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:36:45 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/23 18:14:25 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_db(char **db_array)
{
	size_t	i;

	i = 0;
	while (db_array[i] != NULL)
	{
		free(db_array[i]);
		i++;
	}
	free(db_array);
	return (NULL);
}

static int	ft_count_strs(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static size_t	ft_count_sep(char const *s, char c)
{
	size_t	sep_count;

	sep_count = 0;
	while (s[sep_count] == c && s[sep_count] != '\0')
		sep_count++;
	return (sep_count);
}

static size_t	ft_count_chr(char const *s, char c)
{
	size_t	chr_count;

	chr_count = 0;
	while (s[chr_count] != c && s[chr_count] != '\0')
		chr_count++;
	return (chr_count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	offset;
	size_t	chr_count;
	char	**str_array;

	if (s == NULL)
		return (NULL);
	str_array = malloc((ft_count_strs(s, c) + 1) * sizeof(char *));
	if (str_array == NULL)
		return (NULL);
	i = 0;
	offset = 0;
	while (offset < ft_strlen(s))
	{
		offset += ft_count_sep(&s[offset], c);
		chr_count = ft_count_chr(&s[offset], c);
		if (chr_count == 0)
			break ;
		str_array[i] = ft_substr(s, offset, chr_count);
		if (str_array[i++] == NULL)
			return (ft_free_db(str_array));
		offset += chr_count;
	}
	str_array[i] = NULL;
	return (str_array);
}
