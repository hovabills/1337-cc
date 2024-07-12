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

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

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

int main(int ac, char **av)
{
	int pid;
	char *str;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		// TODO: check the validity of the pid
		str = av[2];
		while (*str)
			send_sig(pid, *str++);
	}
}
