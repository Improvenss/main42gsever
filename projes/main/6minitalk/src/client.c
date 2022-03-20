/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:47:03 by gsever            #+#    #+#             */
/*   Updated: 2022/03/20 04:35:27 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct	sigaction	s_sigaction;
	ft_putstr_fd("Server PID ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd("\n", 1);
	
}