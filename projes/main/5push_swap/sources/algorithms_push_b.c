/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_push_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:19:43 by gsever            #+#    #+#             */
/*   Updated: 2022/07/19 00:40:34 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file algorithms_push_b.c
 * @brief Sorting algorithms for push number to stack b.
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */
#include "../includes/push_swap.h"

/**
 * @brief If number count > 7 running this func.
 * @return void
 * @bug Not know bugs.
 */
void	keep_me(t_base *base)
{
	int	i;
	int	index;

	printf("\033[033mkeep_me	func\033[0m girdik.\n");
	base->c_c = 2;
	base->c[0] = base->max;
	base->c[1] = 0;
	printf("base->c_c = 2 ve base->c[0](%d) = base->max ve base->c[1](%d) = 0 yaptik.\n", base->c[0], base->c[1]);
	i = 0;
	index = 1;
	printf("while base->a[i](%d) > 0 ise giriyoruz.\n", base->a[i]);
	while (base->a[i] > 0)
	{
		printf("base->a[i](%d)\n", base->a[i]);
		i++;
	}
	printf("while'den ciktik diger while giriyoruz base->a[i](%d) < base->max ise.\n", base->a[i]);
	while (base->a[i] < base->max)
	{
		printf("base->a[i](%d) < base->max(%d)\n", base->a[i], base->max);
		if (base->a[i] == index)
		{
			printf("if1 -> base->a[i](%d) == index(%d) oldugu icin c stackinin ardina esit olan sayiyi koyacagiz.\n", base->a[i], index);
			printf("base->c[base->c_c](%d) = base->a[i](%d)\n", base->c[base->c_c], base->a[i]);
			base->c[base->c_c] = base->a[i];
			printf(" --> base->c[base->c_c](%d) = base->a[i](%d)\n", base->c[base->c_c], base->a[i]);
			base->c_c++;
			index++;
		}
		if (i == base->c_a - 1)
		{
			printf("if2 -> i(%d) == base->c_a(%d) oldugu icin i = 0 yapiyoruz.\n", i, base->c_a);
			i = 0;
			continue;
		}
		i++;
	}
	printf("keep_me	func cikiyoruz.\n");
}

int	ps_finder(int c, t_base *base)
{
	int	i;

	i = 0;
	while (i <= base->c_c)
	{
		if (base->c[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	push_to_b(t_base *base)
{
	int	i;

	i = 0;
	while (i < base->c_a)
	{
		if (ps_finder(base->a[0], base) > 0 || base->a[0] <= base->max / 4)
		{

		}
	}
}