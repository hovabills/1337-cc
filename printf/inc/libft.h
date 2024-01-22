#ifndef LIBFT_H
 #define LIBFT_H

#include <unistd.h>
#include <stdlib.h>

int ft_isdigit(char ch);
int	ft_putchar(char ch);
int	ft_putstr(char *str);
int	ft_putnstr(char *str, int n);
int	ft_strlen(char *str);
char *ft_itoa(long long nbr);

#endif