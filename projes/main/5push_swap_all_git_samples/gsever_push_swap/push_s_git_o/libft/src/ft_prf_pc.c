/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_pc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 18:57:24 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 18:15:46 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			prf_pc(va_list args, const t_format *opt)
{
	char	zero;

	(void)args;
	zero = contains(opt->flags, '0') ? '0' : ' ';
	putnchar(!contains(opt->flags, '-') * (opt->width - 1), zero);
	write(1, "%", 1);
	putnchar(contains(opt->flags, '-') * (opt->width - 1), zero);
	return (opt->width < 1 ? 1 : opt->width);
}
