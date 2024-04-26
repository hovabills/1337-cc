/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:56:30 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/01/17 00:09:53 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_left_line(int fd, char *left_line)
{
	int		rd;
	char	*buff;
	char	*tmp_line;

	buff = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd = 1;
	while (rd && !(ft_strchrnl(left_line)))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			free(left_line);
			return (NULL);
		}
		buff[rd] = '\0';
		tmp_line = left_line;
		left_line = ft_strjoin(left_line, buff);
		free(tmp_line);
	}
	free(buff);
	return (left_line);
}

char	*set_next_line(char *left_line)
{
	char	*nl;

	if (!*left_line)
		return (NULL);
	nl = ft_strchrnl(left_line);
	if (!nl)
		return (ft_strdup(left_line));
	return (ft_substr(left_line, nl + 1 - left_line));
}

char	*set_left_line(char *left_line)
{
	char	*nl;
	char	*new_left_line;

	nl = ft_strchrnl(left_line);
	if (!nl)
	{
		free(left_line);
		return (NULL);
	}
	new_left_line = ft_strdup(nl + 1);
	free(left_line);
	return (new_left_line);
}

char	*get_next_line(int fd)
{
	static char	*left_line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	left_line = read_left_line(fd, left_line);
	if (!left_line)
		return (NULL);
	next_line = set_next_line(left_line);
	left_line = set_left_line(left_line);
	return (next_line);
}
