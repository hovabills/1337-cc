/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:22:03 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:45:15 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *str)
{
	int		sign;
	long	lnum;

	sign = 1;
	lnum = 0;
	while (*str == ' ' || *str == '\n' || *str == '\r' || *str == '\t')
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (lnum * sign);
		lnum = lnum * 10 + *str - '0';
		str++;
	}
	return (lnum * sign);
}
