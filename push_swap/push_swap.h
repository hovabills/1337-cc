/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouiyeh <adouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:19:50 by adouiyeh          #+#    #+#             */
/*   Updated: 2024/04/26 06:28:04 by adouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define SA 100
# define SB 101
# define SS 102

# define PA 200
# define PB 201

# define RA 300
# define RB 301
# define RR 302

# define RRA 400
# define RRB 401
# define RRR 402

typedef struct s_task
{
	int				code;
	struct s_task	*next;
}					t_task;

typedef struct s_queue
{
	t_task			*head;
	t_task			*tail;
	size_t			size;
}					t_queue;

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bot;
	size_t			size;
}					t_stack;

t_stack				*stack_init(void);
t_node				*node_new(int val);
void				stack_push_node(t_stack *stack, t_node *node);
int					stack_copy(t_stack *stack, char **av, int ac);
int					stack_check_sorted(t_stack *stack);
int					stack_check_double(t_stack *stack);
void				stack_dump(t_stack *stack);
t_node				*stack_pop_node(t_stack *stack);
void				stack_push(t_stack *dst, t_stack *src);
void				stack_rotate(t_stack *stack);
void				stack_rot_low(t_stack *stack);
void				stack_reverse_rotate(t_stack *stack);
void				stack_swap(t_stack *stack);
void				stack_free(t_stack *stack);
void				stack_sort(t_stack *stack);
void				stack_3_sort(t_stack *stack_a);
void				stack_big_sort(t_stack *stack_a, t_stack *stack_b);
size_t				find_low_pos(t_stack *stack);
size_t				find_hight_pos(t_stack *stack);
size_t				find_dst_pos(t_stack *dst, int node_val);
size_t				find_dst_pos_2(t_stack *dst, int node_val);

t_queue				*get_node_queue_ab(int node_val, size_t node_pos,
						size_t src_size, t_stack *dst);
t_queue				*get_node_queue_ba(int node_val, size_t node_pos,
						size_t src_size, t_stack *dst);
t_queue				*find_cheapest_queue_ab(t_stack *dst, t_stack *src);
t_queue				*find_cheapest_queue_ba(t_stack *dst, t_stack *src);

t_queue				*queue_init(void);
t_task				*task_new(int code);
void				queue_task(t_queue *queue, int code);
void				queue_double_task(t_queue *queue, int c1, int c2);
void				queue_task_opt(t_queue *queue, int code);
void				queue_n_task(t_queue *queue, size_t n, int code);
void				queue_free(t_queue *queue);

void				queue_rot_top_a(t_queue *queue, size_t node_pos,
						size_t size);
void				queue_rot_top_b(t_queue *queue, size_t node_pos,
						size_t size);
void				queue_rot_dst_b(t_queue *queue, int node_val, t_stack *dst);
void				queue_rot_dst_a(t_queue *queue, int node_val, t_stack *dst);

void				queue_exe(t_queue *queue, t_stack *stack_a,
						t_stack *stack_b);
void				task_exe(t_task *task, t_stack *stack_a, t_stack *stack_b);
void				task_write_code(int code);
void				task_sa(t_stack *stack_a);
void				task_sb(t_stack *stack_b);
void				task_ss(t_stack *stack_a, t_stack *stack_b);
void				task_pa(t_stack *stack_a, t_stack *stack_b);
void				task_pb(t_stack *stack_a, t_stack *stack_b);
void				task_ra(t_stack *stack_a);
void				task_rb(t_stack *stack_b);
void				task_rr(t_stack *stack_a, t_stack *stack_b);
void				task_rra(t_stack *stack_a);
void				task_rrb(t_stack *stack_b);
void				task_rrr(t_stack *stack_a, t_stack *stack_b);

#endif
