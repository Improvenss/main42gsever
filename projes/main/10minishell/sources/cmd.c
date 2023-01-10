/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:46:00 by gsever            #+#    #+#             */
/*   Updated: 2022/10/27 12:29:27 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	cmd_set_me_fd_two(t_cmd *cmd,
	int *last_in, int *last_out, int i)
{
	int	flags[2];

	if (ft_strncmp_edited(cmd->redirect[i], ">>", 2))
	{
		flags[0] = 1;
		flags[1] = 1;
		cmd->outfile = set_fd(cmd->outfile, cmd->redirect[i + 1], flags);
		cmd_set_me_fd_last_out(cmd, last_out);
	}
	else if (ft_strncmp_edited(cmd->redirect[i], ">", 1))
	{
		flags[0] = 1;
		flags[1] = 0;
		cmd->outfile = set_fd(cmd->outfile, cmd->redirect[i + 1], flags);
		cmd_set_me_fd_last_out(cmd, last_out);
	}
	else if (ft_strncmp_edited(cmd->redirect[i], "<", 1))
	{
		flags[0] = 0;
		flags[1] = 0;
		cmd->infile = set_fd(cmd->infile, cmd->redirect[i + 1], flags);
		if (*last_in == -1)
			*last_in = cmd->infile;
	}
}

static int	cmd_set_me_fd_first(t_base *base, t_cmd *cmd,
	int *last_in, int i)
{
	if (ft_strncmp_edited(cmd->redirect[i], "<<", 2))
	{
		cmd->infile = set_heredoc(cmd->redirect[i + 1]);
		if (cmd->redirect[i + 1] == NULL)
			*last_in = cmd->infile;
		if (cmd->infile == -1)
		{
			base->heredoc_status = 0;
			return (0);
		}
	}
	return (1);
}

int	cmd_set_me_fd(t_base *base, t_cmd *cmd, int last_in, int last_out)
{
	int	i;
	int	max;

	max = cmd->red_size;
	i = -1;
	while (cmd->redirect[++i])
	{
		if (cmd_set_me_fd_first(base, cmd, &last_in, i) == 0)
			return (0);
	}
	i = max - 2;
	while (i >= 0)
	{
		cmd_set_me_fd_two(cmd, &last_in, &last_out, i);
		i--;
	}
	if (last_in != -1)
		cmd->infile = last_in;
	if (last_out != -1)
		cmd->outfile = last_out;
	if (cmd->outfile == -1 || cmd->infile == -1)
		exit_status(1, 0);
	return (1);
}

void	cmd_set_me(t_base *base)
{
	t_cmd	*tmp;
	int		i;

	i = base->cmd_count;
	tmp = cmd_lstlast(base->cmd);
	while (i-- > 0 && tmp && base->heredoc_status == 1)
	{
		if (tmp->red_size > 0)
			cmd_set_me_fd(base, tmp, -1, -1);
		tmp = tmp->prev;
	}
}

void	cmd(t_base *base)
{
	t_lexer	*tmp;

	tmp = base->lexer;
	while (tmp)
	{
		tmp = cmd_create(&base->cmd, tmp);
	}
	base->cmd_count = cmd_count(base->cmd);
	base->heredoc_status = 1;
	exit_status(0, 0);
	cmd_set_me(base);
	debug_print_cmd(base, "DEBUG", "print");
	if (fork_init(base) == 0)
	{
		print_error(SHELLNAME, "fork", NULL, "Cannot allocate memory");
		cmd_exit(base, base->cmd, 0);
	}
	if (base->heredoc_status == 1)
		fork_start(base);
	else
		exit_status(1, 0);
}
