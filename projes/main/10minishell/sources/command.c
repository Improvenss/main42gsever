/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:10:01 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/15 15:10:01 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file command.c
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

void	cmd_execve(t_base *base, t_cmd *cmd, char *command, char **cmd_array)
{
	int	pi;

	pi = fork();
	if (pi == 0)
	{
		if (base->fd_i != base->cmd_count)
		{
			dup2(cmd->infile, 0);
			dup2(cmd->outfile, 1);
		}
		if (cmd->infile == -1 || cmd->outfile == -1)
			exit(1);
		else
			base->err = execve(command, cmd_array, base->env_chr);
	}
	waitpid(pi, &base->err, 0);
	if (-1 & (cmd->infile | cmd->outfile))
		base->err = base->err / 256;
	exit_status(base->err, 0);
}

static void	cmd_other_part_two(t_base *base, t_cmd *cmd, char **cmd_array)
{
	if (base->mem_1 && !file_or_dir_search(cmd_array[0], O_DIRECTORY))
		cmd_execve(base, cmd, base->mem_1, cmd_array);
	else if (access(cmd_array[0], 0) == 0
		&& !file_or_dir_search(cmd_array[0], O_DIRECTORY))
		cmd_execve(base, cmd, cmd_array[0], cmd_array);
	else
	{
		print_error(SHELLNAME, NULL, cmd_array[0], "command not found");
		exit_status(127, 0);
	}
}

int	cmd_other(t_base *base, t_cmd *cmd, char **cmd_array)
{
	base->env_path = ft_split(env_findret_no_dup(base, "PATH"), ':');
	base->mem_1 = ft_path(base->env_path, cmd_array[0]);
	base->env_chr = env_be_char(base->env);
	signal(SIGINT, action_execve);
	if (search_and_launch(cmd_array))
	{
		if (file_or_dir_search(cmd_array[0], O_DIRECTORY))
		{
			print_error(SHELLNAME, NULL, cmd_array[0], "Is a directory");
			exit_status(1, 0);
		}
		else
			cmd_execve(base, cmd, base->mem_1, cmd_array);
	}
	else
		cmd_other_part_two(base, cmd, cmd_array);
	free(base->mem_1);
	free_pp_str(base->env_chr);
	free_pp_str(base->env_path);
	return (0);
}

/**
 * @brief base->commands[]'in icinde isimleriyle cmd_array'ini
 *  karsilastiriyoruz.
 * 
 * NULL: return (0).
 * FIND: cmd_*.c icindeki gerekli komutun index sirasini donduruyor
 *  o yuzden i + 1 var.
 * NFIND: cmd_other()'e giderek execve()'yle cmd_array'i calistiriyor.
 * 
 * @param base 
 * @param cmd_array 
 * @fn ft_strlen(): command_name; base->commands[0]'daki 
 * NOTE: exit komutu yazildiginda exit'e ozel olarak ERROR donecek
 * @return int NULL: 0, OK: commands[] index'i, NOK: execve's return value.
 */
int	command_find_arr(t_base *base, t_cmd *cmd, char **cmd_array)
{
	int	c_name;
	int	i;

	if (cmd_array[0] == NULL)
		return (0);
	i = -1;
	while (cmd_array && base->commands[++i].name != NULL)
	{
		c_name = ft_strlen(base->commands[i].name);
		if (cmd_array && ft_strncmp_edited(cmd_array[0],
				base->commands[i].name, c_name))
		{
			return (i + 1);
		}
	}
	return (cmd_other(base, cmd, cmd_array));
}

/**
 * @brief Genel komut calistirma islemi buradan basliyor.
 * 
 * 			lexer->parser->expander
 * FIND: Islemleri bittikten sonra bizim kendi tanimladigimiz base->commands[]
 *  structunun icinde base->cmd->full_cmd komutlarimizi ariyoruz,
 *  buldugumuzda kendi yazmis oldugumuz cmd_* func()'larimizi calistiriyoruz.
 * NFIND: Eger bulamazsak return(0);
 * 
 * @param base 
 * @param cmd 
 * @return int 
 */
int	command_exec(t_base *base, t_cmd *cmd)
{
	int	cmd_i;

	cmd_i = command_find_arr(base, cmd, cmd->full_cmd);
	if (cmd_i > 0 && cmd_i < 8)
		return (base->commands[cmd_i - 1].func(base, cmd, 0));
	return (0);
}
