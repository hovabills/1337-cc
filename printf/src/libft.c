#include "libft.h"


int ft_strlen(char *str)
{
	int len;
	
	len = 0;
	while(*str++)
		len++;
	return len;
}

size_t ft_nbrlen(long long nbr)
{
	size_t len;

	len = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
int ft_isdigit(char ch)
{
	if(ch >= '0' && ch <= '9')
		return (1);
	return (0);	
}
int	ft_putchar(char ch)
{
	return write(1, &ch, 1);
} 

int ft_putstr(char *str)
{
	if (!*str)
		return (0);
	write(1, str, 1);
	return (1 + ft_putstr(++str));
}

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

char *ft_itoa(long long nbr)
{
	int len;
	char *str;

	len = ft_nbrlen(nbr);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (nbr)
	{	
		str[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}