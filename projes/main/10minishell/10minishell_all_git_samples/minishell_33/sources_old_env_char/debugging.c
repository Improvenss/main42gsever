/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:52:46 by gsever            #+#    #+#             */
/*   Updated: 2022/10/21 15:31:06 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
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
void	debug_print_cmd(t_base *base, char *env_name)
{
	char	*env;
	int		i;

	env = env_findret(base->env, env_name);
	if (env != NULL)
	{
		t_cmd *write;
		write = base->cmd;
		while (write)
		{
			i = -1;
			while (write->full_cmd[++i])
				printf("CMD->[%d]: %s\n", i, write->full_cmd[i]);
			printf("[%d]: in: %d out: %d\n",i, write->infile, write->outfile);
			write = write->next;
		}
		printf("##########################################################\n");
	}
	free(env);
}

/**
 * @brief Printing Lexer's all linked list.
 * NOTE: Eger export'la DEFINE=print define etmisse yazdirir.
 * 
 * @param base 
 * @param env_var 
 * @param value 
 */
void	debug_print_str(t_base *base, char *env_name)
{
	char	*env;

	env = env_findret(base->env, env_name);
	if (env != NULL)
	{
		t_lexer *tmp = base->lexer;
		while (tmp)
		{
			printf("			->: STR: %s FLAG: %d\n", tmp->str, tmp->flag);
			tmp = tmp->next;
		}
		printf("##########################################################\n");
	}
	free(env);
}
