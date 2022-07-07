/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:18:40 by gsever            #+#    #+#             */
/*   Updated: 2022/07/07 12:55:13 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file sort_small.c
 * @brief 
 * 
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
#include "../includes/push_swap.h"

/**
 * @brief 
 * @return void
 * @param rra
 * @param ra
 * @param pb
 * @bug Not know bugs.
 */
void	push_smallest(int a, t_base *base)
{
	// int	i;
	// int	smallest;

	// i = 1;
	// smallest = base->a[0];
	(void)a;
	(void)base;
	// while (i < a)
	// {
		
	// }
}

/**
 * @brief 
 * @return void
 * @param push_smallest
 * @bug Not know bugs.
 */
void	six_sort(t_base *base)
{
	int	diff;
	int	i;

	i = 0;
	printf("Evet girdik, sayi adetimizi(%d) - 3 unu --> diff'e atayacagiz.\n", base->start.size);
	diff = base->start.size - 3;
	printf("diff(%d) = base->start.size(%d) - 3 yaptik while'mize girecegiz.\n", diff, base->start.size);
	printf("whilemiz i=0 iken size - 3 kadar donecek.\n");
	while (i < diff)
	{
		printf("while (i(%d) < diff(%d))\n", i, diff);
		printf("push_smallest func giriyoruz.\n");
		push_smallest(base->start.size - i, base);
		i++;
	}
	printf("six_sort() functan cikiyoruz.\n");
}

/**
 * @brief If number count < 7 running this func.
 * @return void
 * @param sa If number count 2 starting.
 * @param six_sort If number count not 2 starting.
 * @bug Not know bugs.
 */
void	sort_small(t_base *base)
{
	printf("sort_small() func girdik.\n");
	printf("eger 2 adet sayimiz varsa sa() yapip six_sort() func girecegiz.\n");
	if (base->c_a == 2)
	{
		printf("evet 2 tane sayimiz var o yuzden sa() giriyoruz.\n");
		sa(1, base);
	}
	printf("six_sort() func giriyoruz simdi\n");
	six_sort(base);
}