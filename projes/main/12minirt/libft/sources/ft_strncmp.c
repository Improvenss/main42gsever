/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:37:24 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:18:38 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//comparing n times, if find different doing s1 - s2 = int. Bu ne bicm ing
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	if (n == 0)
		return (0);
	counter = 0;
	while (counter < (n - 1) && s1[counter] && s2[counter])
	{
		if (s1[counter] != s2[counter])
			break ;
		counter++;
	}
	return (((unsigned char *)s1)[counter] - ((unsigned char *)s2)[counter]);
}
/*
//this s1-s2=109 -> m-0=m=109 -----> 0 = NULL
int	main()
{
	char a[] = "1234";
	char b[] = "12345";
	int result;

	result = ft_strncmp(a, b, 4);
	if(result < 0)
		printf("s1 > s2 output:%d\n", result);
	else if (result > 0)
		printf("s1 < s2 output:%d\n", result);
	else
		printf("s1 = s2 output:%d\n", result);
}
*/