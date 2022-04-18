/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:12:50 by gsever            #+#    #+#             */
/*   Updated: 2022/04/18 01:23:48 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
Eger gonderilecek bir sinyal varsa (0/1) action'da calistirmaya devam ederz.
	Yani; "gorkem" stringi gonderilecek,
		 'g' yi gonderirken 'g' = 01100111'i
		 'o' yi gonderirken 'o' = 01101111'i
		 'r' yi gonderirken 'r' = 01110010'i
		 'k' yi gonderirken 'k' = 01101011'i
		 'e' yi gonderirken 'e' = 01100101'i
		 'm' yi gonderirken 'm' = 01101101'i
gondermeye calisiyoruz. 

	'g'den baslayalim --> 00000000 -> 00000001
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
			if (c >> i & 1)//10010110  --> 00000001 --> 00000111 --> 1 2 3 8 16 32
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
	UNIX SIGNALS --> Bu sinyaller calisan bir programa
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
*/
/*
	1-	3 tane argumanimiz haricinde arguman girilmisse ve 3. argumanimizin
icinde bir seyler yazili degilse yani degeri yoksa 1 dondur.
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
	//ft_putchar_fd('\n', 1);
	ft_putstr_fd("\nReceived: ", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	mt_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
