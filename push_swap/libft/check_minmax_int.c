/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minmax_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:21:55 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:46:53 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_minmax_int(char *str)
{
	long	lnum;

	lnum = ft_atol(str);
	if (lnum < INT_MIN || lnum > INT_MAX)
		return (1);
	return (0);
}
