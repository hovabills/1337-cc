/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:20:42 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:37:35 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_3_sort(t_stack *stack)
{
	t_node	*top;
	t_node	*mid;
	t_node	*bot;
	t_queue	*queue;

	top = stack->top;
	mid = top->prev;
	bot = mid->prev;
	queue = queue_init();
	if (!queue)
		return ;
	if (top->val > mid->val && top->val > bot->val && mid->val > bot->val)
		queue_double_task(queue, SA, RRA);
	else if (top->val > mid->val && top->val > bot->val && mid->val < bot->val)
		queue_task(queue, RA);
	else if (top->val > mid->val && top->val < bot->val && mid->val < bot->val)
		queue_task(queue, SA);
	else if (top->val < mid->val && top->val > bot->val && mid->val > bot->val)
		queue_task(queue, RRA);
	else if (top->val < mid->val && top->val < bot->val && mid->val > bot->val)
		queue_double_task(queue, SA, RA);
	queue_exe(queue, stack, NULL);
	queue_free(queue);
}

void	stack_big_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_queue	*queue;

	queue = queue_init();
	if (!queue)
		return ;
	queue_double_task(queue, PB, PB);
	queue_exe(queue, stack_a, stack_b);
	queue_free(queue);
	while (stack_a->size > 3)
	{
		queue = find_cheapest_queue_ab(stack_b, stack_a);
		queue_exe(queue, stack_a, stack_b);
		queue_free(queue);
	}
	stack_3_sort(stack_a);
	while (stack_b->top)
	{
		queue = queue_init();
		queue_rot_dst_a(queue, stack_b->top->val, stack_a);
		queue_task(queue, PA);
		queue_exe(queue, stack_a, stack_b);
		queue_free(queue);
	}
	stack_rot_low(stack_a);
}

void	stack_sort(t_stack *stack_a)
{
	t_stack	*stack_b;

	if (stack_check_sorted(stack_a))
		return ;
	if (stack_a->size == 2 && stack_a->top->val > stack_a->bot->val)
	{
		task_sa(stack_a);
		write(1, "sa\n", 3);
	}
	else if (stack_a->size == 3)
		stack_3_sort(stack_a);
	else if (stack_a->size > 3)
	{
		stack_b = stack_init();
		if (!stack_b)
			return ;
		stack_big_sort(stack_a, stack_b);
		stack_free(stack_b);
	}
}
