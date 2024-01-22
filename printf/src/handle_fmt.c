#include "fmt.h"

char *handle_fmt_d(t_fmt *fmt, int n)
{
    long long nbr;
    int slen;
    char *str;

    nbr = n;
    if (nbr < 0)
    {
        fmt->sign = '-';
        nbr *= -1;
    }
    str = ft_itoa(nbr);
    slen = ft_strlen(str);
    fmt->prec -= slen;
    fmt->padd_len -= slen;
    if (fmt->prec > 0)
        fmt->padd_len -= fmt->prec;
    if (fmt->sign)
        fmt->padd_len--;
    if (fmt->ladj || fmt->prec > 0)
        fmt->padd_ch = ' ';
    return (str);
}

void handle_fmt_s(t_fmt *fmt, char *str)
{
    int slen;

    fmt->padd_ch = ' ';
    slen = ft_strlen(str);
    if (slen <= fmt->prec || fmt->prec == -1)
    {
        fmt->padd_len -= slen;
        fmt->prec = slen;
    }
    else 
        fmt->padd_len -= fmt->prec; 
}