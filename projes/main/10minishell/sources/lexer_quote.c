/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:59:37 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/27 09:07:42 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	quote_lenght(char *str)
{
	char	mark;
	int		i;

	if (!str || *str == '\0')
		return (0);
	if (ft_strchr(QUOTE_MARKS, str[0]) == NULL)
		return (0);
	mark = str[0];
	i = 0;
	while (str[++i])
		if (str[i] == mark)
			break ;
	if (str[i] != mark)
	{
		print_error(SHELLNAME, ERR_SYNTAX, NULL, ERR_QUOTE);
		return (ERROR);
	}
	return (i + 1);
}

void	lexer_quote_next_next(t_lexer **new, int *i, int len, char *str)
{
	*i = *i + len;
	if (!ft_strchr(WHITESPACES, str[*i]) && other_lenght(&str[*i]) == 0)
		(*new)->flag |= TOK_CONNECTED;
}

int	lexer_quote_next(t_base *base, t_lexer **new, char *token, char c)
{
	t_lexer	*last;

	last = lexer_lstlast(base->lexer);
	if (!token)
		return (print_error(SHELLNAME, NULL, NULL, strerror(ENOMEM)));
	if (c == '\'')
		*new = token_create(base, token,
				lexer_type(last, TOK_TEXT + TOK_S_QUOTE));
	else
		*new = token_create(base, token,
				lexer_type(last, TOK_TEXT + TOK_D_QUOTE));
	if (!(*new))
		return (print_error(SHELLNAME, NULL, NULL, strerror(ENOMEM)));
	return (1);
}

int	lexer_quote(t_base *base, char *str, int *i)
{
	char	*token;
	int		len;
	t_lexer	*new;
	t_lexer	*last;

	len = quote_lenght(&str[*i]);
	if (len == ERROR)
		return (ERROR);
	if (len > 0)
	{
		token = ft_substr(str, *i + 1, len - 2);
		if (ft_strchr(token, '$') && str[*i] == '"')
			token = env_expand(base, token, 0, 0);
		last = lexer_lstlast(base->lexer);
		if (last && last->flag & TOK_CONNECTED)
		{
			*i = *i + len;
			node_merge(&last, token, str, i);
			return (0);
		}
		if (lexer_quote_next(base, &new, token, str[*i]) == ERROR)
			return (ERROR);
		lexer_quote_next_next(&new, i, len, str);
	}
	return (0);
}
