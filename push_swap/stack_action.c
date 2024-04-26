/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:20:55 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:37:55 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *dst, t_stack *src)
{
	t_node	*node;

	node = stack_pop_node(src);
	if (!node)
		return ;
	stack_push_node(dst, node);
}

void	stack_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->bot = stack->top;
	stack->top = stack->top->prev;
}

void	stack_reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->top = stack->bot;
	stack->bot = stack->bot->next;
}

void	stack_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->val;
	stack->top->val = stack->top->prev->val;
	stack->top->prev->val = tmp;
}
