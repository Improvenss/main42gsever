/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:36:05 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:50 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//byte dizeye byte yaziyoruz. "gorkem" --> "aaaaem"
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		*(char *)(s + (sizeof(char) * counter)) = (char)c;
		counter++;
	}
	return (s);
}
/*
#include <string.h>
int	main()
{
	char	arr1[] = {'d', 'p', '3'};
	char	arr2[] = {'d', 'p', '3'};
	char	ppu[] = "gorkem";
	int i = 0;
	
	memset(arr1, 97, 2);
	ft_memset(arr2, 97, 2);
	while(arr1[i])
		printf("ft_:%c\n", arr1[i++]);
	printf("ft_:%s\n", ft_memset(ppu, 97, 4));
}
*/