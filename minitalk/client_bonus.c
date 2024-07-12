/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:37:58 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/07/12 04:37:31 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


int ft_atoi(char *str)
{
	int sign;
	int num;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + *str++ - '0';
	return (num * sign);
}

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
		usleep(777);
	}
}

void ack_sig(int sig)
{
	static int count;

	if (sig == SIGUSR1)
	{
		printf("\033[32m %d Characters have been transmitted successfully!\n", count);
		exit(0);
	}
	count++;
}

int main(int ac, char **av)
{
	int pid;
	char *str;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		// TODO: check the validity of the pid
		str = av[2];
		signal(SIGUSR1, ack_sig);
		signal(SIGUSR2, ack_sig);
		while (*str)
			send_sig(pid, *str++);
		send_sig(pid, '\0');
		while (1)
			pause();
	}
}
