/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:37:31 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:18:43 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//strchr.c'nin tersi. sondan baslayarak geriye dogru taramaya basliyor.
char	*ft_strrchr(const char *s, int c)
{
	char	*start;

	start = (char *)s;
	while (*s)
		s++;
	while (s >= start)
	{
		if (*((char *)s) == (char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
/*
int	main()
{
	char a[] = "gorkem";

	printf("ft_:%s", ft_strrchr(a, 'k'));
}
*/