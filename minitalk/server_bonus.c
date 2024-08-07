/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:37:04 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/07/14 00:00:44 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_sig(int sig, siginfo_t *info, void *context)
{
	static int		bit = 8;
	static char		byte;
	static pid_t	pid;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	if (bit-- && sig == SIGUSR1)
		byte = byte | (1 << bit);
	if (!bit)
	{
		if (byte)
		{
			write(1, &byte, 1);
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
			pid = 0;
		}
		bit = 8;
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = handle_sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putstr("The server PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
