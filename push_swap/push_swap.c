/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:19:41 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:35:12 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac == 1)
		return (0);
	stack_a = stack_init();
	if (stack_copy(stack_a, av, ac) && stack_a->size)
	{
		if (!stack_check_double(stack_a))
			stack_sort(stack_a);
		else
			write(2, "Error\n", 6);
	}
	else
		write(2, "Error\n", 6);
	stack_free(stack_a);
	return (0);
}
