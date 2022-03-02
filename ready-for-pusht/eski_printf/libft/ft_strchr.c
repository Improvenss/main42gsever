/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:36:42 by gsever            #+#    #+#             */
/*   Updated: 2022/02/10 17:44:35 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int olarak aramak istedigimiz karakteri unsigned chara cevirir ve 
aradigimiz karakter dahil olmak uzere devamini dondurur.
not: pontirini return ederek r ve geri kalanina ulasabiliyoruz.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
/*
int	main()
{
	char a[] = "gorkem";
	
	printf("ft_:%s", ft_strchr(a, 'r'));
}
*/