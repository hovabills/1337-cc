#include "stack.h"

void sa(t_stack *stack_a)
{
    stack_swap(stack_a);
    write(1, "sa", 2);
}
void sb(t_stack *stack_b)
{
    stack_swap(stack_b);
    write(1, "sb", 2);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    stack_swap(stack_a);
    stack_swap(stack_b);
    write(1, "ss", 2);
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
    stack_push(stack_a, stack_b);
    write(1, "pa", 2);
}

void pb(t_stack *stack_b, t_stack *stack_a)
{
    stack_push(stack_b, stack_a);
    write(1, "pb", 2);
}
