/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:21:53 by fcil              #+#    #+#             */
/*   Updated: 2021/12/04 01:49:22 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < size && *dest)
		dest++;
	if (i == size)
		return (i + (unsigned int)ft_strlen(src));
	j = -1;
	while (src[++j])
		if (j < size - i - 1)
			*dest++ = src[j];
	*dest = '\0';
	return (i + j);
}
