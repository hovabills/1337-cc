#include "stack.h"
#include "actions.h"
int main()
{

    // 3,2,1
    // 2,1,3
    // 2,3,1
    // 1,2,3
    int vals[3] = {1, 2, 3};
    t_stack *stack_a = stack_init('a');
    stack_copy(stack_a, vals, 3);
    stack_dump(stack_a);
    stack_sort(stack_a);
    stack_dump(stack_a);
    stack_free(stack_a);
}