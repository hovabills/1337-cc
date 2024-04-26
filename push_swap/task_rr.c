/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:21:18 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:53:02 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	task_rra(t_stack *stack_a)
{
	stack_reverse_rotate(stack_a);
}

void	task_rrb(t_stack *stack_b)
{
	stack_reverse_rotate(stack_b);
}

void	task_rrr(t_stack *stack_a, t_stack *stack_b)
{
	stack_reverse_rotate(stack_a);
	stack_reverse_rotate(stack_b);
}
