/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:18:40 by gsever            #+#    #+#             */
/*   Updated: 2022/07/15 21:54:01 by gsever           ###   ########.fr       */
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
 * @brief En kucuk sayiyi pushlayacagiz, onun icin butun diziyi tariyoruz,
 * en kucuk sayi gelince onu 
 * @return void
 * @param rra
 * @param ra
 * @param pb
 * @bug Not know bugs.
 */
void	push_smallest(int a, t_base *base)
{
	int	i;
	int	smallest;

	i = 1;
	smallest = base->a[0];
	printf("base->start.size'miz kadar while 1 'e giriyoruz i'miz: %d < sizemiz: %d\n", i, base->start.size);
	while (i < a)
	{
		printf("while, i(%d) < base->start.size(%d) --> if base->a[i](%d) < smallest(%d))\n", i, base->start.size, base->a[i], smallest);
		if (base->a[i] < smallest)
		{
			printf("evet sayimiz en kucuk sayidan kucuk o yuzden sayimizi en kucuk(smallest) sayimiza esitliyoruz.\n");
			smallest = base->a[i];
		}
		++i;
	}
	printf("while'den ciktik en kucuk sayimiz smallest(%d)\n", smallest);
	i = -1;
	printf("base->start.size'miz kadar while 2 'ye giriyoruz i'miz: %d < a(%d) - 1 ise!\n", i, a);
	while (i++ < a - 1)
	{
		printf("i(%d) < a(%d) - 1 --> eger base->a[i](%d) == smallest(%d) ise break\n", i, a, base->a[i], smallest);
		if (base->a[i] == smallest)
		{
			printf("evet esit break ile cikiyoruz!\n");
			break ;
		}
	}
	printf("while'den ciktik i(%d) ile siradaki en kucuk sayimizi bulmus olduk.\n", i);
	printf("base->a[0](%d) != smallest(%d) esit degilse while'mize giriyoruz.\n", base->a[0], smallest);
	while (base->a[0] != smallest)
	{
		printf("base->a[0](%d) != smallest(%d)\n", base->a[0], smallest);
		printf("eger i(%d) > base->c_a(%d) / 2 ise rra yapacak degilse ra yapacak.\n", i, base->c_a);
		if (i > base->c_a / 2)
			rra(1, base);
		else
			ra(1, base);
	}
	pb(base);
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
	printf("sort_small func artik bitti program bitirilebilinir...");
}