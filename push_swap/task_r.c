/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:52:55 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:56:23 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	task_ra(t_stack *stack_a)
{
	stack_rotate(stack_a);
}

void	task_rb(t_stack *stack_b)
{
	stack_rotate(stack_b);
}

void	task_rr(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate(stack_a);
	stack_rotate(stack_b);
}
