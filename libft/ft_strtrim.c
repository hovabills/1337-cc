/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:25:06 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/07 03:12:37 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	char	*start;
	char	*end;

	if (!s1 || !set)
		return ("\0");
	start = (char *)s1;
	end = start + ft_strlen(s1) - 1;
	while (*start && ft_strchr(set, *start))
		start++;
	if (!*start)
		return (ft_strdup(""));
	while (*end && ft_strchr(set, *end))
		end--;
	trim = (char *)malloc(end - start + 2);
	if (trim)
		ft_strlcpy(trim, start, end - start + 2);
	return (trim);
}
