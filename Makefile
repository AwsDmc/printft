NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
AR          = ar rcs

# Directories
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

# Source Files (add your other files here as needed)
SRCS        = ft_printf.c \
              ft_print_chars.c \
              ft_print_nbrs.c \
              ft_print_hex.c

OBJS        = $(SRCS:.c=.o)

# Default Rule
all: $(NAME)

# Compile libft first, then build libftprintf.a
$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

# Rule to dive into libft folder and run its Makefile
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean object files for both printf and libft
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

# Clean objects and the compiled libraries
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

# Recompile everything from scratch
re: fclean all

.PHONY: all clean fclean re
