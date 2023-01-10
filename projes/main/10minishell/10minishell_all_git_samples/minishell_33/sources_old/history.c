/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:49:57 by gsever            #+#    #+#             */
/*   Updated: 2022/10/19 16:50:05 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	history_empty_check(char *input_line)
{
	static char	*last_entry;
	int			i;
	int			l;

	if (ft_strcmp_edited(input_line, last_entry) == 0)
		return (0);
	free(last_entry);
	last_entry = ft_strdup(input_line);
	if (!last_entry)
	{
		exit_status(ENOMEM, 0);
		print_error(SHELLNAME, "last_entry", NULL, strerror(ENOMEM));
	}
	l = 0;
	i = 0;
	while (input_line[i])
	{
		if (input_line[i] == ' ')
			l++;
		i++;
	}
	if (i == l)
		return (0);
	return (1);
}
