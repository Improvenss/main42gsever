/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:52:09 by gsever            #+#    #+#             */
/*   Updated: 2021/12/15 18:25:41 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	i;
	int	*me;

	if (min >= max)
	{
		return (me = NULL);
	}
	i = 0;
	range = max - min;
	me = (int *)malloc(range * sizeof(int));
	if (me == NULL)
		return (0);
	while (min < max)
	{
		me[i] = min ;
		min++;
		i++;
	}
	return (me);
}
/*
int main()
{
	int	min;
	int	max;
	int	*tab;
	int	i = 0;
	int	size;

	min = 5;
	max = 10;
	size = max - min;
	tab = ft_range(min, max);
	while(i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
}
*/
