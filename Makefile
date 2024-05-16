NAME = client
NAME1 = server
BNAME = client_bonus
BNAME1 = server_bonus
HEADER = minitalk.h
BHEADER = minitalk_bonus.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = client \
		server \

BFILES = client_bonus \
		 server_bonus \

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addsuffix .o, $(FILES))

BSRCS = $(addsuffix .c, $(FILES))

BOBJ = $(addsuffix .o, $(BFILES))


all: $(NAME) $(NAME1)

bonus: $(BNAME) $(BNAME1)

$(NAME): client.o
	$(CC) $(CFLAGS) $^ -o $@

$(NAME1): server.o
	$(CC) $(CFLAGS) $^ -o $@

$(BNAME): client_bonus.o
	$(CC) $(CFLAGS) $^ -o $@

$(BNAME1): server_bonus.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADER) $(BHEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(BOBJ)

fclean: clean
	$(RM) $(NAME) $(NAME1) 
	$(RM) $(BNAME) $(BNAME1)

re: fclean all

.PHONY: clean