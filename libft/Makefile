# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCSDIR = srcs/
BONUSDIR = bonus/
OBJSDIR = objs/
INCLUDES = -I../headers

# MANDATORY files
MANDATORY_SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
				ft_toupper.c

# BONUS files
BONUS_SRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
				ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

SRCS_MANDATORY_PATHS = $(addprefix $(SRCSDIR), $(MANDATORY_SRCS))
SRCS_BONUS_PATHS = $(addprefix $(BONUSDIR), $(BONUS_SRCS))

MANDATORY_OBJS = $(addprefix $(OBJSDIR), $(MANDATORY_SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJSDIR), $(BONUS_SRCS:.c=.o))

# Library name
NAME = libft.a

# Default
all: $(NAME)

# Rule to create the library
$(NAME): $(MANDATORY_OBJS)
		ar -rcs $@ $^

# Rule to compile mandatory .c files to .o files
$(OBJSDIR)%.o: $(SRCSDIR)%.c
		mkdir -p $(OBJSDIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to compile bonus .c files to .o files
$(OBJSDIR)%.o: $(BONUSDIR)%.c
		mkdir -p $(OBJSDIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to create the bonus library
bonus: $(BONUS_OBJS) $(MANDATORY_OBJS)
		ar -rcs $(NAME) $(BONUS_OBJS) $(MANDATORY_OBJS)

# Rule to clean up object files
clean:
		rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

# Rule to clean up object files and the library
fclean: clean
		rm -f $(NAME)

# Rule to fclean and redo all
re: fclean all

# Phony targets to avoid conflicts with files of the same name
.PHONY: all clean fclean re bonus
