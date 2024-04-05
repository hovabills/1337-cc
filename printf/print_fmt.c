/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:32:45 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/03/13 02:12:11 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

void	print_fmt_d(t_fmt *fmt, int n)
{
	char	*str;

	str = handle_fmt_d(fmt, n);
	print_sign(fmt);
	if (!fmt->ladj)
		print_padd(fmt);
	print_prec(fmt);
	fmt->n_print += ft_putstr(str);
	if (fmt->ladj)
		print_padd(fmt);
	fmt->n_parse++;
	free(str);
}

void	print_fmt_u(t_fmt *fmt, int n)
{
	char	*str;

	str = handle_fmt_u(fmt, n);
	if (!fmt->ladj)
		print_padd(fmt);
	print_prec(fmt);
	fmt->n_print += ft_putstr(str);
	if (fmt->ladj)
		print_padd(fmt);
	fmt->n_parse++;
	free(str);
}

void	print_fmt_x(t_fmt *fmt, unsigned int n, int upper)
{
	char	*str;

	str = handle_fmt_x(fmt, n, upper);
	if (!fmt->ladj)
		print_padd(fmt);
	print_alt_fmt(fmt, upper);
	print_prec(fmt);
	fmt->n_print += ft_putstr(str);
	if (fmt->ladj)
		print_padd(fmt);
	fmt->n_parse++;
	free(str);
}

void	print_fmt_p(t_fmt *fmt, unsigned long long n)
{
	char	*str;

	str = handle_fmt_p(fmt, n);
	if (!fmt->ladj)
		print_padd(fmt);
	print_alt_fmt(fmt, 0);
	fmt->n_print += ft_putstr(str);
	if (fmt->ladj)
		print_padd(fmt);
	fmt->n_parse++;
	free(str);
}
