/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:15:41 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/21 15:56:31 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file cmd_env.c
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

int	cmd_env(t_base *base, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (base->env[i])
	{
		if (ft_strchr(base->env[i], '='))
			ft_putendl_fd(base->env[i], cmd->outfile);
		i++;
	}
	exit_status(0, 0);
	return (0);
}
