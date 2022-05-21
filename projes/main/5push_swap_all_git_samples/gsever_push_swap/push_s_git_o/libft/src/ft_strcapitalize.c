/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcapitalize.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 13:53:50 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:32:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (ft_isalpha(str[i]))
		{
			if (str[i - 1] && !ft_isspace(str[i - 1])
				&& str[i - 1] != '+' && str[i - 1] != '-')
				str[i] = ft_tolower(str[i]);
			else
			{
				if (ft_islower(str[i]))
					str[i] = ft_toupper(str[i]);
			}
		}
		i++;
	}
	return (str);
}
