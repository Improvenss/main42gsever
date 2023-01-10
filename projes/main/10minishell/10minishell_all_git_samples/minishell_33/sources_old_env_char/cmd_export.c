/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:41:34 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/21 23:09:41 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file cmd_export.c
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


int	cmd_export_add(t_base *base, t_cmd *cmd)
{
	int	i;
	(void)base;
	i = 1;
	while (cmd->full_cmd[i])
	{
		

		i++;
	}
	return (0);
}

int	find_chr_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	cmd_export_print(t_base *base, t_cmd *cmd)
{
	char	*print;
	char	*min;
	int		env_size;
	int		l;

	env_size = env_strlen(base->env);
	print = find_max_str(base->env);
	while (env_size-- > 0)
	{
		ft_putstr_fd("declare -x ", cmd->outfile);
		l = 0;
		while (print[l])
		{
			write(cmd->outfile, &print[l], 1);
			if (print[l] == '=')
				write(cmd->outfile, "\"", 1);
			if (print[l + 1] == '\0')
				write(cmd->outfile, "\"", 1);
			l++;
		}
		write(cmd->outfile, "\n", 1);
		min = find_min_str(base->env);
		l = -1;
		while (base->env[++l])
		{
			if (ft_strcmp_edited(print, base->env[l]) < 0
				&& ft_strcmp_edited(min, base->env[l]) > 0)
			{
				min = base->env[l];
			}
		}
		print = min;
	}
}

int	cmd_export(t_base *base, t_cmd *cmd)
{
	if (cmd->full_cmd[1] == NULL)
		cmd_export_print(base, cmd);
	else if (export_arg_check(cmd->full_cmd))
		cmd_export_add(base, cmd);
	exit_status(0, 0);
	return (0);
}
