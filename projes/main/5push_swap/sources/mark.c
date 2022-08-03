/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:46:39 by gsever            #+#    #+#             */
/*   Updated: 2022/08/03 04:53:35 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mark.c
 * @author Gorkem SEVER (gsever)
 * @brief We are indexing number's values start 0 to up.
 * Min, Max, Mid values indexing. 
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../includes/push_swap.h"

/**
 * @brief Sayilarimiz 0'dan baslayarak kucukten buyuge olacak sekilde degerler
 * veriliyor.
 * 
 * @return void
 * @bug Not know bugs.
 */
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

/**
 * @brief 
 * 
 * @return void
 * @bug Not know bugs.
 */
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
		(*i)--;
	}
}

/**
 * @brief Recursive onself
 * This int index --> the max value's + 1 amount.
 * @return void
 * @param markup_norme ???
 * @param markup Recursive markup function.
 * @bug Not know bugs.
 */
void	markup(int size, int index, int prev, t_base *base)
{
	int	i;
	int	tmp;

	if (index > size + base->start.max)
		return ;
	tmp = base->start.max;
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
	is_repeated(base);
	base->start.min = find_min(size, base);
	base->start.max = find_max(size, base);
	markup(base->start.size, base->start.max + 1, base->start.min - 1, base);
	remark(size, base);
	base->max = base->start.size - 1;
	base->c_a = base->start.size;
	base->c_b = 0;
	base->mid = (base->start.size + 1) / 2;
}
