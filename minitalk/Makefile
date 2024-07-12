NAME = minitalk
BONUS = bonus 
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = client.c server.c utils.c
BONUS_SRCS = client_bonus.c server_bonus.c utils.c

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

OBJS := $(SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) -o client client.o utils.o $(CFLAGS)
	$(CC) -o server server.o utils.o $(CFLAGS)

$(BONUS): $(BONUS_OBJS)
	$(CC) -o client_bonus client_bonus.o utils.o $(CFLAGS)
	$(CC) -o server_bonus server_bonus.o utils.o $(CFLAGS)

all : $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

