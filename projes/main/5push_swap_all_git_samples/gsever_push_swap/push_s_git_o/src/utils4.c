/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils4.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 12:27:38 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 14:32:01 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int			get_index(t_piles *pile, int ab, int pos)
{
	int		i;
	int		*index_tab;
	int		pile_len;

	index_tab = !ab ? pile->index_a : pile->index_b;
	pile_len = !ab ? pile->a_len : pile->b_len;
	i = 0;
	while (i < pile_len && index_tab[i] != pos)
		i++;
	if (i == pile_len)
		return (-1);
	return (i);
}

t_piles		*go_to_b(t_piles *pile, int togo)
{
	int		dir;
	int		index;

	index = 0;
	while (index < pile->b_len && pile->index_b[index] != togo)
		index++;
	dir = index <= pile->b_len / 2;
	index = dir ? index : pile->b_len - index;
	while (index--)
		pile = launch_cmd(pile, dir ? "rb" : "rrb");
	return (pile);
}

t_piles		*go_to(t_piles *pile, int togo)
{
	int		dir;
	int		index;

	index = 0;
	while (index < pile->a_len && pile->index_a[index] != togo)
		index++;
	dir = index <= pile->a_len / 2;
	index = dir ? index : pile->a_len - index;
	while (index--)
		pile = launch_cmd(pile, dir ? "ra" : "rra");
	return (pile);
}
