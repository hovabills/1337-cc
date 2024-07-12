/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:37:04 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/07/12 04:29:42 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_sig(int sig, siginfo_t *info, void *context)
{
	static int bit = 8;
	static char byte;
	static pid_t pid;

	if (!pid)
		pid = info->si_pid;
	if (bit-- && sig == SIGUSR1)
		byte = byte | (1 << bit);
	if (!bit)
	{
		if (byte)
		{
			write(1, &byte, 1);
			bit = 8;
			byte = 0;
			kill(SIGUSR2, pid);
		}
		else
		{
			kill(SIGUSR1, pid);
			pid = 0;
		}
	}
}

int main()
{
	struct sigaction sa;

	pid_t pid = getpid();
	printf("%d\n", pid);
	sa.sa_sigaction = handle_sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
