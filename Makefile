NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
AR          = ar rcs

# Just list your printf files here
SRCS        = ft_printf.c \
              ft_print_chars.c \
              ft_print_nbrs.c \
              ft_print_hex.c

OBJS        = $(SRCS:.c=.o)

# Default Rule
all: $(NAME)

# Creates the static library directly from your objects
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Cleans object files
clean:
	$(RM) $(OBJS)

# Cleans objects and the compiled library
fclean: clean
	$(RM) $(NAME)

# Recompiles everything from scratch
re: fclean all

.PHONY: all clean fclean re
