/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:21:31 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:33:22 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	task_sa(t_stack *stack_a)
{
	stack_swap(stack_a);
}

void	task_sb(t_stack *stack_b)
{
	stack_swap(stack_b);
}

void	task_ss(t_stack *stack_a, t_stack *stack_b)
{
	stack_swap(stack_a);
	stack_swap(stack_b);
}

void	task_pa(t_stack *stack_a, t_stack *stack_b)
{
	stack_push(stack_a, stack_b);
}

void	task_pb(t_stack *stack_a, t_stack *stack_b)
{
	stack_push(stack_b, stack_a);
}
