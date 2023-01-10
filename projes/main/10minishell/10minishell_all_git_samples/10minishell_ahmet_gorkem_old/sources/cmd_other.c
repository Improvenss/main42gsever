/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:41:10 by gsever            #+#    #+#             */
/*   Updated: 2022/10/18 17:42:20 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	cmd_other(t_base *base, char *pipe_line)
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		execve(ft_path(base->PATH, pipe_line),
			ft_split(pipe_line, ' '), base->environ);
	}
	waitpid(pid, &base->status, 0);
	return (0);
}