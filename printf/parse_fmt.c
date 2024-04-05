/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:32:25 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/03/13 02:00:04 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

t_fmt	*init_fmt(void)
{
	t_fmt	*fmt;

	fmt = (t_fmt *)malloc(sizeof(t_fmt));
	if (!fmt)
		return (NULL);
	fmt->sign = 0;
	fmt->ladj = 0;
	fmt->alt_fmt = 0;
	fmt->padd_ch = ' ';
	fmt->padd_len = 0;
	fmt->prec = 0;
	fmt->prec_len = 0;
	fmt->n_parse = 0;
	fmt->n_print = 0;
	return (fmt);
}

void	parse_hmps(t_fmt *fmt, char *str)
{
	while (1)
	{
		if (*str == '#')
			fmt->alt_fmt = 1;
		else if (*str == '-')
			fmt->ladj = 1;
		else if (*str == '+')
			fmt->sign = '+';
		else if (*str == ' ')
		{
			if (!fmt->sign)
				fmt->sign = ' ';
		}
		else
			break ;
		fmt->n_parse += 1;
		str++;
	}
	return ;
}

void	parse_padd(t_fmt *fmt, char *str)
{
	str += fmt->n_parse;
	if (*str == '0')
	{
		fmt->padd_ch = '0';
		fmt->n_parse++;
		str++;
	}
	while ((ft_isdigit(*str)))
	{
		fmt->padd_len = fmt->padd_len * 10 + (*str - '0');
		fmt->n_parse++;
		str++;
	}
	return ;
}

void	parse_prec(t_fmt *fmt, char *str)
{
	str += fmt->n_parse;
	if (*str == '.')
	{
		fmt->prec = 1;
		fmt->n_parse++;
		str++;
		while ((ft_isdigit(*str)))
		{
			fmt->prec_len = fmt->prec_len * 10 + (*str - '0');
			fmt->n_parse++;
			str++;
		}
	}
}

t_fmt	*parse_fmt(char *str)
{
	t_fmt	*fmt;

	fmt = init_fmt();
	parse_hmps(fmt, str);
	parse_padd(fmt, str);
	parse_prec(fmt, str);
	return (fmt);
}
