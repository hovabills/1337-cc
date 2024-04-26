/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:21:48 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:51:04 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	str_to_code(char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		return (100);
	if (!ft_strcmp(str, "sb\n"))
		return (101);
	if (!ft_strcmp(str, "ss\n"))
		return (102);
	if (!ft_strcmp(str, "pa\n"))
		return (200);
	if (!ft_strcmp(str, "pb\n"))
		return (201);
	if (!ft_strcmp(str, "ra\n"))
		return (300);
	if (!ft_strcmp(str, "rb\n"))
		return (301);
	if (!ft_strcmp(str, "rr\n"))
		return (302);
	if (!ft_strcmp(str, "rra\n"))
		return (400);
	if (!ft_strcmp(str, "rrb\n"))
		return (401);
	if (!ft_strcmp(str, "rrr\n"))
		return (402);
	return (0);
}

t_queue	*queue_stdin(void)
{
	t_queue	*queue;
	char	*task;
	int		code;

	queue = queue_init();
	if (!queue)
		return (NULL);
	task = get_next_line(0);
	while (task)
	{
		code = str_to_code(task);
		if (!code)
		{
			write(1, "Error\n", 6);
			free(task);
			queue_free(queue);
			return (NULL);
		}
		queue_task(queue, code);
		free(task);
		task = get_next_line(0);
	}
	return (queue);
}

void	queue_exe_quiet(t_queue *queue, t_stack *stack_a, t_stack *stack_b)
{
	t_task	*task;

	task = queue->head;
	while (task)
	{
		task_exe(task, stack_a, stack_b);
		task = task->next;
	}
	if (stack_check_sorted(stack_a) && !stack_b->size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_queue	*queue;

	if (ac == 1)
		return (0);
	stack_a = stack_init();
	stack_b = stack_init();
	if (stack_copy(stack_a, av, ac) && !stack_check_double(stack_a)
		&& stack_a->size)
	{
		queue = queue_stdin();
		if (queue)
		{
			queue_exe_quiet(queue, stack_a, stack_b);
			queue_free(queue);
		}
	}
	else
		write(1, "Error\n", 6);
	stack_free(stack_a);
	stack_free(stack_b);
}
