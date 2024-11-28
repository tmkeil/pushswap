CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
CHECKER = checker
INCLUDES = -Iheaders
OBJSDIR = objs/
SRCSDIR = srcs/
LIBFTDIR = libft/
LIBFT = libft/libft.a

SRCS = push_swap.c validations.c termination.c pivots.c operations.c operate_both.c \
		nbr_utils.c lst_utils.c lst_utils2.c longsort.c longsort_utils.c align.c

CHECKER_SRCS = checker.c validations.c termination.c operations.c operate_both.c nbr_utils.c lst_utils.c lst_utils2.c


SRCS_PATHS = $(addprefix $(SRCSDIR), $(SRCS))
CHECKER_PATHS = $(addprefix $(SRCSDIR), $(CHECKER_SRCS))

OBJS = $(addprefix $(OBJSDIR), $(SRCS:.c=.o))
OBJS_CHECKER = $(addprefix $(OBJSDIR), $(CHECKER_SRCS:.c=.o))

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) -o $@

$(CHECKER): $(LIBFT) $(OBJS_CHECKER)
	$(CC) $(CFLAGS) $(OBJS_CHECKER) $(LIBFT) $(INCLUDES) -o $@

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	rm -rf $(OBJSDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -rf $(NAME) $(CHECKER)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus

.SILENT:
