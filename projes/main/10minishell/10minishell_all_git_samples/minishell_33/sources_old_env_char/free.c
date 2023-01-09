/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:49:16 by gsever            #+#    #+#             */
/*   Updated: 2022/10/21 15:35:38 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_chr(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		free(line[i++]);
	free(line);
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
		free((*cmd)->full_cmd);
		//chr_free((*cmd)->full_cmd); // lexer içeriği freelendiğinden dolayı freelemeye gerek yok.
		free(*cmd);
		(*cmd) = tmp;
	}
	*cmd = NULL;
}

void	free_all(t_base **base)
{
	ft_putendl_fd(RED"exit"END, STDERR_FILENO);
	rl_clear_history();
	free_cmd(&(*base)->cmd);
	free_lexer(&(*base)->lexer);
	free_chr((*base)->env);
	free_chr((*base)->env_path);
	free((*base)->input_line);
}
