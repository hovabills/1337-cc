#include "ft_printf.h"

t_fmt *print_fmt(char *str, va_list args)
{
    t_fmt *fmt;

    fmt = parse_fmt(str);
    str += fmt->n_parse;

    if (*str == 'c')
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
    return (fmt);
}


int ft_printf(const char *str, ...)
{
	va_list args;
	t_fmt *fmt;
	int len;

	len = 0;
	va_start(args, str);
	while (*str)
	{	
		if (*str == '%' && *(str + 1) == '%')
		{
			len += ft_putchar('%');
			str += 2;
		}
		else if (*str == '%')
		{
			str++;
			fmt = print_fmt((char *)str, args);
			str += fmt->n_parse;
			len += fmt->n_print;
			// printf("\n\e[0;37mPLUS SIGN: \e[0;32m%c\n", fmt->sign);
			// printf("\e[0;37mALT FMT: \e[0;32m%d\n", fmt->alt_fmt);
			// printf("\e[0;37mLEFT ADJ: \e[0;32m%d\n", fmt->ladj);
			// printf("\e[0;37mPADD CHAR: \e[0;32m%c\n", fmt->padd_ch);
			// printf("\e[0;37mPADD LEN: \e[0;32m%d\n", fmt->padd_len);
			// printf("\e[0;37mPRECISION: \e[0;32m%d\n", fmt->prec);
			// printf("\e[0;37mNUM PARSED \e[0;32m%d\n", fmt->n_parse);
			// printf("\e[0;37mNUM PRINT \e[0;32m%d\e[0;37m\n", fmt->n_print);
			free(fmt);
		}
		else
		{
			len += ft_putchar(*str);
			str++;
		}
	}
	va_end(args);
	return (len);
}