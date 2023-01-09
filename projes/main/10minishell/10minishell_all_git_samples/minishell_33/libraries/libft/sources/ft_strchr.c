/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:36:42 by gsever            #+#    #+#             */
/*   Updated: 2022/10/14 10:33:55 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
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