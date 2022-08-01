/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:34:39 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/15 19:28:12 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_eval_dash(t_print *t_spec, int pos)
{
	t_spec->dash = true;
	return (pos + 1);
}

int	ft_eval_zero(t_print *t_spec, int pos)
{
	t_spec->zero = true;
	t_spec->pad_chr = '0';
	return (pos + 1);
}

int	ft_eval_hashtag(t_print *t_spec, int pos)
{
	t_spec->hashtag = true;
	return (pos + 1);
}

int	ft_eval_space(t_print *t_spec, int pos)
{
	t_spec->space = true;
	return (pos + 1);
}

int	ft_eval_plus(t_print *t_spec, int pos)
{
	t_spec->plus = true;
	t_spec->sign = '+';
	return (pos + 1);
}
