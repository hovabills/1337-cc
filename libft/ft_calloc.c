/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:28:08 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/06 03:25:38 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (!num || !size)
	{
		num = 1;
		size = 1;
	}
	if ((num * size) / size != num)
		return (NULL);
	ptr = malloc(num * size);
	if (ptr)
		ft_bzero(ptr, size * num);
	return (ptr);
}
