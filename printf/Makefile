NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ADD_SAN = -fsanitize=address
AR = ar rcs
LIBFT_DIR = libft
LIBFT = libft.a

HDRS =	fmt.h \
		ft_printf.h

SRCS =	parse_fmt.c \
		handle_fmt.c \
		print_fmt.c \
		print_fmt_utils.c \
		ft_printf.c

OBJS := $(SRCS:.c=.o)

%.o: %.c $(HDRS)
	$(CC) -c -o $@ $< $(CFLAGS) 

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	$(AR) $@ $^

all: $(NAME)

bonus: $(NAME)

test: main.o $(NAME)
	$(CC) -o $@ $^ $(CFLAGS) $(ADD_SAN)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)
	
fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: test clean fclean re all bonus
