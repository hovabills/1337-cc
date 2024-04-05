/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:36:59 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/03/13 01:37:00 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define BASE_10 "0123456789"
# define BASE_16 "0123456789abcdef"
# define BASE_16_UP "0123456789ABCDEF"

int		ft_isdigit(char ch);
int		ft_putchar(char ch);
int		ft_putstr(char *str);
int		ft_putnstr(char *str, int n);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
size_t	ft_nbrbase_len(unsigned long long nbr, size_t blen);
char	*ft_itoa_base(unsigned long long nbr, char *base, int base_len);
#endif
