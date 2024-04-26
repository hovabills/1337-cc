/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:20:37 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:33:49 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_copy(t_stack *stack, char **av, int ac)
{
	char	**args;
	char	**head;
	t_node	*node;

	if (!stack)
		return (0);
	while (--ac)
	{
		args = ft_split_rev(av[ac], ' ');
		head = args;
		while (*args)
		{
			if (!ft_isdigit_str(*args) || check_minmax_int(*args))
				return (free_double(head), 0);
			node = node_new(ft_atoi(*args));
			stack_push_node(stack, node);
			args++;
		}
		free_double(head);
	}
	return (1);
}

int	stack_check_double(t_stack *stack)
{
	t_node	*current;
	t_node	*node;
	size_t	size;
	size_t	pos;

	current = stack->top;
	size = stack->size;
	pos = size;
	while (size)
	{
		node = stack->bot;
		pos = --size;
		while (pos)
		{
			if (current->val == node->val)
				return (1);
			node = node->next;
			pos--;
		}
		current = current->prev;
	}
	return (0);
}

int	stack_check_sorted(t_stack *stack)
{
	t_node	*node;
	size_t	size;

	node = stack->top;
	size = stack->size;
	if (!size)
		return (1);
	while (--size)
	{
		if (node->val > node->prev->val)
			return (0);
		node = node->prev;
	}
	return (1);
}

t_node	*stack_pop_node(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (stack->size > 1)
	{
		stack->top = stack->top->prev;
		stack->bot->prev = stack->top;
		stack->top->next = stack->bot;
		stack->size--;
	}
	else if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bot = NULL;
		stack->size--;
	}
	return (node);
}

void	stack_push_node(t_stack *stack, t_node *node)
{
	if (stack->top)
	{
		node->prev = stack->top;
		node->next = stack->bot;
		stack->top->next = node;
		stack->bot->prev = node;
		stack->top = node;
	}
	else
	{
		node->prev = node;
		node->next = node;
		stack->top = node;
		stack->bot = node;
	}
	stack->size++;
}
