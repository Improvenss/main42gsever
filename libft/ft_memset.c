/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:36:05 by gsever            #+#    #+#             */
/*   Updated: 2022/02/05 23:43:34 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//byte dizeye byte yaziyoruz. "gorkem" --> "aaaaem"
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter <= n)
	{
		*(char *)(s + (sizeof(char) * counter)) = (char)c;
		counter++;
	}
	return (s);
}

int	main()
{
	char	arr1[] = {'d', 'p', '3'};
	char	arr2[] = {'0', '1', '1'};
	char	ppu[] = "gorkem";

	memset(arr1, 97, 2);
	ft_memset(arr2, 97, 2);
	printf("ORIGINAL: {%c, %c, %c}\n", arr1[0], arr1[1], arr1[2]);
	printf("MY FUNC: {%c, %c, %c}\n", arr2[0], arr2[1], arr2[2]);
	printf("ft_:%s", ft_memset(ppu, 97, 4));
}