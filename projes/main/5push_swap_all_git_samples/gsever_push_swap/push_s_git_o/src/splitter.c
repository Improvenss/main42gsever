/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   splitter.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 13:17:55 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 13:18:49 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		*pa_max(t_piles *pile)
{
	int		max;
	int		i;

	i = 0;
	max = 0;
	while (i < pile->b_len)
	{
		if (pile->index_b[i] >= max)
			max = pile->index_b[i];
		i++;
	}
	pile = go_to_b(pile, max);
	pile = launch_cmd(pile, "pa");
	return (pile);
}

t_piles		*pb_min(t_piles *pile)
{
	int		min;
	int		i;

	i = 0;
	min = CINT_MAX;
	while (i < pile->a_len)
	{
		if (pile->index_a[i] <= min)
			min = pile->index_a[i];
		i++;
	}
	pile = go_to(pile, min);
	pile = launch_cmd(pile, "pb");
	return (pile);
}

t_piles		*auto_split_b(t_piles *pile, int st, int end)
{
	int			ct;

	ct = 0;
	end = end > pile->b_len + pile->a_len ? pile->b_len + pile->a_len : end;
	st = st < 0 ? 0 : st;
	while (ct < (end - st))
	{
		if (pile->index_b[0] < end && pile->index_b[0] >= st)
		{
			pile = launch_cmd(pile, "pa");
			ct++;
		}
		else
			pile = launch_cmd(pile, "rb");
	}
	return (pile);
}

t_piles		*auto_split_a(t_piles *pile, int st, int end)
{
	int			ct;

	ct = 0;
	end = end > pile->a_len + pile->b_len ? pile->a_len + pile->b_len : end;
	st = st < 0 ? 0 : st;
	while (ct < (end - st))
	{
		if (pile->index_a[0] < end && pile->index_a[0] >= st)
		{
			pile = launch_cmd(pile, "pb");
			ct++;
		}
		else
			pile = launch_cmd(pile, "ra");
	}
	return (pile);
}

t_piles		*rev_split_a(t_piles *pile, int st, int end)
{
	int			ct;

	ct = 0;
	end = end > pile->a_len + pile->b_len ? pile->a_len + pile->b_len : end;
	st = st < 0 ? 0 : st;
	while (ct < (end - st))
	{
		if (pile->index_a[0] < end && pile->index_a[0] >= st)
		{
			pile = launch_cmd(pile, "pb");
			ct++;
		}
		else
			pile = launch_cmd(pile, "rra");
	}
	return (pile);
}
