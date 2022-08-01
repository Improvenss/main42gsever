/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:20:00 by Nik               #+#    #+#             */
/*   Updated: 2019/08/29 20:51:19 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int		is_duplicate(int n, int *stack)
{
	int i;

	i = LEN;
	while (i > 0)
	{
		if (stack[i] == n)
			return (1);
		i--;
	}
	return (0);
}

static void		del_duplicate(int *stack, int num)
{
	while (++num <= LEN)
		stack[num - 1] = stack[num];
	LEN--;
}

static int		get_answer(void)
{
	char *answer;

	ft_printf("your input contains duplicates\n");
	ft_printf("would you like to del it (yes/no)\t");
	while (get_next_line(0, &answer))
	{
		if (!ft_strcmp(answer, "yes"))
		{
			free(answer);
			return (1);
		}
		else if (!ft_strcmp(answer, "no"))
		{
			ft_printf("{red}ERROR{eoc} - invalid input\n");
			free(answer);
			exit(1);
		}
		ft_printf("would you like to del it (yes/no)\t");
		free(answer);
	}
	return (0);
}

void			duplicates_check(int *stack, int err_flag)
{
	int		*new;
	int		i;
	int		answer;

	i = 1;
	answer = 0;
	new = init_b(LEN + 1);
	while (i <= LEN)
	{
		if (is_duplicate(stack[i], new))
		{
			if (!err_flag)
				ft_error("input contains duplicates");
			if (!answer)
				answer = get_answer();
			del_duplicate(stack, i);
		}
		else
		{
			new[0]++;
			new[new[0]] = stack[i];
			i++;
		}
	}
	free(new);
}
