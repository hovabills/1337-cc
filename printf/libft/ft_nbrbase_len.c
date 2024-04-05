/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrbase_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:35:14 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/03/13 01:35:16 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrbase_len(unsigned long long nbr, size_t blen)
{
	size_t	len;

	len = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= blen;
		len++;
	}
	return (len);
}
