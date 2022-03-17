/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:47:01 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:47:03 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void	fatal_error(const char *s)
{
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	*calloc_wrapper(size_t nmemb, size_t size)
{
	void	*out;

	out = ft_calloc(nmemb, size);
	if (!out)
		fatal_error("Error");
	return (out);
}
