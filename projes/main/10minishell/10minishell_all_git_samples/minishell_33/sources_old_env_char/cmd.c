/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:46:00 by gsever            #+#    #+#             */
/*   Updated: 2022/10/21 15:45:19 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_lexer	*cmd_node_create(t_cmd **new, t_lexer *last, int i)
{
	t_lexer *tmp;

	tmp = last;
	*new = malloc(sizeof(t_cmd));
	if (!*new)
		return (NULL);
	(*new)->full_cmd = (char **)malloc(sizeof(char *) * i + 1);
	if (!(*new)->full_cmd)
		return (NULL);
	(*new)->full_path = NULL;
	(*new)->infile = STDIN_FILENO;
	(*new)->outfile = STDOUT_FILENO;
	(*new)->next = NULL;
	tmp = last;
	i = 0;
	while (tmp && tmp->flag != TOK_PIPE)
	{
		if (tmp->flag & (TOK_TEXT | TOK_D_QUOTE | TOK_S_QUOTE))//if (tmp->flag == TOK_TEXT)
		{
			(*new)->full_cmd[i] = tmp->str;//ft_strdup(tmp->str); //lexer içeriğini eşitliyoruz.
			i++;
		}
		cmd_set_fd(tmp, new);
		tmp = tmp->next;
	}
	(*new)->full_cmd[i] = NULL;
	return (tmp);
}

t_lexer	*cmd_create(t_cmd **lst, t_lexer *last)
{	
	t_lexer *tmp;
	t_cmd	*new;
	int		i;

	new = NULL;
	tmp = last;
	i = 0;
	while (tmp && tmp->flag != TOK_PIPE)
	{
		if (tmp->flag & (TOK_TEXT | TOK_D_QUOTE | TOK_S_QUOTE))
			i++;
		tmp = tmp->next;
	}
	tmp = cmd_node_create(&new, last, i);
	cmd_lstadd_back(lst, new);
	if (tmp && tmp->flag == TOK_PIPE)
		tmp = tmp->next;
	return (tmp);
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
	debug_print_cmd(base, DEBUG_ENV);
	if (fork_init(base) == 0)
	{
		print_error(SHELLNAME, "fork", NULL, "Cannot allocate memory");
		cmd_exit(base, base->cmd);
	}
	fork_start(base);
}
