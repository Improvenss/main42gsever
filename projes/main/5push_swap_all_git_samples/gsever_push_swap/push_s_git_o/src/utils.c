/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/17 15:04:54 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 13:30:59 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	dup_piles(t_piles *dst, t_piles *src)
{
	int		i;

	if (!src)
		return ;
	if (!(dst->pile_a = malloc(sizeof(int) * (src->a_len + src->b_len))) ||
		!(dst->pile_b = malloc(sizeof(int) * (src->a_len + src->b_len))) ||
		!(dst->index_a = malloc(sizeof(int) * (src->a_len + src->b_len))) ||
		!(dst->index_b = malloc(sizeof(int) * (src->a_len + src->b_len))))
		return ;
	dst->b_len = src->b_len;
	dst->a_len = src->a_len;
	i = 0;
	while (i < (dst->a_len + dst->b_len))
	{
		dst->pile_a[i] = src->pile_a[i];
		dst->index_a[i] = src->index_a[i];
		dst->pile_b[i] = src->pile_b[i];
		dst->index_b[i] = src->index_b[i];
		i++;
	}
}

void	rotate_pile(t_piles *pile, int ab, int rev)
{
	int		*pile_tab;
	int		pile_len;
	int		i;
	int		*index_tab;

	if ((!ab && !pile->a_len) || (ab && !pile->b_len))
		return ;
	pile_tab = !ab ? pile->pile_a : pile->pile_b;
	index_tab = !ab ? pile->index_a : pile->index_b;
	pile_len = !ab ? pile->a_len : pile->b_len;
	i = !rev ? 1 : pile_len - 1;
	while (i < pile_len && i)
	{
		bit_swapper(pile_tab, i - 1, i);
		bit_swapper(index_tab, i - 1, i);
		i += 2 * !rev - 1;
	}
}

int		iscmd(char *cmd)
{
	return (!ft_strcmp(cmd, "sa") || !ft_strcmp(cmd, "sb") ||
			!ft_strcmp(cmd, "ss") || !ft_strcmp(cmd, "pa") ||
			!ft_strcmp(cmd, "pb") || !ft_strcmp(cmd, "ra") ||
			!ft_strcmp(cmd, "rb") || !ft_strcmp(cmd, "rr") ||
			!ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrb") ||
			!ft_strcmp(cmd, "rrr"));
}

int		check_pile(t_piles *pilelst, int print)
{
	int		i;

	while (pilelst->next)
		pilelst = pilelst->next;
	if (pilelst->b_len != 0)
		return (print ? ft_printf("KO\n") : 0);
	i = 0;
	while (i < pilelst->a_len - 1)
	{
		if (pilelst->pile_a[i] > pilelst->pile_a[i + 1])
			return (print ? ft_printf("KO\n") : 0);
		i++;
	}
	return (print ? ft_printf("OK\n") : 1);
}

int		free_pilelst(t_piles *pilelst)
{
	t_piles		*prev;

	while (pilelst)
	{
		prev = pilelst;
		pilelst = pilelst->next;
		free(prev->pile_a);
		free(prev->index_a);
		free(prev->pile_b);
		free(prev->index_b);
		if (pilelst)
			free(prev->cmd);
		pilelst = prev->next;
		free(prev);
	}
	return (0);
}
