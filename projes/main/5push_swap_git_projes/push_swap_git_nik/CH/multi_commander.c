/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_commander.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 10:42:14 by Nik               #+#    #+#             */
/*   Updated: 2019/08/29 13:22:50 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		multi_commander(char *cmd, int *stack_a, int *stack_b)
{
	char	**cmds;
	int		steps;
	int		i;

	steps = 0;
	i = 0;
	cmds = ft_strsplit(cmd, ' ');
	while (cmds[i])
	{
		if (is_command(cmds[i]))
			steps += commander(cmds[i], stack_a, stack_b);
		free(cmds[i]);
		i++;
	}
	free(cmds);
	return (steps);
}
