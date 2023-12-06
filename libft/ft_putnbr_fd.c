/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:28:05 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/06 03:13:47 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	char	ch;

	ln = n;
	if (ln < 0)
	{
		ln *= -1;
		write(fd, "-", 1);
	}
	if (ln / 10)
		ft_putnbr_fd(ln / 10, fd);
	ch = (ln % 10) + '0';
	write(fd, &ch, 1);
	return ;
}
