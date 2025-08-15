NAME = fractol

# Source files (all .c files in src directory)
SRC_DIR = src
SRC = events.c init.c main.c math_utils.c render.c string_utils.c

# Object files (in obj directory)
OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -fsanitize=leak -g

# Libft configuration
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

#minilibx config
MINILIB_X = minilibx/
mini

# Include directories
INCLUDES = -I. -Iincludes -I$(LIBFT_DIR) -I

# Headers (for dependencies)
HEADERS = includes/fractol.h

# Default target
all: $(NAME)

# Build libft first
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Build the main executable (placed in root directory)
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "remember to remove the wild card in this makefile later"

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

# Clean everything
fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
