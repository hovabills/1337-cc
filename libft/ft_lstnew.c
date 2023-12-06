/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:26:25 by adouiyeh          #+#    #+#             */
/*   Updated: 2023/12/06 03:50:55 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tlst;

	tlst = (t_list *)malloc((sizeof(t_list))) if (!tlst) return (NULL);
	tlst->content = content;
	tlst->next = NULL;
	return (tlst);
}
