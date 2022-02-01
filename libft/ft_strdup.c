/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:35:48 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/02/01 15:45:34 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function dupplicates the string that is passed.
 * And return a pointer to the copied string.
 */

char	*ft_strdup(const char *s1)
{
	size_t	s_len;
	char	*p;
	char	*pointer;

	s_len = ft_strlen(s1) + 1;
	p = (char *)ft_calloc(s_len, sizeof(char));
	if (!p)
		return (NULL);
	pointer = p;
	ft_strlcpy(p, s1, s_len);
	return (pointer);
}
