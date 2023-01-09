/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:00:26 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/15 21:00:26 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file cmd_pwd.c
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

int	cmd_pwd(t_base *base __attribute((unused)), t_cmd *cmd)
{
	char	pwd[256];

	if (cmd->full_cmd[1] == NULL)
	{
		getcwd(pwd, sizeof(pwd));
		ft_putendl_fd(pwd, cmd->outfile);
	}
	else
	{
		print_error(SHELLNAME, "pwd", NULL, "too many arguments");
		exit_status(1, 0);
	}
	return (0);
}
