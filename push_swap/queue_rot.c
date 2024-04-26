/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:19:59 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:29:35 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	queue_rot_top_a(t_queue *queue, size_t node_pos, size_t size)
{
	if (node_pos == size)
		return ;
	else if (node_pos >= size / 2)
		queue_n_task(queue, size - node_pos, RA);
	else if (node_pos < size / 2)
		queue_n_task(queue, node_pos, RRA);
}

void	queue_rot_top_b(t_queue *queue, size_t node_pos, size_t size)
{
	if (node_pos == size)
		return ;
	else if (node_pos >= size / 2)
		queue_n_task(queue, size - node_pos, RB);
	else if (node_pos < size / 2)
		queue_n_task(queue, node_pos, RRB);
	else if (node_pos == size / 2)
	{
		if (queue->head && queue->head->code == RA)
			queue_n_task(queue, size - node_pos, RB);
		else
			queue_n_task(queue, node_pos, RRB);
	}
}

void	queue_rot_dst_b(t_queue *queue, int node_val, t_stack *dst)
{
	size_t	dst_pos;

	dst_pos = find_dst_pos_2(dst, node_val);
	queue_rot_top_b(queue, dst_pos, dst->size);
}

void	queue_rot_dst_a(t_queue *queue, int node_val, t_stack *dst)
{
	size_t	dst_pos;

	dst_pos = find_dst_pos(dst, node_val);
	queue_rot_top_a(queue, dst_pos, dst->size);
}

void	stack_rot_low(t_stack *stack)
{
	t_queue	*queue;
	size_t	pos;

	queue = queue_init();
	if (!queue)
		return ;
	pos = find_low_pos(stack);
	queue_rot_top_a(queue, pos, stack->size);
	queue_exe(queue, stack, stack);
	queue_free(queue);
}
