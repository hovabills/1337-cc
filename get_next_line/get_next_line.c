/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 02:47:09 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/21 06:20:12 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_left_line(int fd, char *left_line)
{
	int		rb;
	char	*buff;
	char	*tmp_line;

	rb = 1;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchrnl(left_line) && rb)
	{
		rb = read(fd, buff, BUFFER_SIZE);
		if (rb == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rb] = '\0';
		tmp_line = left_line;
		left_line = ft_strjoin(left_line, buff);
		free(tmp_line);
	}
	free(buff);
	return (left_line);
}

char	*set_left_line(char *left_line)
{
	char	*nl;
	char	*tmp_line;

	nl = ft_strchrnl(left_line);
	if (nl)
	{
		tmp_line = ft_strdup(nl + 1);
		free(left_line);
		return (tmp_line);
	}
	return (NULL);
}

char	*set_next_line(char *left_line)
{
	char	*nl;

	nl = ft_strchrnl(left_line);
	if (nl)
		return (ft_substr(left_line, (nl + 1) - left_line));
	return (left_line);
}

char	*get_next_line(int fd)
{
	static char	*left_line;
	char		*next_line;

	left_line = get_left_line(fd, left_line);
	if (!left_line || !*left_line)
		return (NULL);
	next_line = set_next_line(left_line);
	left_line = set_left_line(left_line);
	return (next_line);
}
