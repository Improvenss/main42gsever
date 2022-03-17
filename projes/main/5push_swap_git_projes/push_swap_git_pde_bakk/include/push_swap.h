/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:45:47 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:45:48 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"
# include "stack.h"

int		is_valid_arg(const char *s);
void	parse_array(t_collection *stacks, char **argv, int i);
void	parse_split_array(t_collection *coll, char *s);

//PUSH_SWAP_H
#endif
