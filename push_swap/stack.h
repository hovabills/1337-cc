#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
    int val;
    struct s_node *prev;
} t_node;

typedef struct s_stack
{
    t_node *top;
    char name;
    size_t size;
} t_stack;

t_stack *stack_init(char name);
void stack_copy(t_stack *stack, int *vals, size_t len);
void stack_push_val(t_stack *stack, int val);
void stack_push(t_stack *dst, t_stack *src);
void stack_swap(t_stack *stack);
void stack_rotate(t_stack *stack);
void stack_rrotate(t_stack *stack);
void stack_push_node(t_stack *stack, t_node *node);
void stack_rpush_node(t_stack *stack, t_node *node);
t_node *stack_pop_node(t_stack *stack);
t_node *stack_rpop_node(t_stack *stack);
void stack_dump(t_stack *stack);
void stack_free(t_stack *stack);
