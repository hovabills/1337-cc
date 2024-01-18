#include "ft_printf.h"

int	ft_putchar_fmt(struct Format *fmt, char *ch)
{
	return write(0, ch, 1);
} 