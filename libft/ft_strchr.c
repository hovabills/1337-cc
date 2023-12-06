/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:25:37 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/06 03:49:44 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	ch;
	char	*s;

	ch = (char)c;
	s = (char *)str;
	while (*s)
	{
		if (*s == ch)
			return (s);
		s++;
	}
	if (ch == '\0')
		return (s);
	return (NULL);
}
