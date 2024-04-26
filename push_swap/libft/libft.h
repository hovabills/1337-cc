/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:22:20 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:22:21 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

int		ft_isdigit(char ch);
int		ft_isdigit_str(char *str);
int		check_minmax_int(char *str);
int		ft_atoi(char *str);
long	ft_atol(char *str);
char	**ft_split_rev(char *str, char ch);
void	free_double(char **str);

#endif