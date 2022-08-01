/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:14:59 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:16:42 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//mallocla yer ayirdiktan sonra \0 'la dolduruyor "null"la yani
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	ret = malloc(nmemb * size);
	if (ret)
		ft_bzero(ret, nmemb * size);
	return (ret);
}
/*
2x2=4byte olacagi icin, 4 kere while'ye soktuk
int	main()
{
	int *ptr;
	int *ft_p;
	int i;
	int j;

	ft_p = (int *)ft_calloc(2, 2);

	ptr = (int *)calloc(2, 2);

	i = 0;
	while (i < 5)
	{
		printf("org_addres:%p | org_value:%i\n", (ptr + i), *(ptr + i));
		i++;
	}

	j = 0;
	while (j < 5)
	{
		printf("ft_addres:%p | ft_value:%i\n", (ft_p + j), *(ft_p + j));
		j++;
	}
}
*/