/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:46:39 by gsever            #+#    #+#             */
/*   Updated: 2022/07/02 18:29:22 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief 
 * 
 * @return void
 * @bug Not know bugs.
 */
void	remark(int size, t_base *base)
{
	int		i;

	i = 0;
	printf("\033[0;35mremark	func girdik\033[0m\n");
	printf("simdi sayilarimizin basindan baslayarak sirasiyla hepsine en buyuk sayi + 1'ini cikartip atayacagiz.\n");
	while (i < size)
	{
		printf("i = %d base->a[i](%d) -= (base->start.max + 1)(%d) ----> ", i, base->a[i], base->start.max + 1);
		base->a[i] -= (base->start.max + 1);
		printf("base->a[i](%d)\n", base->a[i]);
		++i;
	}
	printf("evet sayilarimizin hepsinden max+1 cikarildi ve sayilarimiz 0 'dan baslayarak sirasiyla siralanarak minimum sayilara indirgendi.\n");
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
		printf("*i'mizi aldik	*i = %d\n", *i);
		printf("if?	tmp(%d) == 0 'mi kontrol ediyoruz.\n", *tmp);
		if (*tmp == 0)
		{
			printf("evet tmp == 0\n");
			printf("if2?	base->a[*i](%d) == 0 'mi\n", base->a[*i]);
			if (base->a[*i] == 0)
			{
				printf("yes base->a[*i](%d) == 0 o zaman index'imizi base->a[*i] yapiyoruz\n", base->a[*i]);
				base->a[*i] = *index;
			}
		}
		printf("if?? base->a[*i](%d) == *tmp(%d) 'mi diye kontrol ediyoruz\n", base->a[*i], *tmp);
		if (base->a[*i] == *tmp)
		{
			printf("\033[0;34maynen\033[0m base->a[*i] = *index(%d) yapiyoruz ve BREAK ile cikiyoruz.\n", *index);
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

	printf("\033[0;31mmarkup\033[0m		func girdik, kontrol ediyoruz index > size + base->start.max 'mi diye, eger buyukse return'la bitirecegiz\n");
	if (index > size + base->start.max)
	{
		printf("evet buyuk return ile cikiyoruz.\n");
		return ;
	}
	printf("degilmis bitmedi devam ediyoruz\n");
	tmp = base->start.max;
	printf("tmp = base->start.max ile simdilik find_max func'tan buldugumuz max sayimizi tmp'ye atiyoruz --> base->start.max:%d\n", tmp);
	i = 0;
	while (i < size)
	{
		printf("i = %d'dan sayimiz kadar kontrol ediyoruz --> if sayimiz > oncekisinden && sayimiz <= tmp(yani max) ise sayimizi tmp(yani max) yapiyoruz.\n", i);
		if (base->a[i] > prev && base->a[i] <= tmp)
		{
			printf("sayimiz oncekisinden buyuk bu yuzden bu sayimizi tmp(yani MAX) yapiyoruz. onceki(prev)	:%d sonraki(base->a[i])	:%d\n", prev, base->a[i]);
			tmp = base->a[i];
		}
		i++;
	}
	printf("while'den ciktik, en kucuk + 1 =	tmp:%d\n", tmp);
	printf("\033[0;32mmarkup_norme\033[0m	func gidiyoruz, adresleriyle gonderecegiz ki iclerindeki verileri degistirebilelim.\n");
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
	printf("markup	functan remark functionuna gidiyoruz.\n");
	remark(size, base);
	base->max = base->start.size - 1;
	base->c_a = base->start.size;
	base->c_b = 0;
	base->mid = (base->start.size + 1) / 2;
}