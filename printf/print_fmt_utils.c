/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:33:00 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/03/13 02:08:25 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

void	print_padd(t_fmt *fmt)
{
	int	i;

	i = 0;
	while (i++ < fmt->padd_len)
		fmt->n_print += ft_putchar(fmt->padd_ch);
}

void	print_prec_s(t_fmt *fmt, char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (fmt->prec_len >= 6 || !fmt->prec)
			fmt->n_print += ft_putstr("(null)");
		return ;
	}
	if (fmt->prec)
	{
		while (str[i] && i < fmt->prec_len)
			fmt->n_print += ft_putchar(str[i++]);
		return ;
	}
	fmt->n_print += ft_putstr(str);
}

void	print_prec(t_fmt *fmt)
{
	int	i;

	i = 0;
	while (i++ < fmt->prec_len)
		fmt->n_print += ft_putchar('0');
}

void	print_sign(t_fmt *fmt)
{
	if (fmt->sign)
		fmt->n_print += ft_putchar(fmt->sign);
}

void	print_alt_fmt(t_fmt *fmt, int upper)
{
	if (fmt->alt_fmt && upper)
		fmt->n_print += write(1, "0X", 2);
	else if (fmt->alt_fmt)
		fmt->n_print += write(1, "0x", 2);
}
