/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:19:56 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:31:17 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_queue	*get_node_queue_ab(int node_val, size_t node_pos, size_t src_size,
		t_stack *dst)
{
	t_queue	*queue;

	queue = queue_init();
	queue_rot_top_a(queue, node_pos, src_size);
	queue_rot_dst_b(queue, node_val, dst);
	queue_task(queue, PB);
	return (queue);
}

t_queue	*get_node_queue_ba(int node_val, size_t node_pos, size_t src_size,
		t_stack *dst)
{
	t_queue	*queue;

	queue = queue_init();
	queue_rot_top_b(queue, node_pos, src_size);
	queue_rot_dst_a(queue, node_val, dst);
	queue_task(queue, PA);
	return (queue);
}

t_queue	*find_cheapest_queue_ab(t_stack *dst, t_stack *src)
{
	t_queue	*cheapest_queue;
	t_queue	*tmp;
	t_node	*node;
	size_t	size;

	cheapest_queue = NULL;
	size = src->size;
	node = src->top;
	while (size)
	{
		tmp = get_node_queue_ab(node->val, size, src->size, dst);
		if (!cheapest_queue)
			cheapest_queue = tmp;
		else if (cheapest_queue->size > tmp->size)
		{
			queue_free(cheapest_queue);
			cheapest_queue = tmp;
		}
		else
			queue_free(tmp);
		node = node->prev;
		size--;
	}
	return (cheapest_queue);
}

t_queue	*find_cheapest_queue_ba(t_stack *dst, t_stack *src)
{
	t_queue	*cheapest_queue;
	t_queue	*tmp;
	t_node	*node;
	size_t	size;

	cheapest_queue = NULL;
	size = src->size;
	node = src->top;
	while (size)
	{
		tmp = get_node_queue_ba(node->val, size, src->size, dst);
		if (!cheapest_queue)
			cheapest_queue = tmp;
		else if (cheapest_queue->size > tmp->size)
		{
			queue_free(cheapest_queue);
			cheapest_queue = tmp;
		}
		else
			queue_free(tmp);
		node = node->prev;
		size--;
	}
	return (cheapest_queue);
}
