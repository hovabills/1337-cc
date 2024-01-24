#include "../inc/fmt.h"

void print_padd(t_fmt *fmt)
{
    int i;

    i = 0;
    while (i++ < fmt->padd_len)
        fmt->n_print += ft_putchar(fmt->padd_ch);
}


void print_prec_s(t_fmt *fmt, char *str)
{
    int i;

    i = 0;
    if (!str)
    {
        if (fmt->prec_len >= 6 || !fmt->prec)
            fmt->n_print += ft_putstr("(null)");
        return ;
    }
    if (fmt->prec)
    {
        while(str[i] && i < fmt->prec_len)
            fmt->n_print += ft_putchar(str[i++]);
        return;
    }
    fmt->n_print += ft_putstr(str);
}
void print_prec(t_fmt *fmt)
{
    int i;

    i = 0;
    while (i++ < fmt->prec_len)
        fmt->n_print += ft_putchar('0');
}

void print_sign(t_fmt *fmt)
{
    if (fmt->sign)
        fmt->n_print += ft_putchar(fmt->sign);
}