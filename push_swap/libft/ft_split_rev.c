/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:22:14 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:41:07 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char *str, char ch)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == ch)
			str++;
		if (*str)
			count++;
		while (*str && *str != ch)
			str++;
	}
	return (count);
}

char	*ft_strdup_br(char **str, char br)
{
	size_t	size;
	char	*dup;

	size = 0;
	while ((*str)[size] && (*str)[size] != br)
		size++;
	dup = (char *)malloc(size + 1);
	if (!dup)
		return (0);
	dup[size] = '\0';
	while (**str && **str != br)
		*dup++ = *(*str)++;
	return (dup - size);
}

void	free_double(char **str)
{
	char	**head;

	head = str;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(head);
}

char	**ft_split_rev(char *str, char ch)
{
	char	**words;
	size_t	size;

	size = ft_count_words(str, ch);
	words = (char **)malloc(sizeof(char *) * (size + 1));
	if (!words)
		return (NULL);
	words[size--] = NULL;
	while (*str)
	{
		while (*str && *str == ch)
			str++;
		if (*str)
		{
			words[size] = ft_strdup_br(&str, ch);
			if (!words[size])
				return (free_double(words), NULL);
			size--;
		}
	}
	return (words);
}
