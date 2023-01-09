/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_set_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:45:03 by gsever            #+#    #+#             */
/*   Updated: 2022/10/21 15:28:36 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	set_fd(int oldfd, char *path, int flags[2])
{
	int	fd;

	if (access(path, F_OK) == 1 && !flags[0])
	{
		exit_status(127, 0);
		return (print_error(SHELLNAME, "No such file or directory", path, NULL));
	}
	else if (access(path, R_OK) == -1 && !flags[0])
	{
		exit_status(126, 0);
		return (print_error(SHELLNAME, path, "No such file or directory", NULL));
	}
	else if (access(path, W_OK) == -1 && access(path, F_OK) == 0 && flags[0])
	{
		exit_status(126, 0);
		return (print_error(SHELLNAME, "permission denied", path, NULL));
	}
	if (flags[0] && flags[1])
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0666);
	else if (flags[0] && !flags[1])
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (!flags[0] && oldfd != -1)
		fd = open(path, O_RDONLY);
	else
		fd = oldfd;
	return (fd);
}

char	*get_heredoc_str(char *limit)
{
	char		*str;
	char		*tmp;

	str = NULL;
	tmp = NULL;
	signal(SIGINT, action_heredoc);
	while (exit_status(0, 1) != 130 && (!ft_strncmp_edited(str, limit, ft_strlen(limit))
	|| !str))
	{
		free(str);
		str = readline("> ");
		if (!str)
		{
			printf("%s (wanted `%s\')\n", "minishell: warning: here-document delimited by end-of-file", limit);
			break;
		}
		if (!ft_strncmp_edited(str, limit, ft_strlen(limit)))
			tmp = str_add(tmp, str);
	}
	free(str);
	return (tmp);
}

int	set_heredoc(char *limit)
{
	int		fd[2];
	char	*str;

	exit_status(0, 0);
	if (pipe(fd) == -1)
		return (print_error(SHELLNAME, "error creating pipe", NULL, NULL));
	str = get_heredoc_str(limit);
	if (str == NULL) //crlt+D için
	{
		close(fd[WRITE_END]);
		return (fd[READ_END]);
	}
	write(fd[WRITE_END], str, ft_strlen(str));
	free(str);
	close(fd[WRITE_END]);
	if (exit_status(0, 1) == 130)
	{
		close(fd[READ_END]);
		return (-1);
	}
	return (fd[READ_END]);
}

void	cmd_set_fd(t_lexer *tmp, t_cmd **new)
{
	int flags[2];

	if (ft_strncmp_edited(tmp->str, ">>", 2))
	{
		flags[0] = 1;
		flags[1] = 1;
		(*new)->outfile = set_fd((*new)->outfile, tmp->next->str, flags);
	}
	else if (ft_strncmp_edited(tmp->str, ">", 1))
	{
		flags[0] = 1;
		flags[1] = 0;
		(*new)->outfile = set_fd((*new)->outfile, tmp->next->str, flags);
	}
	else if (ft_strncmp_edited(tmp->str, "<<", 2))
	{
		(*new)->infile = set_heredoc(tmp->next->str);
	}
	else if (ft_strncmp_edited(tmp->str, "<", 1))
	{
		flags[0] = 0;
		flags[1] = 0;
		(*new)->infile = set_fd((*new)->infile, tmp->next->str, flags);
	}
	if ((*new)->outfile == -1 || (*new)->infile == -1)
		exit_status(1, 0);
}
