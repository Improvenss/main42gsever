/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:01:08 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/15 20:01:08 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file cmd_echo.c
 * @author Ahmet KARACA (akaraca)
 * @author Gorkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../includes/minishell.h"

void	cmd_echo_print(t_cmd *cmd, int i)
{
	int	l;

	while (cmd->full_cmd[i])
	{
		l = -1;
		while (cmd->full_cmd[i][++l])
		{
			write(cmd->outfile, &cmd->full_cmd[i][l], 1);
		}
		if (cmd->full_cmd[i + 1])
			write(cmd->outfile, " ", 1);
		i++;
	}
}

int	cmd_echo(t_base *base __attribute((unused)),
	t_cmd *cmd, int i __attribute((unused)))
{
	bool	new_line;

	if (cmd->full_cmd[1] == NULL)
		write(cmd->outfile, "\n", 1);
	else
	{
		new_line = true;
		while (ft_strncmp_edited(cmd->full_cmd[++i], "-n", 2))
			new_line = false;
		if (cmd->full_cmd[i] == NULL)
			write(cmd->outfile, "\0", 1);
		else
		{
			cmd_echo_print(cmd, i);
			if (new_line)
				write(cmd->outfile, "\n", 1);
		}
	}
	exit_status(0, 0);
	return (0);
}
