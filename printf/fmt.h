/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:30:47 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/03/13 02:13:19 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_H
# define FMT_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_fmt
{
	int		ladj;
	int		alt_fmt;
	char	sign;
	char	padd_ch;
	int		padd_len;
	int		prec;
	int		prec_len;
	int		n_parse;
	int		n_print;
}			t_fmt;

// utils
void		print_padd(t_fmt *fmt);
void		print_prec_s(t_fmt *fmt, char *str);
void		print_prec(t_fmt *fmt);
void		print_sign(t_fmt *fmt);
void		print_alt_fmt(t_fmt *fmt, int upper);

// parse
t_fmt		*parse_fmt(char *str);

// handle
void		handle_fmt_s(t_fmt *fmt, char *s);
char		*handle_fmt_d(t_fmt *fmt, long d);
char		*handle_fmt_u(t_fmt *fmt, unsigned int d);
char		*handle_fmt_x(t_fmt *fmt, unsigned int n, int upper);
char		*handle_fmt_p(t_fmt *fmt, unsigned long long n);

// print
void		print_fmt_perc(t_fmt *fmt);
void		print_fmt_c(t_fmt *fmt, char ch);
void		print_fmt_s(t_fmt *fmt, char *str);
void		print_fmt_d(t_fmt *fmt, int n);
void		print_fmt_u(t_fmt *fmt, int n);
void		print_fmt_x(t_fmt *fmt, unsigned int n, int upper);
void		print_fmt_p(t_fmt *fmt, unsigned int long long n);

#endif
