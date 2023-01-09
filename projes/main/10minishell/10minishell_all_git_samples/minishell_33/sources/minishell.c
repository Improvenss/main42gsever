/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:47:06 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/13 08:47:06 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file minishell.c
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
 * @brief Bash shell starting here.
 * 
 * @param base 
 * @note errno -> errno.h'ta tanimli errno; Donus degerlerini tutmak icin.
*/
void	minishell(t_base *base)
{
	signal(SIGQUIT, SIG_IGN);
	commands_init(base);
	while (1)
	{
		signal(SIGINT, action);
		base->input_line = readline(T_NAME);
		if (!base->input_line)
			break;
		if (history_empty_check(base->input_line))
		 	add_history(base->input_line);
		lexer(base, base->input_line);
		if (lexer_syntax(base->lexer) == ERROR)
			exit_status(1, 0);
		else
			cmd(base);
		free_cmd(&base->cmd);
		free_lexer(&base->lexer);
		free(base->input_line);
	}
	free_all(base);
}
