/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:45:58 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:46:00 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "stack.h"

void			fatal_error(t_collection *stacks, const char *s);
int				cleanup(t_collection *stacks);

unsigned int	amount_digits(int n);
int				atoi_exit_on_error(const char *s, bool *error);
unsigned int	get_max_bits(unsigned int max_num);
void			clearscreen(void);
size_t			get_max_element(const t_stack *stack);

//UTILS_H
#endif
