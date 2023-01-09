/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:12:35 by gsever            #+#    #+#             */
/*   Updated: 2022/10/26 22:52:50 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file utils_free.c
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

void	free_fork_inits(t_base *base, int **fd)
{
	int	i;

	if (base->cmd_count > 1)
	{
		i = 0;
		while (i < base->cmd_count)
		{
			free(fd[i]);
			i++;
		}
		free(fd);
		free(base->pid);
	}
}

void	free_pp_str(char **line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		free(line[i++]);
	}
	if (line != NULL)
		free(line);
}
