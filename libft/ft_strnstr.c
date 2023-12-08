/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:25:12 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/07 03:15:49 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*b;
	char	*s;

	i = 0;
	b = (char *)big;
	s = (char *)small;
	slen = ft_strlen(s);
	if (!slen)
		return (b);
	while (b[i] && (i + slen) <= len)
	{
		if (ft_strncmp(b + i, s, slen) == 0)
			return (b + i);
		i++;
	}
	return (NULL);
}
