NAME = minitalk
BONUS = bonus 
CC = cc
CFLAGS = -Wall -Wextra -Werror


SRCS = client.c server.c
BONUS_SRCS = client_bonus.c server_bonus.c



%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

OBJS := $(SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) -o client client.o $(CFLAGS)
	$(CC) -o server server.o $(CFLAGS)

$(BONUS): $(BONUS_OBJS)
	$(CC) -o client_bonus client_bonus.o $(CFLAGS)
	$(CC) -o server_bonus server_bonus.o $(CFLAGS)

all : $(NAME)

