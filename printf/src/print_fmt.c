#include "../inc/fmt.h"

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
    if (n || fmt->prec_len > 0 )
        fmt->n_print += ft_putstr(str);
    if (fmt->ladj)
        print_padd(fmt);
    fmt->n_parse++;
    free(str);
}
void print_fmt_u(t_fmt *fmt, int n)
{
    char *str;
    
    str = handle_fmt_u(fmt, n);
    if (!fmt->ladj)
        print_padd(fmt);
    print_prec(fmt);
    if (n || fmt->prec_len > 0 )
        fmt->n_print += ft_putstr(str);
    if (fmt->ladj)
        print_padd(fmt);
    fmt->n_parse++;
    free(str);
}
void print_fmt_xX(t_fmt *fmt, unsigned int n, int upper)
{
    char *str;
    
    str = handle_fmt_xX(fmt, n, upper);
    if (!fmt->ladj)
        print_padd(fmt);
    if (fmt->alt_fmt && n)
    {
        if (upper)
            fmt->n_print += write(1, &"0X", 2);
        else
            fmt->n_print += write(1, &"0x", 2);
    }
    print_prec(fmt);
    if (n || fmt->prec_len > 0 )
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
    print_prec_s(fmt, str);
    if (fmt->ladj)
        print_padd(fmt);
    fmt->n_parse++;
    return;
}




