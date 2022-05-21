/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_millenium.c                                   :+:      :+:    :+:   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/13 12:40:36 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2022/04/17 16:52:43 by gsever           ###   ########.tr       */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		*threshold_sort(t_piles *pile)
{
	while (pile->a_len > 0)
		pile = pb_min(pile);
	while (pile->b_len > 0)
		pile = pa_max(pile);
	return (pile);
}

int			get_median(t_piles *pile, int st, int end, int ab)
{
	int		i;
	int		*index_tab;
	int		j;
	int		ct;

	i = st;
	ct = 0;
	index_tab = !ab ? pile->index_a : pile->index_b;
	while (i < end && ct != ((end - st) / 2))
	{
		ct = 0;
		j = st;
		while (j < end)
		{
			if (index_tab[j] < index_tab[i])
				ct++;
			j++;
		}
		i++;
	}
	return (i - 1);
}

t_piles		*seq_split(t_piles *pile, int st, int end)
{
	int			i;
	int			med;

	i = st;
	med = pile->index_a[get_median(pile, st, end, 0)];
	while (pile->b_len < (end / 2))
	{
		if (pile->index_a[0] < med)
			pile = launch_cmd(pile, "pb");
		else
			pile = launch_cmd(pile, "ra");
	}
	return (pile);
}

void		double_split(t_piles **pile, int blen)
{
	int		i;
	int		ref1;
	int		ref2;
	int		dir;

	i = (*pile)->b_len + (*pile)->a_len - QS_THRESHOLD;
	ref1 = (*pile)->index_a[0];
	ref2 = (*pile)->index_a[blen - 2];
	dir = 0;
	while (i > blen - QS_THRESHOLD)
	{
		*pile = !dir ? rev_split_a(*pile, i, i + QS_THRESHOLD) :
		auto_split_a(*pile, i, i + QS_THRESHOLD);
		*pile = !dir ? go_to(*pile, ref2) : go_to(*pile, ref1);
		i -= QS_THRESHOLD;
		dir = !dir;
	}
	*pile = threshold_sort(*pile);
}

void		algo_millenium(t_piles **pile)
{
	t_piles	*step;
	int		i;
	int		blen;

	step = *pile;
	step = seq_split(step, 0, step->a_len);
	blen = step->b_len;
	i = step->b_len - QS_THRESHOLD;
	while (i >= -QS_THRESHOLD)
	{
		step = auto_split_b(step, i, i + QS_THRESHOLD);
		i -= QS_THRESHOLD;
	}
	double_split(&step, blen);
}
