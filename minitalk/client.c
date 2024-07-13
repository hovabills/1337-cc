/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:37:49 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/07/12 03:38:47 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_sig(pid_t pid, char ch)
{
	int bit;

	bit = 8;
	while (bit--)
	{
		if (ch >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(600);
	}
}

int main(int ac, char **av)
{
	int pid;
	char *str;

	if (ac == 3)
	{
		if (!ft_isdigit(av[1]))
		{
			ft_putstr("Error: The PID is incorrect");
			return (1);
		}	
		pid = ft_atoi(av[1]);
		str = av[2];
		while (*str)
			send_sig(pid, *str++);
		send_sig(pid, '\n');
	}
	else
		ft_putstr("Error: The number of argument is incorrect");
	return (0);
}
