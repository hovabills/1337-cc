/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:31:11 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/03/13 02:15:28 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_fmt_perc(t_fmt *fmt)
{
	fmt->n_print += ft_putchar('%');
	fmt->n_parse++;
}

void	print_fmt_c(t_fmt *fmt, char ch)
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

void	print_fmt_s(t_fmt *fmt, char *str)
{
	handle_fmt_s(fmt, str);
	if (!fmt->ladj)
		print_padd(fmt);
	print_prec_s(fmt, str);
	if (fmt->ladj)
		print_padd(fmt);
	fmt->n_parse++;
	return ;
}

t_fmt	*print_fmt(char *str, va_list args)
{
	t_fmt	*fmt;

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
		print_fmt_x(fmt, va_arg(args, unsigned int), 0);
	else if (*str == 'X')
		print_fmt_x(fmt, va_arg(args, unsigned int), 1);
	else if (*str == 'p')
		print_fmt_p(fmt, va_arg(args, unsigned long int));
	return (fmt);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_fmt	*fmt;
	int		len;

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
