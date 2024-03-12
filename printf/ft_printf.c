#include "ft_printf.h"

t_fmt *print_fmt(char *str, va_list args)
{
    t_fmt *fmt;

    fmt = parse_fmt(str);
    str += fmt->n_parse;

    if (*str == '%')
        print_fmt_perc(fmt);
    else if (*str == 'c')
        print_fmt_c(fmt, va_arg(args, int));
    else if (*str == 's')
        print_fmt_s(fmt, va_arg(args, char *));
    else if (*str == 'd' || *str == 'i')
        print_fmt_d(fmt, va_arg(args, int));
    else if (*str == 'u')
        print_fmt_u(fmt, va_arg(args, unsigned int));
    else if (*str == 'x')
        print_fmt_xX(fmt, va_arg(args, unsigned int), 0);
    else if (*str == 'X')
        print_fmt_xX(fmt, va_arg(args, unsigned int), 1);
	else if (*str == 'p')
        print_fmt_p(fmt, va_arg(args, unsigned long int));
    return (fmt);
}


int ft_printf(const char *str, ...)
{
	va_list args;
	t_fmt *fmt;
	int len;

	if (!str)
		return (-1);
	len = 0;
	va_start(args, str);
	while (*str)
	{	
		if (*str++ == '%')
		{
			fmt = print_fmt((char *)str, args);
			str += fmt->n_parse;
			len += fmt->n_print;
			free(fmt);
		}
		else 
			len += ft_putchar(*(str - 1));
	}
	va_end(args);
	return (len);
}
