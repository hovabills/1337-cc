#include "printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int len;

	len = 0;
	va_start(args, str);
	while(*str)
	{
		if (*str == '%')
			len += ft_format(++str, args);
			
		len += ft_printchar((char *)str);
		str++;
	}
	va_end(args);
	return (len);
}