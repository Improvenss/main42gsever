/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_set_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:45:03 by gsever            #+#    #+#             */
/*   Updated: 2022/10/27 09:37:57 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	set_fd_set(int oldfd, char *path, int *flags)
{
	int	fd;

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

int	set_fd(int oldfd, char *path, int *flags)
{
	if (access(path, F_OK) == 1 && !flags[0])
	{
		exit_status(127, 0);
		return (print_error(SHELLNAME, path, \
		"No such file or directory", NULL));
	}
	else if (access(path, R_OK) == -1 && !flags[0])
	{
		exit_status(126, 0);
		return (print_error(SHELLNAME, path, \
		"No such file or directory", NULL));
	}
	else if (access(path, W_OK) == -1 && access(path, F_OK) == 0 && flags[0])
	{
		exit_status(126, 0);
		return (print_error(SHELLNAME, "permission denied", path, NULL));
	}
	return (set_fd_set(oldfd, path, flags));
}

char	*get_heredoc_str(char *limit)
{
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	signal(SIGINT, action_heredoc);
	while (exit_status(0, 1) != 130
		&& (!ft_strncmp_edited(str, limit, ft_strlen(limit)) || !str))
	{
		free(str);
		str = readline("> ");
		if (!str)
		{
			printf("%s (wanted `%s\')\n", "minishell: warning: \
			here-document delimited by end-of-file", limit);
			break ;
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
	if (str == NULL)
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
