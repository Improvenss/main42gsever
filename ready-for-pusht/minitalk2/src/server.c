/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:12:14 by gsever            #+#    #+#             */
/*   Updated: 2022/05/17 13:25:25 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
		https://www.programiz.com/c-programming/bitwise-operators
	https://www.tutorialspoint.com/cprogramming/c_bitwise_operators.htm
https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B#Operator_precedence
	https://en.wikipedia.org/wiki/Bitwise_operation
	⭐⭐⭐https://realpython.com/python-bitwise-operators/⭐⭐⭐
Operators	Meaning of operators
	&	-->		Bitwise AND
Binary AND Operator copies a bit to the result if it exists in both operands.
	|	-->		Bitwise OR
Binary OR Operator copies a bit if it exists in either operand.
	^	-->		Bitwise XOR
Binary XOR Operator copies the bit if it is set in one operand but not both.
	~	-->		Bitwise complement
Binary One's Complement Operator is unary and has the effect of 'flipping' bits.
	<<	-->		Shift left
Binary Left Shift Operator. The left operands value is moved left 
by the number of bits specified by the right operand.
	>>	-->		Shift right
Binary Right Shift Operator. The left operands value is moved right 
by the number of bits specified by the right operand.
*/
/*
	void (*__sa_sigaction)(int, struct __siginfo *, void *);
		This function using int, struct pointer and void pointer.
//c = c | (sig == SIGUSR2) 00000000 -> 00000001
//c = c << 1  00000001 -> 00000010
*/
static void	faction(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

/*
	What does a signal handler do?
		A signal handler is a function which is called by the target 
environment when the corresponding signal occurs. 
The target environment suspends execution of the program until 
the signal handler returns or calls longjmp(). 
Signal handlers can be set with signal() or sigaction().

	Bir sinyal işleyici ne yapar?
		Bir sinyal işleyici, ilgili sinyal oluştuğunda hedef ortam 
tarafından çağrılan bir fonksiyondur. 
Hedef ortam, sinyal işleyici dönene veya longjmp() öğesini 
çağırana kadar programın yürütülmesini askıya alır. 
Sinyal işleyiciler, signal() veya sigaction() ile ayarlanabilir.
*/
/*
//zaten bellekte olusmus olan PID'i bellekten cekiyorsun
	(numarasini cekiyorsun yani).
//s_sigaction.__sigaction_u.__sa_sigaction = faction; knowledge
//https://stackoverflow.com/questions/12587621/sign
	al-handler-sa-sigaction-arguments
*/
int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = faction;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
