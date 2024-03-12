#include "libft.h"

int ft_putstr(char *str)
{
	if (!str || !*str)
		return (0);
	write(1, str, 1);
	return (1 + ft_putstr(++str));
}