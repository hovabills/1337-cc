/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:24:19 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/06 21:12:14 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(long num)
{
	size_t	len;

	len = 0;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void	ft_numlcpy(char *str, long ln, int nlen, int sign)
{
	str[nlen] = '\0';
	while (nlen--)
	{
		str[nlen] = (ln % 10) + '0';
			ln /= 10;
	}
	if (sign)
		*str = '-';
}

char	*ft_itoa(int n)
{
	int		nlen;
	char	*str;
	int		sign;
	long	ln;

	sign = 0;
	ln = n;
	if (ln < 0)
	{
		sign = 1;
		ln *= -1;
	}
	if (!ln)
		return (ft_strdup("0"));
	nlen = ft_numlen(ln) + sign;
	str = (char *)malloc(nlen + 1);
	if (str)
		ft_numlcpy(str, ln, nlen, sign);
	return (str);
}
