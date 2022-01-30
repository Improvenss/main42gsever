/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeskin <ekeskin@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:30:50 by ekeskin           #+#    #+#             */
/*   Updated: 2021/12/14 13:57:30 by ekeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;
	int		e;

	i = 0;
	e = 0;
	while (src[i] != '\0')
		i++;
	p = (char *)malloc(sizeof(char) * i);
	while (src[e] != '\0')
	{
		p[e] = src[e];
		e++;
	}
	p[e] = '\0';
	return (p);
}
