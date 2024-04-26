/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:20:20 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:30:24 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bot = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*node_new(int val)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->val = val;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	stack_dump(t_stack *stack)
{
	t_node	*node;
	size_t	size;

	node = stack->top;
	size = stack->size;
	while (size)
	{
		printf("val: %d | next->val: %d | prev val: %d \n", node->val,
			node->next->val, node->prev->val);
		node = node->prev;
		size--;
	}
	printf("\n\n");
}

void	stack_free(t_stack *stack)
{
	t_node	*node;
	size_t	size;

	node = stack->top;
	size = stack->size;
	while (size)
	{
		stack->top = node->prev;
		free(node);
		node = stack->top;
		size--;
	}
	free(stack);
}
