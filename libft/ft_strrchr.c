/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:25:09 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/06 04:15:23 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	char	*save;

	s = (char *)str;
	save = (char *)0;
	while (*s)
	{
		if (*s == (char)c)
			save = s;
		s++;
	}
	if (c == '\0')
		return (s);
	return (save);
}
