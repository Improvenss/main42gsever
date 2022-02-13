/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:52:35 by gsever            #+#    #+#             */
/*   Updated: 2021/12/14 17:34:24 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
NULLint	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	len = max - min;
	*range = (int *)malloc(len * sizeof(int));
	if (!*range)
		return (-1);
	while (min < max)
	{
		*range[i] = min ;
		min++;
		i++;
	}
	return (len);
}

#include <stdio.h>
int	main()
{
	int *a;
	int size = ft_ultimate_range(&a, 5, 10);
	int i = 0;
	while(i < size)
	{
		printf("%d\n", a[i]);
		i++;
	}
}

/*{
	{1, 2, 3, 4, 5};
}*/
