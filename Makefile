NAME = client
NAME1 = server
HEADER = minitalk.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = client \
		server \

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addsuffix .o, $(FILES))

all: $(NAME) $(NAME1)

$(NAME): client.o
	$(CC) $(CFLAGS) $^ -o $@

$(NAME1): server.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME) $(NAME1)

re: fclean all

.PHONY: clean