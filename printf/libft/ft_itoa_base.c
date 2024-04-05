/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:35:01 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/03/13 01:35:03 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long long nbr, char *base, int blen)
{
	size_t	len;
	char	*str;

	len = ft_nbrbase_len(nbr, blen);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nbr == 0)
	{
		*str = '0';
		return (str);
	}
	while (nbr)
	{
		str[len--] = base[nbr % blen];
		nbr /= blen;
	}
	return (str);
}
