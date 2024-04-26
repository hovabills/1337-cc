/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_task.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:53:56 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:55:43 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	queue_task(t_queue *queue, int code)
{
	t_task	*task;

	task = task_new(code);
	if (queue->tail)
	{
		queue->tail->next = task;
		queue->tail = task;
	}
	else
	{
		queue->head = task;
		queue->tail = task;
	}
	queue->size++;
}

void	queue_double_task(t_queue *queue, int c1, int c2)
{
	queue_task(queue, c1);
	queue_task(queue, c2);
}

void	queue_task_opt(t_queue *queue, int code)
{
	t_task	*task;

	task = queue->head;
	while (task)
	{
		if ((task->code == RA && code == RB) || (task->code == RB
				&& code == RA))
		{
			task->code = RR;
			return ;
		}
		else if ((task->code == RRA && code == RRB) || (task->code == RRB
				&& code == RRA))
		{
			task->code = RRR;
			return ;
		}
		task = task->next;
	}
	queue_task(queue, code);
}

void	queue_n_task(t_queue *queue, size_t n, int code)
{
	while (n--)
		queue_task_opt(queue, code);
}
