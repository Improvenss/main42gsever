/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:07:43 by Nik               #+#    #+#             */
/*   Updated: 2019/08/21 16:35:33 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#define COMMANDS "sa sb ss pa pb ra rb rr rra rrb rrr"

int		is_command(char *cmd)
{
	int len;

	len = ft_strlen(cmd);
	if (ft_strstr(COMMANDS, cmd) && len > 1 && len < 4 && !ft_strchr(cmd, ' '))
		return (1);
	ft_printf("{red}%s{eoc} - not a command\n", cmd);
	return (0);
}
