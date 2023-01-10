/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:49:16 by gsever            #+#    #+#             */
/*   Updated: 2022/10/21 13:11:27 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_pp_str(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		free(line[i++]);
	}
	free(line);
}

void	free_env(t_env **env)
{
	t_env *tmp;

	while (*env != NULL)
	{
		tmp = (*env)->next;
		// if ((*env)->is_env_equal == false)
		// {
		// 	free((*env)->data[0]);
		// 	free((*env)->data[1]);
		// 	free((*env)->data);
		// }
		// else
		free_pp_str((*env)->data);
		free(*env);
		(*env) = tmp;
	}
	*env = NULL;
}

void	free_lexer(t_lexer **lexer)
{
	t_lexer	*tmp;

	while (*lexer)
	{
		tmp = (*lexer)->next;
		free((*lexer)->str);
		free(*lexer);
		(*lexer) = tmp;
	}
	*lexer = NULL;
}

void	free_cmd(t_cmd **cmd)
{
	t_cmd	*tmp;

	while (*cmd)
	{
		tmp = (*cmd)->next;
		free_pp_str((*cmd)->full_cmd);
		free(*cmd);
		(*cmd) = tmp;
	}
	*cmd = NULL;
}

void	free_all(t_base *base)
{
	ft_putendl_fd(RED"exit"END, STDERR_FILENO);
	rl_clear_history();
	free_cmd(&base->cmd);
	free_lexer(&base->lexer);
	free_env(&base->env);
	free(base->input_line);
	free_pp_str(base->env_path);
}