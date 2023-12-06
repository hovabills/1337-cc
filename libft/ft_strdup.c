/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:25:35 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/06 01:36:40 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	size_t	slen;
	char	*str2;

	slen = ft_strlen(str1) + 1;
	str2 = (char *)malloc(slen);
	if (str2 != NULL)
		ft_strlcpy(str2, str1, slen);
	return (str2);
}
