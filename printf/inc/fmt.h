#ifndef FMT_H
 #define FMT_H

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>


typedef struct s_fmt 
{
	int ladj; //-
	int alt_fmt; //#
	char sign; //+
	char padd_ch; // 0
	int padd_len; 
	int prec; // .
	int n_parse;
	int n_print;
} t_fmt;

t_fmt *parse_fmt(char *str);
t_fmt *print_fmt(char *str,va_list args);
void handle_fmt_s(t_fmt *fmt, char *s);
char *handle_fmt_d(t_fmt *fmt, int d);
#endif