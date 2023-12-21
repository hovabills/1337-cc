#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10000000 
#endif

size_t	ft_strlen(char *str);
void	ft_strcpy(char *dst, char *src);
void	ft_strcat(char *dst, char *src);
char	*ft_strchrnl(char *str);
char	*ft_substr(char *str, size_t len);
char 	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);

#endif

