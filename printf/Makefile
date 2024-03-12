NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ADD_SAN = -fsanitize=address
AR = ar rcs
LIBFT_DIR = libft
LIBFT = libft.a

# CHANGE TO EXPLICIT SRCS
INCS := $(wildcard *.h)  
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

%.o: %.c $(INCS)
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
	$(MAKE) rm -f -C $(LIBFT_DIR)
	rm -f $(NAME)
