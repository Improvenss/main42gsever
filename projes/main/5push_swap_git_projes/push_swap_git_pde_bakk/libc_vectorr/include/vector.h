/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:48:33 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:48:34 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stdlib.h>
# include <sys/types.h>

# ifndef CONTENT
#  define CONTENT int
# endif

typedef struct s_vector
{
	CONTENT			*arr;
	size_t			size;
	size_t			capacity;
}t_vector;

t_vector	*vector_init(size_t init_size);
void		vector_destroy(t_vector *vec);

void		vector_pushback(t_vector *vec, CONTENT item);
void		vector_delete_bypos(t_vector *vec, size_t pos);
void		vector_delete_byval(t_vector *vec, CONTENT item);

ssize_t		vector_find_by_value(t_vector *vec, CONTENT to_find);
void		vector_sort(t_vector *vec);

//VECTOR_H
#endif
