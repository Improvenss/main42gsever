/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:32:29 by gsever            #+#    #+#             */
/*   Updated: 2022/10/26 21:32:54 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/**
 * @brief PDF'den istenilen komutlarimizi burada base->commands[]'i
 *  t_commands structuna init ediyoruz.
 * 
 * Terminal'imize girilen girdimizde buradaki komutlardan biri varsa sahip
 *  olduklari functionlari calistirilacak.
 * 
 * @param base base->commands[8]'in icine init ediyoruz.
 * @fn cmd_echo()
 * @fn cmd_cd()
 * @fn cmd_pwd()
 * @fn cmd_unset()
 * @fn cmd_export()
 * @fn cmd_env()
 * @fn cmd_exit()
 */
void	commands_init(t_base *base)
{
	base->commands[0] = (t_commands){"echo", cmd_echo};
	base->commands[1] = (t_commands){"cd", cmd_cd};
	base->commands[2] = (t_commands){"pwd", cmd_pwd};
	base->commands[3] = (t_commands){"unset", cmd_unset};
	base->commands[4] = (t_commands){"export", cmd_export};
	base->commands[5] = (t_commands){"env", cmd_env};
	base->commands[6] = (t_commands){"exit", cmd_exit};
	base->commands[7] = (t_commands){NULL, NULL};
}
