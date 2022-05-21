/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:07:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/30 02:16:36 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../utils/utils.h"

int		get_command(int *stack_a, int *stack_b, t_push flags);
void	print_man(void);
void	usage(void);
int		multi_commander(char *cmd, int *stack_a, int *stack_b);
void	push_help(int *stack_a, int *stack_b);

#endif
