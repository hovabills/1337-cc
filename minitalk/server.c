/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:37:53 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/07/12 04:31:19 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void handle_sig(int sig)
{
	static int bit = 8;
	static char byte;

	if (bit-- && sig == SIGUSR1)
		byte |= (1 << bit);
	if (!bit)
	{
		write(1, &byte, 1);
		bit = 8;
		byte = 0;
	}
}

int main()
{
	pid_t pid = getpid();
	printf("%d\n", pid);
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	while (1)
	{
		pause();
	}
}
