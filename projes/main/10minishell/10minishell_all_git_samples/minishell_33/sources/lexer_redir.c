/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:50:43 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/19 15:13:38 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	redir_type(char *token)
{
	if (ft_strncmp_edited(token, "<", 1))
		return (TOK_REDIR);
	if (ft_strncmp_edited(token, ">", 1))
		return (TOK_REDIR);
	if (ft_strncmp_edited(token, "<<", 2))
		return (TOK_HEREDOC);
	if (ft_strncmp_edited(token, ">>", 2))
		return (TOK_HEREDOC);
	return (1);
}

int	lexer_redir(t_base *base, char *str, int *i)
{
	char	*token;
	int		len;
	t_lexer	*new;

	len = 0;
	while (ft_isdigit(str[*i + len])) // 1 > 1.txt
		len++;
	if (str[*i + len] == '<' || str[*i + len] == '>')
	{
		if (str[*i + len] == str[*i + len + 1])
			len++;
		len++;
		token = ft_substr(str, *i, len);
		if(!token)
			return (print_error(SHELLNAME, NULL, NULL, strerror(ENOMEM)));
		new = token_create(base, token, redir_type(token));//TOK_REDIR);
		if (!new)
			return (print_error(SHELLNAME, NULL, NULL, strerror(ENOMEM)));
		*i = *i + len;
	}
	return (0);
}
