/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:48:49 by gsever            #+#    #+#             */
/*   Updated: 2022/10/26 23:25:03 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file fork.c
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

static void	fork_start_part_two(t_base *base)
{
	if (base->cmd_count > 1)
	{
		fd_close(base);
		ft_wait(base);
	}
	if (base->cmd_count == 1)
		command_exec(base, base->cmd);
}

/**
 * @brief command_exec() burada calisacak.
 * 
 * @note base->cmd_count: Pipe sayisi + 1 kadar. Bu kadar process acilacak.
 * 
 * @param base 
 * @fn fork(): Eger birden fazla pipe'miz varsa o kadar calistirilacak
 *  ve islemi bitince sonlandirilacak.
 * @fn fork_dup(): Bir onceki pipe'den(fork'tan) bilgiyi alabilmek icin.
 * @fn fd_close()
 * @fn command_exec(): Komut burada calistirilacak, eger cmd_*()'da tanimli
 *  bir komut yoksa execve()'ye gonderilip calistirilacak.
 * @fn print_error(): Eger komutumuz ve execve'miz calismazsa
 *  yazdirilacak error.
 * @fn exit()
 * @fn ft_wait()
 * @return int 
 */
int	fork_start(t_base *base)
{
	t_cmd	*tmp;
	int		i;

	i = -1;
	base->fd_i = -1;
	tmp = base->cmd;
	while (base->cmd_count > 1 && ++i < base->cmd_count && tmp)
	{
		base->fd_i = i;
		if (ft_strncmp_edited(tmp->full_cmd[0], "wc", 2) == 0)
			signal(SIGINT, SIG_IGN);
		base->pid[i] = fork();
		if (base->pid[i] == 0)
		{
			fork_dup(base, i, tmp);
			fd_close(base);
			exit(command_exec(base, tmp));
		}
		tmp = tmp->next;
	}
	fork_start_part_two(base);
	return (0);
}

int	fork_init(t_base *base)
{
	int	i;

	if (base->cmd_count > 1)
	{
		base->fd = (int **)malloc(sizeof(int *) * (base->cmd_count + 1));
		if (base->fd == NULL)
			return (0);
		i = -1;
		while (++i < base->cmd_count)
		{
			base->fd[i] = (int *)malloc(sizeof(int) * 2);
			if (base->fd[i] == NULL)
				return (0);
			pipe(base->fd[i]);
		}
		base->pid = (int *)malloc(sizeof(int) * base->cmd_count);
		if (base->pid == NULL)
			return (0);
	}
	return (1);
}
