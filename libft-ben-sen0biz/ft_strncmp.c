/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:58:01 by gsever            #+#    #+#             */
/*   Updated: 2022/02/04 18:51:45 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//this s1-s2=109 -> m-0=m=109 -----> 0 = NULL
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
void	ft_strncmp_test(void)
{
	char str1[15] = "gorkem";
	char str2[15] = "gorke";
	char original_str1[15] = "gorkem";
	char original_str2[15] = "gorke";
	int ret;
	int original_ret;

	ret = ft_strncmp(str1, str2, 6);
	original_ret = strncmp(original_str1, original_str2, 6);
	if(ret < 0)
		printf("str2 > str1 |%d|\n", ret);
	else if(ret > 0)
		printf("str1 > str2 |%d|\n", ret);
	else
		printf("str1 = str2 |%d|\n", ret);
	if(ret < 0)
		printf("str2 > str1 |%d|\n", original_ret);
	else if(ret > 0)
		printf("str1 > str2 |%d|\n", original_ret);
	else
		printf("str1 = str2 |%d|\n", original_ret);
}

int main()
{
    ft_strncmp_test();
}
*/