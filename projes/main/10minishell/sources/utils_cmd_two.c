/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:56:02 by gsever            #+#    #+#             */
/*   Updated: 2022/10/27 00:57:00 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file utils_cmd_two.c
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

t_lexer	*cmd_node_create_set(t_lexer *tmp, t_cmd **new, int *i, int *l)
{
	*i = 0;
	*l = 0;
	while (tmp && tmp->flag != TOK_PIPE)
	{
		if (tmp->flag & (TOK_TEXT | TOK_D_QUOTE | TOK_S_QUOTE))
		{
			if (tmp->str[0] != '\0')
			{
				(*new)->full_cmd[*i] = ft_strdup(tmp->str);
				(*i)++;
			}
		}
		else if (tmp->flag & (TOK_REDIR | TOK_HEREDOC | TOK_REDIR_FILE))
		{
			if (tmp->str[0] != '\0')
			{
				(*new)->redirect[*l] = ft_strdup(tmp->str);
				(*l)++;
			}
		}
		tmp = tmp->next;
	}
	return (tmp);
}

t_lexer	*cmd_node_create(t_cmd **new, t_lexer *last, int i, int l)
{
	t_lexer	*tmp;

	tmp = last;
	*new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!*new)
		return (NULL);
	(*new)->full_cmd = (char **)malloc(sizeof(char *) * (i + 1));
	if (!(*new)->full_cmd)
		return (NULL);
	(*new)->redirect = (char **)malloc(sizeof(char *) * (l + 1));
	if (!(*new)->redirect)
		return (NULL);
	(*new)->infile = STDIN_FILENO;
	(*new)->outfile = STDOUT_FILENO;
	(*new)->next = NULL;
	tmp = last;
	tmp = cmd_node_create_set(tmp, new, &i, &l);
	(*new)->full_cmd[i] = NULL;
	(*new)->redirect[l] = NULL;
	(*new)->size = i;
	(*new)->red_size = l;
	return (tmp);
}

t_lexer	*cmd_create(t_cmd **lst, t_lexer *last)
{
	t_lexer	*tmp;
	t_cmd	*new;
	int		i;
	int		l;

	new = NULL;
	tmp = last;
	i = 0;
	l = 0;
	while (tmp && tmp->flag != TOK_PIPE)
	{
		if (tmp->flag & (TOK_TEXT | TOK_D_QUOTE | TOK_S_QUOTE))
			i++;
		else
			l++;
		tmp = tmp->next;
	}
	tmp = cmd_node_create(&new, last, i, l);
	cmd_lstadd_back(lst, new);
	if (tmp && tmp->flag == TOK_PIPE)
		tmp = tmp->next;
	return (tmp);
}

t_cmd	*cmd_lstlast(t_cmd *cmd)
{
	t_cmd	*tmp;

	if (cmd == NULL)
		return (NULL);
	tmp = cmd;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
