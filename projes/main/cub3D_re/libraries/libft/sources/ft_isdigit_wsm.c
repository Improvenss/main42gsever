/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_wsm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:19:17 by gsever            #+#    #+#             */
/*   Updated: 2022/11/05 00:57:37 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//Checking char; is it number or space or '-' return 0.
int	ft_isdigit_wsm(char c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '-')
		return (0);
	return (1);
}
