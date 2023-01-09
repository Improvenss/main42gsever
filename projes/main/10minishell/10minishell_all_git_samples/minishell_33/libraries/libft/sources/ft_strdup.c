/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:36:47 by gsever            #+#    #+#             */
/*   Updated: 2022/10/23 21:53:32 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//istenilen string kadar malloc'ta yer ayirior, string'i icine koyup return edio

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (*src)
		dst[i++] = *((char *)src++);
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*ret;

	ret = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret)
		ft_strcpy(ret, s);
	return (ret);
}

/*
int	main()
{
	char *a = "gorkem sever";

	printf("ft_:%s|\n", ft_strdup(a));
}
*/
