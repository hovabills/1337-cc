/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:31:54 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/03/13 02:12:59 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

void	handle_fmt_s(t_fmt *fmt, char *str)
{
	int	slen;

	fmt->padd_ch = ' ';
	slen = ft_strlen(str);
	if (!slen && fmt->prec_len >= 6)
		fmt->padd_len -= 6;
	else if (slen && fmt->prec && fmt->prec_len < slen)
		fmt->padd_len -= fmt->prec_len;
	else
		fmt->padd_len -= slen;
}

char	*handle_fmt_d(t_fmt *fmt, long nbr)
{
	int		slen;
	char	*str;

	if (nbr < 0)
	{
		fmt->sign = '-';
		nbr *= -1;
	}
	str = ft_itoa_base(nbr, BASE_10, 10);
	slen = ft_strlen(str);
	if (fmt->sign)
		fmt->padd_len--;
	if (fmt->ladj || fmt->prec)
		fmt->padd_ch = ' ';
	if (!nbr && fmt->prec && fmt->prec_len == 0)
	{
		*str = '\0';
		return (str);
	}
	fmt->padd_len -= slen;
	fmt->prec_len -= slen;
	if (fmt->prec && fmt->prec_len > 0)
		fmt->padd_len -= fmt->prec_len;
	return (str);
}

char	*handle_fmt_u(t_fmt *fmt, unsigned int nbr)
{
	int		slen;
	char	*str;

	str = ft_itoa_base(nbr, BASE_10, 10);
	slen = ft_strlen(str);
	if (fmt->ladj || fmt->prec)
		fmt->padd_ch = ' ';
	if (!nbr && fmt->prec && fmt->prec_len == 0)
	{
		*str = '\0';
		return (str);
	}
	fmt->padd_len -= slen;
	fmt->prec_len -= slen;
	if (fmt->prec && fmt->prec_len > 0)
		fmt->padd_len -= fmt->prec_len;
	return (str);
}

char	*handle_fmt_x(t_fmt *fmt, unsigned int nbr, int upper)
{
	int		slen;
	char	*str;

	if (upper)
		str = ft_itoa_base(nbr, BASE_16_UP, 16);
	else
		str = ft_itoa_base(nbr, BASE_16, 16);
	slen = ft_strlen(str);
	if (!nbr)
	{
		fmt->alt_fmt = 0;
		if (fmt->prec && fmt->prec_len == 0)
		{
			*str = '\0';
			return (str);
		}
	}
	fmt->padd_len -= slen;
	fmt->prec_len -= slen;
	if (fmt->prec && fmt->prec_len > 0)
		fmt->padd_len -= fmt->prec_len;
	if (fmt->alt_fmt)
		fmt->padd_len -= 2;
	return (str);
}

char	*handle_fmt_p(t_fmt *fmt, unsigned long long nbr)
{
	int		slen;
	char	*str;

	if (!nbr)
	{
		fmt->padd_len -= 5;
		fmt->alt_fmt = 0;
		return (ft_strdup("(nil)"));
	}
	str = ft_itoa_base(nbr, BASE_16, 16);
	slen = ft_strlen(str);
	fmt->padd_len -= slen + 2;
	fmt->alt_fmt = 1;
	return (str);
}
