#include "libft.h"

int	ft_putnstr(char *str, int n)
{
	int	i;

	i = 0;
	while(i < n && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return i;
}