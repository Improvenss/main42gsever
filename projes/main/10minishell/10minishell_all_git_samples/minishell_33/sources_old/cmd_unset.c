/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:56:19 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/15 21:56:19 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file cmd_unset.c
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

int	cmd_unset(t_base *base, t_cmd *cmd)
{
	t_env	*tmp;
	t_env	*before;
	t_env	*del;
	int		l;

	l = 0;
	while (cmd->full_cmd[++l] != NULL)
	{
		tmp = base->env;
		tmp->prev = NULL;
		while (tmp != NULL && cmd->full_cmd[l] != NULL)
		{
			if (ft_strcmp_edited(cmd->full_cmd[l], tmp->data[0]) == 0)
			{
				del = tmp;
				tmp->prev->next = tmp->next;
				chr_free(del->data);
			}
			before = tmp;
			tmp = tmp->next;
			if (tmp != NULL)
				tmp->prev = before;
		}
	}
	return (0);
}
