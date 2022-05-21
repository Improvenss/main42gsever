/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:45:42 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:45:45 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "stack.h"
# include "opcode.h"

typedef void	(*t_operation)();

t_opcode	string2opcode(const char *str);
void		execute_operation(t_opcode opcode, t_collection *collection);
void		print_operation(t_opcode opcode, int fd);

void		sa(t_collection *collection);
void		sb(t_collection *collection);
void		ss(t_collection *collection);
void		pa(t_collection *collection);
void		pb(t_collection *collection);
void		ra(t_collection *collection);
void		rb(t_collection *collection);
void		rr(t_collection *collection);
void		rra(t_collection *collection);
void		rrb(t_collection *collection);
void		rrr(t_collection *collection);

//OPERATIONS_H
#endif
