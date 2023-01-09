/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:45:44 by gsever            #+#    #+#             */
/*   Updated: 2022/10/26 22:49:17 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file utils_fork.c
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

/**
 * @brief 
 * 
 * @param base 
 */
void	ft_wait(t_base *base)
{
	int	i;
	int	err;

	i = -1;
	while (++i < base->cmd_count)
		waitpid(base->pid[i], &err, 0);
	exit_status(err, 0);
}

void	fd_close(t_base *base)
{
	int	i;

	i = -1;
	while (++i < base->cmd_count)
	{
		close(base->fd[i][0]);
		close(base->fd[i][1]);
	}
}

void	fork_dup(t_base *base, int i, t_cmd *cmd)
{
	if (i > 0 && cmd->infile == 0)
		dup2(base->fd[i - 1][0], 0);
	if (i != (base->cmd_count - 1))
		dup2(base->fd[i][1], 1);
}
