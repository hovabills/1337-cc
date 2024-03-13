NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

HDRS =	libft.h
FILES =	ft_isdigit \
		ft_putchar \
		ft_putstr \
		ft_putnstr \
		ft_strdup \
		ft_strlen \
		ft_itoa_base \
		ft_nbrbase_len

SRCS := $(addsuffix .c, $(FILES)) 
OBJS := $(addsuffix .o, $(FILES)) 

%.o: %.c HDRS 
	$(CC) -c -o $@ $< $(CFLAGS) 

$(NAME): $(OBJS)
	$(AR) $(NAME) $^

all: $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: clean fclean all


