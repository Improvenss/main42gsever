/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:41:34 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/15 21:41:34 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
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

int	cmd_export_add(t_base *base, t_cmd *cmd, int i)
{
	t_env	*tmp;
	t_env	*new;

	while (cmd->full_cmd[++i])
	{
		if (export_same_check(base, cmd->full_cmd[i]))
		{
			new = (t_env *)malloc(sizeof(t_env));
			if (!new)
			{
				return (print_error(SHELLNAME, "exprt_new_add",
						NULL, strerror(ENOMEM)));
			}
			new->is_env_equal = false;
			if (ft_strchr(cmd->full_cmd[i], '='))
				new->is_env_equal = true;
			new->data = env_split(cmd->full_cmd[i]);
			tmp = base->env;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
			new->next = NULL;
		}
	}
	return (0);
}

static void	cmd_export_print_part_two(t_cmd *cmd, char *str, char *print)
{
	ft_putstr_fd("declare -x ", cmd->outfile);
	ft_putstr_fd(print, cmd->outfile);
	if (str != NULL)
	{
		write(cmd->outfile, "=\"", 2);
		ft_putstr_fd(str, cmd->outfile);
		write(cmd->outfile, "\"", 1);
	}
	write(cmd->outfile, "\n", 1);
}

void	cmd_export_print(t_base *base, t_cmd *cmd, int i)
{
	t_env	*tmp_down;
	char	*str;
	char	*print;

	print = export_find_min_str(base);
	while (i-- > 0)
	{
		str = env_findret(base, print);
		if (ft_strcmp_edited(print, "_"))
			cmd_export_print_part_two(cmd, str, print);
		free(str);
		str = export_find_max_str(base);
		tmp_down = base->env;
		while (tmp_down != NULL)
		{
			if (ft_strcmp_edited(print, tmp_down->data[0]) < 0
				&& ft_strcmp_edited(str, tmp_down->data[0]) > 0)
				str = tmp_down->data[0];
			tmp_down = tmp_down->next;
		}
		print = str;
	}
}

int	cmd_export(t_base *base, t_cmd *cmd, int i __attribute((unused)))
{
	if (cmd->full_cmd[1] == NULL)
		cmd_export_print(base, cmd, export_lstsize(base->env));
	else if (export_arg_check(cmd->full_cmd))
	{
		cmd_export_add(base, cmd, 0);
		exit_status(0, 0);
	}
	return (0);
}
