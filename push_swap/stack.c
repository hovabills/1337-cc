#include "stack.h"
#include "actions.h"

t_stack *stack_init(char name)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->name = name;
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

void stack_push_val(t_stack *stack, int val)
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	new->val = val;
	new->prev = stack->top;
	stack->top = new;
	stack->size++;
}

void stack_dump(t_stack *stack)
{
	printf("\n\nStack %c size: %ld\n", stack->name, stack->size);
	t_node *node = stack->top;
	while (node)
	{
		printf("+---------------+\n");
		printf("|	%d	|\n", node->val);
		printf("+---------------+\n");
		node = node->prev;
	}
}

void stack_copy(t_stack *stack, int *vals, size_t len)
{
	while (len)
		stack_push_val(stack, vals[--len]);
}

void stack_free(t_stack *stack)
{
	t_node *tmp;

	while (stack->top)
	{
		tmp = stack->top;
		stack->top = tmp->prev;
		free(tmp);
	}
	free(stack);
}
void stack_swap(t_stack *stack)
{
	int val;

	if (stack->size < 2)
		return;
	val = stack->top->val;
	stack->top->val = stack->top->prev->val;
	stack->top->prev->val = val;
}

t_node *stack_pop_node(t_stack *stack)
{
	t_node *node;

	if (!stack->top)
		return (NULL);
	node = stack->top;
	stack->top = node->prev;
	stack->size--;
	node->prev = NULL;
	return (node);
}

t_node *stack_rpop_node(t_stack *stack)
{
	t_node *tmp;
	t_node *last;

	tmp = stack->top;
	if (!tmp)
		return NULL;
	stack->size--;
	if (stack->size == 1)
	{
		tmp = stack->top;
		stack->top = NULL;
		return tmp;
	}
	while (tmp->prev)
	{
		if (!tmp->prev->prev)
			break;
		tmp = tmp->prev;
	}
	last = tmp->prev;
	tmp->prev = NULL;
	return (last);
}

void stack_push_node(t_stack *stack, t_node *node)
{
	node->prev = stack->top;
	stack->top = node;
	stack->size++;
}
void stack_rpush_node(t_stack *stack, t_node *node)
{
	t_node *tmp;

	tmp = stack->top;
	if (!tmp)
		return;
	while (tmp->prev)
		tmp = tmp->prev;
	tmp->prev = node;
	stack->size++;
}

void stack_push(t_stack *dst, t_stack *src)
{
	t_node *node;
	node = stack_pop_node(src);
	if (!node)
		return;
	stack_push_node(dst, node);
}

void stack_rotate(t_stack *stack)
{
	t_node *node;

	node = stack_pop_node(stack);
	if (!node)
		return;
	stack_rpush_node(stack, node);
}

void stack_rrotate(t_stack *stack)
{
	t_node *node;

	node = stack_rpop_node(stack);
	if (!node)
		return;
	stack_push_node(stack, node);
}
void stack_sort(t_stack *stack)
{
	if (stack->size == 1)
		return;
	if (stack->size == 3)
	{
		stack_sort_3(stack);
		return;
	}
}

void stack_sort_3(t_stack *stack)
{
	t_node *top;
	t_node *midd;
	t_node *bott;

	top = stack->top;
	midd = top->prev;
	bott = midd->prev;
	if (top->val > midd->val && top->val < bott->val && midd->val < bott->val)
		sa(stack);
	else if (top->val > midd->val && top->val > bott->val && midd->val > bott->val)
	{
		sa(stack);
		rra(stack);
	}
	else if (top->val > midd->val && top->val > bott->val && midd->val < bott->val)
		ra(stack);
	else if (top->val < midd->val && top->val < bott->val && midd->val > bott->val)
	{
		sa(stack);
		ra(stack);
	}
	else if (top->val < midd->val && top->val > bott->val && midd->val > bott->val)
		rra(stack);
}
