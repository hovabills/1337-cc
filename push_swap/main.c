#include "stack.h"

int main()
{

    int vals[10] = {6, 8, -1};
    t_stack *stack_a = stack_init('a');
    stack_copy(stack_a, vals, 10);
    stack_dump(stack_a);
    stack_sort(stack_a);
    stack_dump(stack_a);
    stack_free(stack_a);
}