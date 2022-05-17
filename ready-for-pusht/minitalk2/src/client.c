/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:12:50 by gsever            #+#    #+#             */
/*   Updated: 2022/05/17 13:24:40 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
	void action function'unda kac tane character gonderildigini, 
server'den --> client'e gonderilen geri dongu olarak kontrol ediyoruz.
*/
static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

/*
Eger gonderilecek bir sinyal varsa (0/1) action'da calistirmaya devam ederiz.
	Yani; "gorkem" stringi gonderilecek,
		 'g' yi gonderirken 'g' = 01100111'i
		 'o' yi gonderirken 'o' = 01101111'i
		 'r' yi gonderirken 'r' = 01110010'i
		 'k' yi gonderirken 'k' = 01101011'i
		 'e' yi gonderirken 'e' = 01100101'i
		 'm' yi gonderirken 'm' = 01101101'i
gondermeye calisiyoruz. 

	'g'den baslayalim -->  'g' = 01100111 -> 01100111
		OK-> i=8 [0]1100111 --> 'g' = 00000000
		OK-> i=7 0[1]100111 --> 'g' = 00000001
		OK-> i=6 01[1]00111 --> 'g' = 00000011
		OK-> i=5 011[0]0111 --> 'g' = 00000110
		OK-> i=4 0110[0]111 --> 'g' = 00001100
		OK-> i=3 01100[1]11 --> 'g' = 00011001
		OK-> i=2 011001[1]1 --> 'g' = 00110011
		OK-> i=1 0110011[1] --> 'g' = 01100111
		KO-> i=0 01100111??????? not entering while loop.
*/
/*
	mt_kill --> minitalk_kill -> It's meaning signal sending program starting.

	Last while loop: For cleaning signal... We are sending 
		8 pieces bit = 1 byte. We must cleaned. It's looking interesting :').

//gorkem --> 'g' characterini = 01100111 sonra o,r,k,e,m
//thinking--> i=8 [0]1100111 --> i=7 0[1]100111
	line 80	-->		//printf("1");
	line 84	-->		//printf("0");

*/
static void	mt_kill(int pid, char *str)

{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

/*
	UNIX SIGNALS --> Bu sinyaller calisan bir programa;
Signal_Name	Signal_Number	Description
SIGHUP		1	Hang up detected on controlling terminal or death of 
	controlling process.
SIGINT		2	Issued if the user sends an interrupt(kesme) signal. (Ctrl + C)
SIGQUIT		3	Issued if the user sends a quit(cikma/bitir) signal. (Ctrl + D)
SIGFPE		8	Issued if an illegal mathematical operation is attempted.
SIGKILL		9	If a process gets this signal it must quit immediately 
	and will not perform any clean-up operations.
SIGALRM		14	Alarm clock signal. (used for timers)
SIGTERM		15	Software termination signal. (sent by kill by default)

				How does signal in C work?
	A signal is a software generated interrupt that is sent to a process 
by the OS because of when user press ctrl-c or another process tell 
something to this process. There are fix set of signals that can be sent 
to a process. signal are identified by integers.
*/
/*
	1-	3 tane argumanimiz haricinde arguman girilmisse ve 3. argumanimizin
icinde bir seyler yazili degilse yani degeri yoksa 1 dondur.
		ornek --> ./client <server PID> <String>
				  ./client 4435 gorkem_sever
				  ./client 4436 🎈
				  ./client 4436 "gorkem_sever 🎈🎈🎈🎈"
	2-	Sent	: 3. argumanimizda kac karakter varsa onu say ve yaz.
	3-	Received: signal.h kutuphanesinde hazir olarak gelen signal() fonk.'da
action 
*/
int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_putstr_fd("Sent	: ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	mt_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
