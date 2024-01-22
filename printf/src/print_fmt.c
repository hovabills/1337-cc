#include "fmt.h"

void print_padd(t_fmt *fmt)
{
    int i;

    i = 0;
    while (i++ < fmt->padd_len)
        fmt->n_print += ft_putchar(fmt->padd_ch);
}

void print_prec(t_fmt *fmt)
{
    int i;

    i = 0;
    while (i++ < fmt->prec)
        fmt->n_print += ft_putchar('0');
}

void print_sign(t_fmt *fmt)
{
    if (fmt->sign)
        fmt->n_print += ft_putchar(fmt->sign);
}


void print_fmt_c(t_fmt *fmt, char ch)
{
    fmt->padd_len--;
    fmt->padd_ch = ' ';
    if (!fmt->ladj)
        print_padd(fmt);
    fmt->n_print += ft_putchar(ch);
    if (fmt->ladj)
        print_padd(fmt);
    fmt->n_parse++;
}

void print_fmt_d(t_fmt *fmt, int n)
{
    char *str;
    
    str = handle_fmt_d(fmt, n);
    if (!fmt->ladj)
        print_padd(fmt);
    print_sign(fmt);
    print_prec(fmt);
    fmt->n_print += ft_putstr(str);
    if (fmt->ladj)
        print_padd(fmt);
    fmt->n_parse++;
    free(str);
}


void print_fmt_s(t_fmt *fmt, char *str)
{
    handle_fmt_s(fmt, str);
    if (!fmt->ladj)
        print_padd(fmt);
    fmt->n_print += ft_putnstr(str, fmt->prec);
    if (fmt->ladj)
        print_padd(fmt);
    fmt->n_parse++;
    return;
}

t_fmt *print_fmt(char *str, va_list args)
{
    t_fmt *fmt;

    fmt = parse_fmt(str);
    str += fmt->n_parse;
    switch (*str)
    {
    case 'c':
        print_fmt_c(fmt, va_arg(args, int));
        break;
    case 's':
        print_fmt_s(fmt, va_arg(args, char *));
        break;
    case 'd':
        print_fmt_d(fmt, va_arg(args, int));
        break;
    default:
        break;
    }
    return (fmt);
}


