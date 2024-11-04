CC = cc

# CFLAGS = -Wall -Wextra -Werror

all: test

test:
	$(CC) $(CFLAGS) *.c libft/*.c

fill:
	$(CC) $(CFLAGS) fill/fill.c libft/*.c
	./a.out

fclean:
	rm -f a.out libft/a.out

.PHONY: fill all test fclean

.SILENT:
