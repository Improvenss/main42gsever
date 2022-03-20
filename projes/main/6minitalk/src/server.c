/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:47:18 by gsever            #+#    #+#             */
/*   Updated: 2022/03/20 05:13:26 by gsever           ###   ########.fr       */
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