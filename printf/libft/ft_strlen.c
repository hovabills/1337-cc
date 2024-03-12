#include "libft.h"

int ft_strlen(char *str)
{
	int len;
	
	len = 0;
	if (!str)
		return (0);
	while(*str++)
		len++;
	return len;
}
