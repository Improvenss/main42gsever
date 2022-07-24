/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:04:11 by gsever            #+#    #+#             */
/*   Updated: 2022/07/01 20:11:57 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief	Finding stack's MIN number.
 * @return	Minimum number.
 * @bug		Not know bugs.
 */
int	find_min(int size, t_base *base)
{
	int	i;
	int	min;

	i = 0;
	printf("find_min func geldik. while'ye girecegiz. i=0 dan size'ye kadar gidecek dongu\n");
	min = base->a[i];
	printf("base->a[i] mizin ilk sayisini min yaptik\n");
	while (i < size)
	{
		printf("girdik dongumuze, base->a[i] < min diye kontrol ediyoruz\n");
		if (base->a[i] < min)
		{
			min = base->a[i];
			printf("evet sayimiz en son belirlenen min sayisindan kucuk. o zaman sayimizi min'e atiyoruz.\n");
		}
		i++;
	}
	printf("dongumuz bitti min sayimizi return ediyoruz.\n");
	return (min);
}

/**
 * @brief	Finding stack's MAX number.
 * @return	Maximum number.
 * @bug		Not know bugs.
 */
int	find_max(int size, t_base *base)
{
	int	i;
	int	max;

	i = 0;
	printf("find_max func geldik. while'ye girecegiz. i=0 dan size'ye kadar gidecek dongu\n");
	max = base->a[i];
	printf("base->a[i] mizin ilk sayisini MAX yaptik\n");
	while (i < size)
	{
		printf("girdik dongumuze, base->a[i] > MAX diye kontrol ediyoruz\n");
		if (base->a[i] > max)
		{
			max = base->a[i];
			printf("evet sayimiz en son belirlenen MAX sayisindan BUYUK. o zaman sayimizi MAX'a atiyoruz.\n");
		}
		i++;
	}
	printf("dongumuz bitti MAX sayimizi return ediyoruz.\n");
	return (max);
}