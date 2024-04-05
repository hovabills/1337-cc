/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:36:17 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/03/13 01:36:18 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(str);
	dup = (char *)malloc(len + 1);
	while (*str)
		*dup++ = *str++;
	*dup = '\0';
	return (dup - len);
}
