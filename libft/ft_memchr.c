/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:26:41 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/06 04:01:40 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*ch;
	size_t			i;

	i = 0;
	ch = (unsigned char *)ptr;
	while (i < n)
	{
		if (ch[i] == (unsigned char)c)
			return (&ch[i]);
		i++;
	}
	return (NULL);
}
