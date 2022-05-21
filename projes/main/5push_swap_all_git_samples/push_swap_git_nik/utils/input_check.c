/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:32:28 by Nik               #+#    #+#             */
/*   Updated: 2019/08/31 14:15:47 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	is_number(char *s)
{
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static char	*get_valid(char *s)
{
	char *new;

	ft_printf("invalid input {red}%s{eoc}\n", s);
	ft_printf("input valid numer or skip\t");
	while (get_next_line(0, &new))
	{
		if (is_number(new))
			return (new);
		if (ft_strequ(new, "skip"))
		{
			free(new);
			return (NULL);
		}
		ft_printf("{red}%s{eoc} - invalid\n", new);
		ft_printf("input valid numer or skip\t");
		free(new);
	}
	return (NULL);
}

static char	*num_convert(char *s)
{
	if (!ft_strcmp(s, "zero"))
		return ("0");
	else if (!ft_strcmp(s, "one"))
		return ("1");
	else if (!ft_strcmp(s, "two"))
		return ("2");
	else if (!ft_strcmp(s, "three"))
		return ("3");
	else if (!ft_strcmp(s, "four"))
		return ("4");
	else if (!ft_strcmp(s, "five"))
		return ("5");
	else if (!ft_strcmp(s, "six"))
		return ("6");
	else if (!ft_strcmp(s, "seven"))
		return ("7");
	else if (!ft_strcmp(s, "eight"))
		return ("8");
	else if (!ft_strcmp(s, "nine"))
		return ("9");
	else if (!ft_strcmp(s, "ten"))
		return ("10");
	else
		return (get_valid(s));
}

char		*input_checker(char *s, int err_flag)
{
	char *ret;

	ret = s;
	if (!is_number(s))
	{
		if (!err_flag)
			ft_error("invalid input");
		if (!(ret = num_convert(s)))
			return (NULL);
	}
	if (!ft_isinteger(ret))
		ft_error("some arguments are bigger than an integer");
	return (ret);
}
