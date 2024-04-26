/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:21:35 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:34:03 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_task	*task_new(int code)
{
	t_task	*task;

	task = (t_task *)malloc(sizeof(t_task));
	if (!task)
		return (NULL);
	task->code = code;
	task->next = NULL;
	return (task);
}

void	task_exe(t_task *task, t_stack *stack_a, t_stack *stack_b)
{
	if (task->code == SA)
		task_sa(stack_a);
	else if (task->code == SB)
		task_sb(stack_b);
	else if (task->code == SS)
		task_ss(stack_a, stack_b);
	else if (task->code == PA)
		task_pa(stack_a, stack_b);
	else if (task->code == PB)
		task_pb(stack_a, stack_b);
	else if (task->code == RA)
		task_ra(stack_a);
	else if (task->code == RB)
		task_rb(stack_b);
	else if (task->code == RR)
		task_rr(stack_a, stack_b);
	else if (task->code == RRA)
		task_rra(stack_a);
	else if (task->code == RRB)
		task_rrb(stack_b);
	else if (task->code == RRR)
		task_rrr(stack_a, stack_b);
}

void	task_write_code(int code)
{
	if (code == SA)
		write(1, "sa\n", 3);
	else if (code == SB)
		write(1, "sb\n", 3);
	else if (code == SS)
		write(1, "ss\n", 3);
	else if (code == PA)
		write(1, "pa\n", 3);
	else if (code == PB)
		write(1, "pb\n", 3);
	else if (code == RA)
		write(1, "ra\n", 3);
	else if (code == RB)
		write(1, "rb\n", 3);
	else if (code == RR)
		write(1, "rr\n", 3);
	else if (code == RRA)
		write(1, "rra\n", 4);
	else if (code == RRB)
		write(1, "rrb\n", 4);
	else if (code == RRR)
		write(1, "rrr\n", 4);
}
