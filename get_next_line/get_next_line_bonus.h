/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:59:08 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/01/14 02:59:12 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1 
# endif

size_t	ft_strlen(char *str);
char	*ft_strchrnl(char *str);
char	*ft_substr(char *str, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*get_next_line(int fd);

#endif
