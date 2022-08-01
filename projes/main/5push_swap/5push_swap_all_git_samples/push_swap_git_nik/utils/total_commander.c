/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_commander.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:23:17 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/29 22:01:45 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	totle_commander(char *cmd, int *stack_a, int *stack_b)
{
	ft_printf("%s\n", cmd);
	commander(cmd, stack_a, stack_b);
}
