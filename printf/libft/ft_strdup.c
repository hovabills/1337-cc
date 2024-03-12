#include "libft.h"

char *ft_strdup(char *str)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(str);
	dup = (char *)malloc(len + 1);
	while (*str)
		*dup++ = *str++;
	*dup = '\0';
	return (dup - len);
}