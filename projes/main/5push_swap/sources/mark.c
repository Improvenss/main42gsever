/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:46:39 by gsever            #+#    #+#             */
/*   Updated: 2022/07/01 20:19:12 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	remark(int size, t_base *base)
{
	int		i;

	i = 0;
	while (i < size)
	{
		base->a[i] -= (base->start.max + 1);
		++i;
	}
	return ;
}

void	markup_norme(int *i, int *index, int *tmp, t_base *base)
{
	while (*i >= 0)
	{
		if (*tmp == 0)
		{
			if (base->a[*i] == 0)
				base->a[*i] = *index;
		}
		if (base->a[*i] == *tmp)
		{
			base->a[*i] = *index;
			break ;
		}
		(*i)++;
	}
}

/**
 * @brief Recursive onself
 * @return void
 * @param markup_norme ???
 * @param markup Recursive markup function.
 * @bug Not know bugs.
 */
void	markup(int size, int index, int prev, t_base *base)
{
	int	i;
	int	tmp;

	printf("markup func girdik, kontrol ediyoruz index > size + base->start.max 'mi diye, eger buyukse return'la bitirecegiz\n");
	if (index > size + base->start.max)
		return ;
	printf("degilmis bitmedi devam ediyoruz\n");
	tmp = base->start.max;
	printf("tmp = base->start.max ile simdilik find_max func'tan buldugumuz max sayimizi tmp'ye atiyoruz --> base->start.max:%d\n", base->start.max);
	i = 0;
	while (i < size)
	{
		if (base->a[i] > prev && base->a[i] <= tmp)
			tmp = base->a[i];
		i++;
	}
	markup_norme(&i, &index, &tmp, base);
	markup(size, ++index, tmp, base);
}

/**
 * @brief	Indexer = Hafizaya alma demek.
 * We are indexing ---> marking --> remarking
 * @return	void
 * @param	is_repeated We are controling repeaded numbers. If found -> "Error"
 * @param	find_min We are assigning min value to base->start.min.
 * @param	find_max We are assigning max value to base->start.max.
 * @param	markup 
 * @param	remark
 * @bug		Not know bugs.
 */
void	indexer(int size, t_base *base)
{
	printf("indexer girdik, is_repeated func giriyoruz\n");
	is_repeated(base);
	printf("is_repeated ciktik\n");
	printf("find_min func gidiyoruz\n");
	base->start.min = find_min(size, base);
	printf("min bulduk, base->start.min atadik, find_max'a gidiyoruz\n");
	base->start.max = find_max(size, base);
	printf("max bulduk, base->start.max atadik, markup func gidiyoruz\n");
	markup(base->start.size, base->start.max + 1, base->start.min - 1, base);
	remark(size, base);
	base->max = base->start.size - 1;
	base->c_a = base->start.size;
	base->c_b = 0;
	base->mid = (base->start.size + 1) / 2;
}