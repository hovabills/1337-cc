NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
FSAN = -g
BONUS = checker

LIBFT_SRCS = libft/check_minmax_int.c \
			 libft/ft_atoi.c \
			 libft/ft_atol.c \
			 libft/ft_isdigit_str.c \
			 libft/ft_isdigit.c \
			 libft/ft_split_rev.c \

SRCS =	queue_get.c \
		queue_rot.c \
		queue_task.c \
		queue.c \
		stack_action.c \
		stack_find.c \
		stack_sort.c \
		stack_utils.c \
		stack.c \
		task_r.c \
		task_rr.c \
		task_sp.c \
		task.c \

BONUS_SRCS = checker_bonus/checker.c \
			 checker_bonus/get_next_line.c \
			 checker_bonus/get_next_line_utils.c \

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
OBJS := $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) 

$(NAME): push_swap.o $(OBJS) $(LIBFT_OBJS) 
	$(CC) -o $@ $^ $(CFLAGS)

bonus: $(LIBFT_OBJS) $(OBJS) $(BONUS_OBJS)
	$(CC) -o $(BONUS) $^ $(CFLAGS) -g

all : $(NAME)

clean:
	rm -f push_swap.o $(OBJS) $(LIBFT_OBJS) $(BONUS_OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all
