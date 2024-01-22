NAME = libftprintf.a
INC = inc
SRC = src
CC = cc
CFLAGS = -Wall -Wextra -Werror
ADD_SAN = -fsanitize=address
AR = ar rcs

# CHANGE TO EXPLICIT SRCS
INCS := $(wildcard $(INC)/*.h)  
SRCS := $(wildcard $(SRC)/*.c)
OBJS := $(SRCS:.c=.o)

%.o: %.c $(INCS)
	$(CC) -c -o $@ $< $(CFLAGS) -I $(INC)


$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

test: main.o $(NAME)
	$(CC) -o $@ $^ $(CFLAGS) $(ADD_SAN)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)



