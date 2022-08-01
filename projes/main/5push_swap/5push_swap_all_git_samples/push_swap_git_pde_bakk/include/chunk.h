/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:45:29 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:45:39 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_H
# define CHUNK_H

# include <stdbool.h>
# include <stdlib.h>
# include "stack.h"

typedef struct s_chunk {
	short int	nb;
	short int	size;
	int			min;
	int			max;
}				t_chunk;

t_chunk	chunk_init(int nb, int size);
void	chunk_decrease(t_chunk *chunk);
void	chunk_increase(t_chunk *chunk);

int		get_chunk_size(t_stack *stack);
bool	is_within_chunk(int item, const t_chunk *chunk);

//CHUNK_H
#endif
