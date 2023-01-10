/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:58:45 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/15 21:58:45 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file cmd_cd.c
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

char	*clear_slash(t_base *base, char *str)
{
	char		*tmp;
	size_t		i;
	size_t		l;

	tmp = (char *)malloc(sizeof(char) * ft_strlen(str));
	if(!tmp)
		return (NULL);
	l = 0;
	if (!ft_strncmp_edited(env_findret(base, "PWD"), "/", 1))
		tmp[l++] = '/';
	i = 0;
	while (l <= ft_strlen(str) && str[i] != '/')
		tmp[l++] = str[i++];
	tmp[l] = '\0';
	return (tmp);
}

char	*cd_slash(char *str)
{
	int		i;
	int		l;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * ft_strlen(str));
	if (!tmp)
		return (NULL);
	i = 0;
	l = 0;
	while (str[i] == '/')
		i++;
	if (str[i] == '\0')
		tmp[l++] = '/';
	while (str[i])
	{
		if (str[i - 1] == '/' && str[i] != '\0')
			tmp[l++] = '/';
		tmp[l++] = str[i++];
		while (str[i] == '/')
			i++;
	}
	tmp[l] = '\0';
	return (tmp);
}

char	*delete_front_slash(char *str)
{
	char	*tmp;
	int		l;
	int		i;

	l = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * l);
	while (str[l] != '/')
		l--;
	i = -1;
	while (++i < l)
		tmp[i] = str[i];
	if (l == 0)
		tmp[i++] = '/';
	tmp[i] = '\0';
	return (tmp);
}

int	cmd_cd(t_base *base, t_cmd *cmd)
{
	if (cmd->full_cmd[2] != NULL)
	{
		print_error(SHELLNAME, "cd", NULL, "too many arguments");
		exit_status(1, 0);
	}
	else if (cmd->full_cmd[1] == NULL
		|| ft_strncmp_edited(cmd->full_cmd[1], "~", 1)
		|| ft_strncmp_edited(cmd->full_cmd[1], "--", 2)
		|| (cmd->full_cmd[1] != NULL && ft_strncmp_edited(cmd->full_cmd[1], "\0", 0))) // cd $pwd için.
	{
		set_env(base, "OLDPWD", env_findret(base, "PWD"));
		set_env(base, "PWD", env_findret(base, "HOME"));
		chdir(env_findret(base, "HOME"));
		exit_status(0, 0);
	}
	else if (ft_strncmp_edited(cmd->full_cmd[1], "-", 1))
	{
		base->mem_1 = env_findret(base, "OLDPWD");
		set_env(base, "OLDPWD", env_findret(base, "PWD"));
		set_env(base, "PWD", base->mem_1);
		chdir(base->mem_1);
		ft_putstr_fd(base->mem_1, cmd->outfile);
		write(cmd->outfile, "\n", 1);
		exit_status(0, 0);
	}
	else if (cmd->full_cmd[1] != NULL && file_or_dir_search(cmd->full_cmd[1], O_DIRECTORY))
	{
		set_env(base, "OLDPWD", env_findret(base, "PWD"));
		if (ft_strncmp_edited(cmd->full_cmd[1], "..", 2))
			set_env(base, "PWD", delete_front_slash(env_findret(base, "PWD")));
		else if (cmd->full_cmd[1][0] == '/')
			set_env(base, "PWD", cd_slash(cmd->full_cmd[1]));
		else if (!ft_strncmp_edited(cmd->full_cmd[1], ".", 1))
		{
			base->mem_1 = clear_slash(base, cmd->full_cmd[1]);
			set_env(base, "PWD", ft_strjoin(env_findret(base, "PWD"), base->mem_1));
			free(base->mem_1);
		}
		chdir(env_findret(base, "PWD"));
		exit_status(0, 0);
	}
	else if (file_or_dir_search(cmd->full_cmd[1], 0))
	{
		print_error("cd", cmd->full_cmd[1], NULL, "Not a directory");
		exit_status(1, 0);
	}
	else
	{
		print_error("cd", cmd->full_cmd[1], NULL, "No such file or directory");
		exit_status(1, 0);
	}
	return (0);
}
