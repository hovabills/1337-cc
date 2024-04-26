/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:21:11 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:36:39 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_low_pos(t_stack *stack)
{
	t_node	*node;
	size_t	size;
	int		low_val;
	size_t	low_pos;

	size = stack->size;
	node = stack->top;
	low_val = node->val;
	low_pos = size;
	while (size)
	{
		if (node->val < low_val)
		{
			low_val = node->val;
			low_pos = size;
		}
		size--;
		node = node->prev;
	}
	return (low_pos);
}

size_t	find_hight_pos(t_stack *stack)
{
	t_node	*node;
	size_t	size;
	int		hight_val;
	size_t	hight_pos;

	size = stack->size;
	node = stack->top;
	hight_val = node->val;
	hight_pos = size;
	while (size)
	{
		if (node->val > hight_val)
		{
			hight_val = node->val;
			hight_pos = size;
		}
		size--;
		node = node->prev;
	}
	return (hight_pos);
}

size_t	find_dst_pos(t_stack *dst, int node_val)
{
	t_node	*node_dst;
	size_t	size;
	int		low_val;
	size_t	low_pos;

	size = dst->size;
	node_dst = dst->top;
	low_val = node_dst->val;
	low_pos = size;
	while (size)
	{
		if ((node_val < node_dst->val) && (node_val > node_dst->next->val))
			return (size);
		if (node_dst->val < low_val)
		{
			low_val = node_dst->val;
			low_pos = size;
		}
		size--;
		node_dst = node_dst->prev;
	}
	return (low_pos);
}

size_t	find_dst_pos_2(t_stack *dst, int node_val)
{
	t_node	*node_dst;
	size_t	size;

	size = dst->size;
	node_dst = dst->top;
	while (size)
	{
		if ((node_val > node_dst->val) && (node_val < node_dst->next->val))
			return (size);
		size--;
		node_dst = node_dst->prev;
	}
	return (find_hight_pos(dst));
}
