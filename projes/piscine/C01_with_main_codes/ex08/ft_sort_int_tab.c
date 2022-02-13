/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 14:43:41 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/01 23:23:01 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab_order(int *t, int *t2, int *t3, int *i)
{
	i[3] = 2147483647;
	i[0] = 0;
	while (i[0] < i[6])
	{
		i[1] = 0;
		i[2] = 0;
		while (i[1] < i[6])
		{
			if (t3[i[1]] == i[0])
			{
				i[2] = 1;
			}
			i[1]++;
		}
		if (i[2] == 0 && t[i[0]] <= i[3])
		{
			i[3] = t[i[0]];
			i[5] = i[0];
		}
		i[0]++;
	}
	t2[i[4]] = i[3];
	t3[i[4]] = i[5];
	i[4]++;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int tab2[size];
	int tab3[size];
	int i[7];

	i[6] = size;
	i[0] = 0;
	while (i[0] < size)
	{
		tab3[i[0]] = -1;
		i[0]++;
	}
	i[4] = 0;
	while (i[4] < size)
	{
		ft_sort_int_tab_order(tab, tab2, tab3, i);
	}
	i[0] = 0;
	while (i[0] < size)
	{
		tab[i[0]] = tab2[i[0]];
		i[0]++;
	}
}
