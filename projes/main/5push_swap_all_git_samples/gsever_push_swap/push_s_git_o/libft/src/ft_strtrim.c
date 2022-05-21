/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:44:19 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:32:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*so;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	j = ft_strlen(s) - 1;
	while (j >= 0 && ft_isspace(s[j]))
		j--;
	if (j < 0)
		so = ft_strdup("\0");
	else
		so = ft_strsub(s, i, j - i + 1);
	if (!so)
		return (NULL);
	return (so);
}
