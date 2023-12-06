/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:25:27 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/06 03:13:10 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	if (!size)
		return (slen);
	dlen = ft_strlen(dest);
	if (size > dlen)
		return (ft_strlcpy(dest + dlen, src, size - dlen) + dlen);
	return (size + slen);
}
