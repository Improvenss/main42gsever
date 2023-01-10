/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:56:51 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/26 21:51:55 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file utils_lexer.c
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

t_lexer	*token_create(t_base *base, char *str, int type)
{
	t_lexer	*new;
	t_lexer	*temp;

	new = (t_lexer *)malloc(sizeof(t_lexer));
	if (!new)
		return (NULL);
	new->flag = type;
	new->str = str;
	new->next = NULL;
	if (base->lexer == NULL)
	{
		base->lexer = new;
		base->lexer->next = NULL;
		new->prev = NULL;
	}
	else
	{
		temp = base->lexer;
		while (temp->next != NULL)
			temp = temp->next;
		new->prev = temp;
		temp->next = new;
	}
	return (new);
}

int	other_lenght(char *str)
{
	if (*str == '<' && *(str + 1) != '<')
		return (1);
	else if (*str == '<' && *(str + 1) == '<')
		return (2);
	else if (*str == '>' && *(str + 1) != '>')
		return (1);
	else if (*str == '>' && *(str + 1) == '>')
		return (2);
	else if (*str == '|' && *(str + 1) != '|' && *(str - 1) != '|')
		return (1);
	return (0);
}

void	node_merge(t_lexer **lexer, char *token, char *str, int *i)
{
	char	*tmp;

	if (!ft_strchr(WHITESPACES, str[*i]) && other_lenght(&str[*i]) == 0)
		(*lexer)->flag = TOK_CONNECTED + TOK_TEXT;
	else if ((*lexer)->prev && (*lexer)->prev->flag & (TOK_REDIR | TOK_HEREDOC))
		(*lexer)->flag = TOK_REDIR_FILE;
	else
		(*lexer)->flag = TOK_TEXT;
	tmp = ft_strjoin((*lexer)->str, token);
	free((*lexer)->str);
	free(token);
	(*lexer)->str = tmp;
}

t_lexer	*lexer_lstlast(t_lexer *lexer)
{
	t_lexer	*tmp;

	if (lexer == NULL)
		return (NULL);
	tmp = lexer;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	lexer_type(t_lexer *last, int type)
{
	if (last != NULL && (last->flag == TOK_REDIR || last->flag == TOK_HEREDOC))
		return (TOK_REDIR_FILE);
	return (type);
}
