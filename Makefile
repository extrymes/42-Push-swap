NAME = push_swap

SRCS = 	push_swap.c parsing.c checkers.c utils.c

OBJS = $(SRCS:.c=.o)

HDR_DIR = includes

LIBFT_DIR = libft
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/,$(LIBFT_FILE))

CFLAGS = -Wall -Wextra -Werror
CC = cc $(CFLAGS) -g -I $(HDR_DIR)

GRAY = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m

%.o: %.c
	@$(CC) -c $< -o $@
	@echo "$(GRAY)Compiled: $<$(RESET)"

all: $(NAME)

$(LIBFT):
	@echo "$(YELLOW)Building libft..$(RESET)"
	@make --no-print-directory -C $(LIBFT_DIR)
	@echo "$(GREEN)Library $(LIBFT_FILE) successfully built!$(RESET)"

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -o $(NAME) $^
	@echo "$(GREEN)Executable $(NAME) successfully created!$(RESET)"

clean:
	@echo "$(BLUE)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Cleaning complete!$(RESET)"

fclean: clean
	@echo "$(BLUE)Complete cleanup, delete $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Cleaning complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re