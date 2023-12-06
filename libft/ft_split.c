/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:25:43 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/06 21:58:54 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(char **p)
{
	while (*p)
	{
		free(*p);
		p++;
	}
	free(p);
	return (NULL);
}

size_t	word_count(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_word_add(char **nstr, char *str, char c)
{
	size_t	i;
	size_t	slen;

	i = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			if (!ft_strchr(str, c))
				slen = ft_strlen(str);
			else
				slen = ft_strchr(str, c) - str;
			nstr[i] = ft_substr(str, 0, slen);
			if (!nstr[i])
				return (ft_free(nstr));
			i++;
			str += slen;
		}
	}
	nstr[i] = NULL;
	return (nstr);
}

char	**ft_split(char const *s, char c)
{
	char	**nstr;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	nstr = (char **)malloc((word_count(str, c) + 1) * sizeof(char *));
	if (nstr)
		ft_word_add(nstr, str, c);
	return (nstr);
}
