CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRCS = $(wildcard *.c libft/*.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cp $< $(NAME)
	$(CC) $(OBJS) -o $@
	make clean

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY: all clean fclean

.SILENT:
