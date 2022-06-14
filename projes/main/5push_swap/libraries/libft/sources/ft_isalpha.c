/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:34:05 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:16:49 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//alphabetic characters
int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
