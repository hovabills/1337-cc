/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:25:29 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/06 04:20:39 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	slen1;
	size_t	slen2;
	size_t	slen3;
	char	*s3;

	slen1 = ft_strlen((char *)s1);
	slen2 = ft_strlen((char *)s2);
	slen3 = slen1 + slen2 + 1;
	s3 = (char *)malloc(slen3);
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, slen3);
	ft_strlcat(s3, s2, slen3);
	return (s3);
}
