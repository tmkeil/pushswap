CC = cc

CFLAGS = -Wall -Wextra -Werror

all: test

test:
	$(CC) $(CFLAGS) *.c libft/*.c


fclean:
	rm -f a.out libft/a.out