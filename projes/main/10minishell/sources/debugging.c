/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:52:46 by gsever            #+#    #+#             */
/*   Updated: 2022/10/26 21:51:37 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file debugging.c
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
 * @brief Printing all cmd linked list.
 * NOTE: Eger export'la DEFINE=print define etmisse yazdirir.
 * 
 * @param base 
 * @param env_var 
 * @param value 
 */
void	debug_print_cmd(t_base *base, char *env_var, char *value)
{
	t_cmd	*write;
	int		i;
	int		l;

	if (env_is_have(base, env_var, value))
	{
		write = base->cmd;
		while (write)
		{
			i = -1;
			while (write->full_cmd[++i])
				printf("CMD->[%d]: %s\n", i, write->full_cmd[i]);
			l = 0;
			while (write->redirect && write->redirect[l])
			{
				printf("CMD_RED->[%d]: %s\n", l, write->redirect[l]);
				l++;
			}
			printf("[%d]: in: %d out: %d\n", i, write->infile, write->outfile);
			write = write->next;
		}
		printf("##########################################################\n");
	}
}

/**
 * @brief Printing Lexer's all linked list.
 * NOTE: Eger export'la DEFINE=print define etmisse yazdirir.
 * 
 * @param base 
 * @param env_var 
 * @param value 
 */
void	debug_print_str(t_base *base, char *env_var, char *value)
{
	t_lexer	*tmp;

	tmp = base->lexer;
	if (env_is_have(base, env_var, value))
	{
		while (tmp)
		{
			printf("			->: STR: %s FLAG: %d\n", tmp->str, tmp->flag);
			tmp = tmp->next;
		}
		printf("##########################################################\n");
	}
}
