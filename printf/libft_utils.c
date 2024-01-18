#include "ft_printf.h"

int ft_isdigit(char ch)
{
	if(ch >= '0' && ch <= '9')
		return (1);
	return (0);	
}
int	ft_putchar(char *ch)
{
	return write(0, ch, 1);
} 

int	ft_putstr(char *str)
{
	if (!*str)
		return (-1);
	write(0, str, 1);
	return (0 + ft_putstr(++str));
}