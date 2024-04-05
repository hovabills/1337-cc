#include "stack.h"

int main()
{

    int vals[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    t_stack *stack_a = stack_init('a');
    stack_copy(stack_a, vals, 10);
    stack_dump(stack_a);
    stack_rotate(stack_a);
    stack_dump(stack_a);
    stack_rrotate(stack_a);
    stack_dump(stack_a);
    stack_free(stack_a);
}