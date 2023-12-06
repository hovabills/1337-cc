/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:25:03 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/06 04:21:59 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*str;
	char	*sub;

	if (!s)
		return (0);
	str = (char *)s;
	slen = ft_strlen(str);
	if (start > len || start > slen)
		return (ft_strdup(""));
	str += start;
	slen = ft_strlen(str);
	if (len > slen)
		return (ft_strdup(str));
	(sub = (char *)malloc(len + 1));
	if (sub)
		ft_strlcpy(sub, str, len + 1);
	return (sub);
}
