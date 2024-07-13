/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:37:58 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/07/13 23:59:59 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_sig(pid_t pid, char ch)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (ch >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
	}
}

void	ack_sig(int sig)
{
	static int	count;

	if (sig == SIGUSR1)
	{
		ft_putnbr(count);
		ft_putstr(" Characters have been transmitted successfully!\n");
		exit(0);
	}
	count++;
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*str;

	if (ac == 3)
	{
		if (!ft_isdigit(av[1]))
		{
			ft_putstr("Error: The PID is incorrect");
			return (1);
		}
		pid = ft_atoi(av[1]);
		str = av[2];
		signal(SIGUSR1, ack_sig);
		signal(SIGUSR2, ack_sig);
		while (*str)
			send_sig(pid, *str++);
		send_sig(pid, '\n');
		send_sig(pid, '\0');
		while (1)
		{
		}
	}
	else
		ft_putstr("Error: The number of arguments is incorrect");
	return (0);
}
