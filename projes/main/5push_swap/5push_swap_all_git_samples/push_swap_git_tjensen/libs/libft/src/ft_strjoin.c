/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:11:53 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/14 11:23:22 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	joined_size;
	char	*joined_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined_str = malloc(joined_size * sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	ft_strlcpy(joined_str, s1, joined_size);
	ft_strlcat(joined_str, s2, joined_size);
	return (joined_str);
}
