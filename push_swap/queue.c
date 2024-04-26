/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:20:04 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:53:39 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_queue	*queue_init(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->head = NULL;
	queue->tail = NULL;
	queue->size = 0;
	return (queue);
}

void	queue_free(t_queue *queue)
{
	t_task	*task;
	t_task	*tmp;

	if (!queue)
		return ;
	task = queue->head;
	while (task)
	{
		tmp = task->next;
		free(task);
		task = tmp;
	}
	free(queue);
}

void	queue_exe(t_queue *queue, t_stack *stack_a, t_stack *stack_b)
{
	t_task	*task;

	task = queue->head;
	while (task)
	{
		task_exe(task, stack_a, stack_b);
		task_write_code(task->code);
		task = task->next;
	}
}
